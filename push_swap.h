/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:48:38 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 13:51:20 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_data{
	int	max_sequence;
	int	clustering_size;
}	t_data;

typedef struct s_list{
	int				content;
	int				sequence;
	struct s_list	*next;
}	t_list;

void	print_error(char *str);
int		is_arg_number(char *str);
int		is_arg_int_range(char *str);
void	check_my_arg(char **argv);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	args_to_list(char **args);
void	find_sequence(t_list	*a, t_data *mydata);
void	checksorted(t_list **a);
void	find_list_size_and_sort(t_list **a, t_list **b, t_data *mydata);
void	sort_three(t_list **mmtlist);
void	sort_five(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata);
void	sort_for_more(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata);
void	sort_second_list(t_list **mmtlist1, t_list **mmtlist2, t_data *mydata);
int		search_max(t_list **mmtlist2, int element_cnt);
void	free_list(t_list **a, t_list **b, t_data *mydata);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif
