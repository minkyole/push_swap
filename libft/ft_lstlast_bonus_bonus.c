/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:54:03 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 19:59:48 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == (void *)0)
		return (lst);
	temp = lst;
	while (temp->next != (void *)0)
	{
		temp = temp->next;
	}
	return (temp);
}
