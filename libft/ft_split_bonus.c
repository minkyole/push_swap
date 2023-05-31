/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:56:21 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/23 18:17:44 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static void	all_free(char **cut_str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(cut_str[j]);
		j++;
	}
	free(cut_str);
}

static int	word_cut(char c, char *str, int *word_size, int i)
{
	int	flag;

	flag = 0;
	while (str[i])
	{
		if (c == str[i] && flag == 1)
			return (i);
		flag = 1;
		*word_size = *word_size + 1;
		i++;
	}
	return (i);
}

static int	add_word(char **cut_str, int word, char c, char *str)
{
	int	i;
	int	k;
	int	j;
	int	word_size;
	int	start;

	i = -1;
	j = 0;
	while (++i < word)
	{
		k = -1;
		word_size = 0;
		while (str[j] == c)
			j++;
		start = j;
		j = word_cut(c, str, &word_size, j);
		cut_str[i] = (char *)malloc(sizeof(char) * (word_size + 1));
		if (cut_str[i] == 0)
			return (i);
		while (++k < word_size)
			cut_str[i][k] = str[start++];
		cut_str[i][k] = '\0';
	}
	return (-1);
}

static int	word_count(char c, char *str, int flag, int count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**cut_str;
	int		i;

	i = 0;
	word = word_count(c, (char *)s, 1, 0);
	cut_str = (char **)malloc(sizeof(char *) * (word + 1));
	if (cut_str == 0)
		return (0);
	cut_str[word] = 0;
	if (word == 0)
		return (cut_str);
	i = add_word(cut_str, word, c, (char *)s);
	if (i != -1)
	{
		all_free(cut_str, i);
		return (0);
	}
	return (cut_str);
}
