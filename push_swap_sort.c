/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:53:42 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 15:58:52 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort for three elements */
void	sort_three(t_list **mmtlist)
{
	int	a;
	int	b;
	int	c;

	a = (*mmtlist)->content;
	b = (*mmtlist)->next->content;
	c = (*mmtlist)->next->next->content;
	if (a > b && a > c && c > b)
		ra(mmtlist);
	else if (b > a && b > c && c > a)
	{
		rra(mmtlist);
		sa(mmtlist);
	}
	else if (b > a && b > c && a > c)
		rra(mmtlist);
	else if (a > b && a > c && b > c)
	{
		sa(mmtlist);
		rra(mmtlist);
	}
	else if (c > a && c > b && a > b)
		sa(mmtlist);
}

/* sort for four or five elements
3 < ft_lstsize <= 5 */
void	sort_five(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata)
{
	while (ft_lstsize(*mmtlist1) != 3)
	{
		if ((*mmtlist1)->sequence == 0)
			pb(mmtlist1, mmtlist2);
		else if ((*mmtlist1)->sequence == 1 && mydata->max_sequence == 4)
			pb(mmtlist1, mmtlist2);
		else
			ra(mmtlist1);
	}
	sort_three(mmtlist1);
	while (ft_lstsize(*mmtlist2) != 0)
	{
		if ((*mmtlist2)->sequence == 1 && mydata->max_sequence == 4)
			pa(mmtlist1, mmtlist2);
		else if ((*mmtlist2)->sequence == 0 && mydata->max_sequence == 4)
		{
			rb(mmtlist2);
			pa(mmtlist1, mmtlist2);
		}
		if (ft_lstsize(*mmtlist2))
			pa(mmtlist1, mmtlist2);
	}
}

/* will sort according to this function
	- in the beginning a is filled, b is empty */
void	find_list_size_and_sort(t_list **a, t_list **b, t_data *mydata)
{
	int	mylistsize;

	mylistsize = ft_lstsize(*a);
	if (mylistsize < 2)
		exit(EXIT_SUCCESS);
	else if (mylistsize == 2)
		sa(a);
	else if (mylistsize == 3)
		sort_three(a);
	else if (mylistsize <= 5)
		sort_five(a, b, mydata);
	else if (mylistsize <= 100)
	{
		mydata->clustering_size = 14;
		sort_for_more(a, b, mydata);
	}
	else
	{
		mydata->clustering_size = 32;
		sort_for_more(a, b, mydata);
	}
}
