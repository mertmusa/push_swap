/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:29 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/25 14:05:58 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* swap operation for sa and/or sb */
void	swap_list(t_list **mmtlist)
{
	t_list	*new_first;
	t_list	*new_second;

	new_second = *mmtlist;
	new_first = (*mmtlist)->next;
	new_second->next = (*mmtlist)->next->next;
	new_first->next = new_second;
	*mmtlist = new_first;
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(t_list **a)
{
	if (!(*a) || ft_lstsize(*a) < 2)
		return ;
	swap_list(a);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	sb(t_list **b)
{
	if (!(*b) || ft_lstsize(*b) < 2)
		return ;
	swap_list(b);
}

/* ss : sa and sb at the same time. */
void	ss(t_list **a, t_list **b)
{
	swap_list(a);
	swap_list(b);
}
