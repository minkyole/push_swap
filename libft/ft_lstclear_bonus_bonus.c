/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:35:22 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 20:46:11 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (*lst == (void *)0)
		return ;
	while (temp != (void *)0)
	{
		del (temp->content);
		*lst = temp->next;
		free (temp);
		temp = *lst;
	}
	lst = (void *)0;
}
