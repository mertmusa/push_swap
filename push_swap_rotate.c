/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:30:44 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 15:32:43 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* first element becomes last */
void	rotate_list(t_list	**mmtlist)
{
	t_list	*new_first;
	t_list	*new_last;

	new_last = *mmtlist;
	*mmtlist = (*mmtlist)->next;
	new_first = *mmtlist;
	while (new_first->next)
		new_first = new_first->next;
	new_first->next = new_last;
	new_first->next->next = NULL;
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	ra(t_list **a)
{
	rotate_list(a);
	ft_printf("ra\n");
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rb(t_list **b)
{
	rotate_list(b);
	ft_printf("rb\n");
}

/* rr : ra and rb at the same time. */
void	rr(t_list **a, t_list **b)
{
	rotate_list(a);
	rotate_list(b);
	ft_printf("rr\n");
}
