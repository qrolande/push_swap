/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_do_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:01:49 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/15 19:05:42 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

static void	just_do_it_for_len(t_swap *start, char *line, int len)
{
	if (ft_strnstr(line, "rra", len))
		rra(start, 0);
	else if (ft_strnstr(line, "rrb", len))
		rrb(start, 0);
	else if (ft_strnstr(line, "rrr", len))
		rrr(start, 0);
}

void	just_do_it(t_swap *start, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len == 2)
	{
		if (ft_strnstr(line, "sa", len))
			sa(start, 0);
		else if (ft_strnstr(line, "sb", len))
			sb(start, 0);
		else if (ft_strnstr(line, "ra", len))
			ra(start, 0);
		else if (ft_strnstr(line, "rb", len))
			rb(start, 0);
		else if (ft_strnstr(line, "pa", len))
			pa(start, 0);
		else if (ft_strnstr(line, "pb", len))
			pb(start, 0);
		else if (ft_strnstr(line, "rr", len))
			rr(start, 0);
		else if (ft_strnstr(line, "ss", len))
			ss(start, 0);
	}
	else
		just_do_it_for_len(start, line, len);
}
