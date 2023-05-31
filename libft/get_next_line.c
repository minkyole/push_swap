/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:48:23 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/17 19:32:30 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_add(char *buff, char *parr, int buff_size, int parr_size)
{
	char	*new_arr;
	int		size;

	size = parr_size + buff_size;
	new_arr = (char *)malloc(sizeof(char) * size + 1);
	if (new_arr == NULL)
		return (NULL);
	if (parr == NULL)
	{
		ft_strcpy(new_arr, buff);
		return (new_arr);
	}
	ft_strcpy(new_arr, parr);
	ft_strcpy(&new_arr[parr_size], buff);
	free (parr);
	return (new_arr);
}

int	arr_read_return_test(t_gnl *member, char **parr)
{
	char	*temp_arr;

	if (member->read_size == -1)
		return (0);
	else if (check_count(*parr, &member->end, 2))
	{
		member->return_arr = malloc(member->end + 2);
		if (member->return_arr == 0)
			return (0);
		ft_memcpy(member->return_arr, *parr,
			member->end + 1);
		temp_arr = malloc(1);
		if (temp_arr == 0)
		{
			free (member->return_arr);
			return (0);
		}
		temp_arr[0] = '\0';
		free (*parr);
		*parr = temp_arr;
		return (1);
	}
	return (0);
}

int	arr_read_test(t_gnl *member, char **parr)
{
	char	*temp_arr;

	if (check_count(*parr, &member->end, 1))
	{
		member->return_arr = malloc(member->end + 2);
		if (member->return_arr == 0)
			return (0);
		ft_memcpy(member->return_arr, *parr, \
				member->end + 1);
		temp_arr = malloc(member->parr_size - member->end);
		if (temp_arr == 0)
		{
			free (member->return_arr);
			return (0);
		}
		ft_strcpy(temp_arr, &((*parr)[member->end + 1]));
		free (*parr);
		*parr = temp_arr;
		return (1);
	}
	return (2);
}

char	*get_next_line2(char **parr, t_gnl member, int fd)
{
	int			temp;
	char		*arr;

	temp = 0;
	while (1)
	{
		member.read_size = read(fd, member.buff, BUFFER_SIZE);
		if (member.read_size < 1)
		{
			temp = arr_read_return_test(&member, parr);
			break ;
		}
		member.buff[member.read_size] = '\0';
		arr = str_add(member.buff, *parr, member.read_size, member.parr_size);
		if (arr == NULL)
			break ;
		*parr = arr;
		member.parr_size += member.read_size;
		temp = arr_read_test(&member, parr);
		if (temp == 1 || temp == 0)
			break ;
	}
	if (temp == 1)
		return (member.return_arr);
	return (static_reset(parr));
}

char	*get_next_line(int fd)
{
	static char	*parr;
	char		*temp_arr;
	t_gnl		member;

	member.parr_size = ft_strlen2(parr);
	member.read_size = 0;
	if (check_count(parr, &member.end, 1))
	{
		member.return_arr = malloc(member.end + 2);
		if (member.return_arr == 0)
			return (static_reset(&parr));
		ft_memcpy(member.return_arr, parr, member.end + 1);
		temp_arr = malloc(member.parr_size - member.end);
		if (temp_arr == 0)
		{
			free (member.return_arr);
			return (static_reset(&parr));
		}
		ft_strcpy(temp_arr, &parr[member.end + 1]);
		free (parr);
		parr = temp_arr;
		return (member.return_arr);
	}
	return (get_next_line2(&parr, member, fd));
}
