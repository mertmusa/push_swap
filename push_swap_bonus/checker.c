/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:54:54 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/25 14:48:02 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* this function checks if list sorted then return int value */
int	checksorted_int(t_list **a)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *a;
	if (!temp)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->sequence > i)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

/* check if each rule is true
function exists due to norminette*/
void	ft_checker_rules_2(t_list **list_a, t_list **list_b, char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(list_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(list_a, list_b);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(list_a, list_b);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(list_a, list_b);
	else
	{
		free (s);
		print_error("Wrong operation");
	}
}

/* check if each rule is true */
void	ft_checker_rules(t_list **list_a, t_list **list_b, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		sa(list_a);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		sb(list_b);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		ss(list_a, list_b);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(list_a);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(list_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(list_a, list_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(list_a);
	else
		ft_checker_rules_2(list_a, list_b, s);
	free (s);
}

/* bonus checker */
void	ft_checker(t_list **list_a, t_list **list_b, t_data *mydata)
{
	int		i;
	char	*line;

	i = ft_lstsize(*list_a);
	line = get_next_line(0);
	while (line)
	{
		ft_checker_rules(list_a, list_b, line);
		line = get_next_line(0);
	}
	ft_printf("line: %d\n", __LINE__);
	if (checksorted_int(list_a) && ft_lstsize(*list_a) \
			== i && ft_lstsize(*list_b) == 0)
	{
		ft_printf("line: %d\n", __LINE__);
		free_list(list_a, list_b, mydata);
		print_error("OK");
	}
	else
	{
		ft_printf("line: %d\n", __LINE__);
		free_list(list_a, list_b, mydata);
		print_error("KO");
	}
}
