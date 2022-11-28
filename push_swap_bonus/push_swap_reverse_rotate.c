/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:33:29 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/25 12:51:38 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* last element becomes first */
void	reverse_rotate_list(t_list **mmtlist)
{
	t_list	*front;
	t_list	*back;
	t_list	*head;

	front = *mmtlist;
	back = *mmtlist;
	head = *mmtlist;
	if (*mmtlist == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*mmtlist = front;
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(t_list **a)
{
	if (!(*a))
		return ;
	reverse_rotate_list(a);
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	rrb(t_list **b)
{
	if (!(*b))
		return ;
	reverse_rotate_list(b);
}

/* rrr : rra and rrb at the same time. */
void	rrr(t_list **a, t_list **b)
{
	reverse_rotate_list(a);
	reverse_rotate_list(b);
}
