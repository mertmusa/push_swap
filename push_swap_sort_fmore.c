/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_fmore.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:32 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 16:01:40 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* where is the max value
in the second list */
int	search_max(t_list **mmtlist2, int element_cnt)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *mmtlist2;
	while (temp)
	{
		if (temp->sequence == element_cnt)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

/* sort second list
after all firts list's elements pushed second list
a -> b (a empty, b full) */
void	sort_second_list(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata)
{
	int	element_cnt;
	int	mid;
	int	place;

	element_cnt = mydata->max_sequence;
	while (*mmtlist2)
	{
		mid = (element_cnt + 1) / 2;
		place = search_max (mmtlist2, element_cnt);
		if ((*mmtlist2)->sequence == element_cnt)
		{
			pa(mmtlist1, mmtlist2);
			element_cnt--;
		}
		else if (place <= mid && (*mmtlist2)->sequence != element_cnt)
			rb(mmtlist2);
		else if (place > mid && (*mmtlist2)->sequence != element_cnt)
			rrb(mmtlist2);
	}
}

/* sort for more than 5 elements
5 < ft_lstsize */
void	sort_for_more(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata)
{
	int	i;

	i = 0;
	while (*mmtlist1)
	{
		if ((*mmtlist1)->sequence <= i && i > 1)
		{
			pb(mmtlist1, mmtlist2);
			rb(mmtlist2);
			i++;
		}
		else if ((*mmtlist1)->sequence <= (i + mydata->clustering_size))
		{
			pb(mmtlist1, mmtlist2);
			i++;
		}
		else if ((*mmtlist1)->sequence >= i)
			ra(mmtlist1);
	}
	sort_second_list(mmtlist1, mmtlist2, mydata);
}
