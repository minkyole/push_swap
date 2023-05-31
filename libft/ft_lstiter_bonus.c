/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:54:05 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 20:56:12 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst == (void *)0)
		return ;
	temp = lst;
	while (temp->next != (void *)0)
	{
		f(temp->content);
		temp = temp->next;
	}
	f(temp->content);
}
