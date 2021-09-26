/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:13:08 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/14 13:37:13 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	algorithm_for_three(t_swap *start)
{
	if (start->a->content < start->a->next->next->content
		&& start->a->next->content > start->a->next->next->content)
	{
		sa(start, 1);
		ra(start, 1);
	}
	if (start->a->content < start->a->next->content
		&& start->a->content > start->a->next->next->content)
		rra(start, 1);
	if (start->a->content > start->a->next->content
		&& start->a->content < start->a->next->next->content)
		sa(start, 1);
	if (start->a->content > start->a->next->next->content
		&& start->a->next->next->content > start->a->next->content)
		ra(start, 1);
	if (start->a->content > start->a->next->content
		&& start->a->next->content > start->a->next->next->content)
	{
		sa(start, 1);
		rra(start, 1);
	}
}

void	algorithm_under_three(t_swap *start)
{
	if (ft_lstsize(start->a) == 2)
	{
		if (start->a->content > start->a->next->content)
			sa(start, 1);
	}
	else if (ft_lstsize(start->a) == 3)
		algorithm_for_three(start);
}
