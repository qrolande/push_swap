/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:10:12 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 19:38:59 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_swap *start, int i)
{
	sa(start, 0);
	sb(start, 0);
	if (i)
		write(1, "ss\n", 3);
}

void	rr(t_swap *start, int i)
{
	ra(start, 0);
	rb(start, 0);
	if (i)
		write(1, "rr\n", 3);
}

void	rrr(t_swap *start, int i)
{
	rra(start, 0);
	rrb(start, 0);
	if (i)
		write(1, "rrr\n", 4);
}
