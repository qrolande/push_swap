/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:48:24 by qrolande          #+#    #+#             */
/*   Updated: 2021/10/10 12:52:30 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialization(t_swap *start)
{
	start->a = NULL;
	start->b = NULL;
	start->temp = NULL;
	start->rotate = NULL;
}

static void	if_sorted(t_swap *start)
{
	start->temp = start->a;
	if (start->temp->index == 0)
	{
		while (start->temp->next != NULL)
		{
			if (start->temp->index + 1 == start->temp->next->index)
				start->temp = start->temp->next;
			else
				return ;
		}
		ft_lstclear(&start->a);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_swap	start;
	int		len;

	initialization(&start);
	lets_begin(&start, ac, av);
	if (ft_lstsize(start.a) <= 3)
		algorithm_under_three(&start);
	len = ft_lstsize(start.a);
	if (len > 3)
	{
		indexation(&start);
		start.temp = start.a;
		if_sorted(&start);
		main_algorithm(&start);
		final_sort(&start);
	}
	ft_lstclear(&start.a);
	return (0);
}
