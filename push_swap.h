/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:46:48 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/15 16:26:21 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				steps;
	int				flag;
	int				first_ind;
	int				first_step;
	int				temp_steps;
	int				nextindex;
	struct s_list	*next;
}					t_list;

typedef struct s_swap
{
	t_list			*a;
	t_list			*b;
	t_list			*temp;
	t_list			*rotate;
	t_list			init;
}					t_swap;

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
int			ft_atoi(char *str);
int			ft_lstsize(t_list *lst);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);

void		indexation(t_swap *start);
void		main_algorithm(t_swap *start);
void		algorithm_under_three(t_swap *start);
void		count_steps(t_swap *start);
void		lets_begin(t_swap *start, int ac, char **av);
void		push_to_a(t_swap *start);
void		swap_stacks(t_swap *start);
void		final_sort(t_swap *start);
void		cleaning_company(t_swap *start);

void		sa(t_swap *start, int i);
void		ra(t_swap *start, int i);
void		pa(t_swap *start, int i);
void		rra(t_swap *start, int i);

void		sb(t_swap *start, int i);
void		rb(t_swap *start, int i);
void		pb(t_swap *start, int i);
void		rrb(t_swap *start, int i);

void		ss(t_swap *start, int i);
void		rr(t_swap *start, int i);
void		rrr(t_swap *start, int i);

#endif