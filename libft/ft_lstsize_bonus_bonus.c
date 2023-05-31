/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:37:53 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 19:57:48 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != (void *)0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
