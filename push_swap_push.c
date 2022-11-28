/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:28:40 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 15:29:58 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* be careful this function push first parameter to second */
void	push_list(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

/* pa (push a): Take the first element
at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	pa(t_list **a, t_list **b)
{
	if (!(*b))
		return ;
	push_list(b, a);
	ft_printf("pa\n");
}

/* pb (push b): Take the first element
at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	pb(t_list **a, t_list **b)
{
	if (!(*a))
		return ;
	push_list(a, b);
	ft_printf("pb\n");
}
