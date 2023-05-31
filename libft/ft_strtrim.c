/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:16:14 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/19 15:05:17 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_set_test(char word, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (word == set[i])
			return (0);
		i++;
	}
	return (1);
}

static int	trim_size(char *parr, char *set, int *min, int *max)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (parr[i])
	{
		if (count == 1 && str_set_test(parr[i], (char *)set))
		{
			*min = i;
			*max = i;
			count = 2;
		}
		else if (count != 1 && str_set_test(parr[i], (char *)set))
			*max = i;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	char	*parr;
	int		i;
	int		count;

	min = 0;
	i = 0;
	parr = (char *)s1;
	count = trim_size(parr, (char *)set, &min, &max);
	if (count == 1)
		return (ft_strdup(""));
	parr = malloc(sizeof(char) * (max + count - min));
	if (parr == 0)
		return ((void *)0);
	parr[max + count - min - 1] = 0;
	i = 0;
	while (min <= max)
	{
		parr[i] = s1[min];
		i++;
		min++;
	}
	return (parr);
}
