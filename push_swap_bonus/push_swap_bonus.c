/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:04:36 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/25 13:41:50 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* print "Error" to STDERR output */
void	print_error(char *str)
{
	char	*s;

	s = str;
	if (s[0] == 'O' && s[1] == 'K' && ft_strlen(s) == 2)
		write(2, "OK\n", 3);
	else if (s[0] == 'K' && s[1] == 'O' && ft_strlen(s) == 2)
		write(2, "KO\n", 3);
	else
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* by order of the peaky fookin blinders */
void	find_sequence(t_list *a, t_data *mydata)
{
	t_list	*temp1;
	t_list	*temp2;

	mydata->max_sequence = ft_lstsize(a) - 1;
	if (!a)
		return ;
	temp1 = a;
	while (temp1)
	{
		temp2 = a;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				temp1->sequence++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	temp1 = a;
}

/* free all the list */
void	free_list(t_list **a, t_list **b, t_data *mydata)
{
	int		i;
	int		sza;
	int		szb;

	sza = ft_lstsize(*a);
	szb = ft_lstsize(*b);
	i = 0;
	while (i < sza)
	{
		free(*a);
		*a = (*a)->next;
		i++;
	}
	i = 0;
	while (i < szb)
	{
		free(*b);
		*b = (*b)->next;
		i++;
	}
	free (mydata);
}

/* argument to list */
void	args_to_list(char **arg)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	t_data	*mydata;
	int		i;

	mydata = (t_data *)malloc(sizeof(t_data));
	i = 0;
	b = NULL;
	a = ft_lstnew(ft_atoi(arg[0]));
	while (arg[++i])
	{
		temp = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(&a, temp);
	}
	find_sequence(a, mydata);
	ft_checker(&a, &b, mydata);
	checksorted(&a);
	find_list_size_and_sort(&a, &b, mydata);
	free_list(&a, &b, mydata);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	i = 0;
	if (argc < 2)
		print_error("Arguments are less than two!");
	else if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			print_error("Empty argument!");
		args = ft_split(argv[1], ' ');
	}
	else
	{
		args = (char **)malloc(sizeof(char *) * (argc));
		while (++i < argc)
			args[i - 1] = ft_strdup(argv[i]);
		args[i - 1] = NULL;
	}
	check_my_arg(args);
	args_to_list(args);
}
