/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:45:00 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/15 19:08:06 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
}					t_swap;

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

void		lets_begin(t_swap *start, int ac, char **av);
void		just_do_it(t_swap *start, char *line);
void		search(t_swap *start, char *line);
void		cleaning_company(t_swap *start);
void		indexation(t_swap *start);
void		ko_out(t_swap *swap);

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**ft_split(char const *s, char c);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
int			ft_atoi(char *str);
int			ft_lstsize(t_list *lst);
int			get_next_line(char **line);

#endif