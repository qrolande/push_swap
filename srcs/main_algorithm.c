/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:50:47 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 20:56:50 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	cooking_value(t_swap *start, t_list *temp2, int index, int flag)
{
	start->init.temp_steps = start->init.temp_steps + start->temp->steps;
	if (start->temp->flag == temp2->flag)
	{
		if (start->temp->steps > temp2->steps)
			start->init.temp_steps -= temp2->steps;
		else
			start->init.temp_steps -= start->temp->steps;
	}
	if (start->init.first_step > start->init.temp_steps
		|| start->init.first_step == -1)
	{
		start->init.first_step = start->init.temp_steps;
		start->init.first_ind = index;
		start->init.flag = flag;
	}
}

static int	search(t_swap *start, int index)
{
	int	i;

	i = 1;
	while (start->temp)
	{
		if (start->temp->index == index + i)
		{
			start->temp = start->b;
			i++;
		}
		else if (start->temp->index != index + i)
		{
			if (start->temp->next == NULL)
				break ;
			else
				start->temp = start->temp->next;
		}
	}
	return (i);
}

static void	cooking(t_swap *start)
{
	int		index;
	int		flag;
	int		res;
	t_list	*temp2;

	start->init.first_ind = 0;
	start->init.first_step = -1;
	start->temp = start->b;
	temp2 = start->b;
	while (start->temp)
	{
		start->init.temp_steps = start->temp->steps;
		index = start->temp->index;
		flag = start->temp->flag;
		start->temp = start->b;
		res = search(start, index);
		temp2->nextindex = index + res;
		start->temp = start->a;
		while (index + res != start->temp->index)
			start->temp = start->temp->next;
		cooking_value(start, temp2, index, flag);
		temp2 = temp2->next;
		start->temp = temp2;
	}
}

static void	first_step(t_swap *start)
{
	int	len;
	int	list_len;

	len = ft_lstsize(start->a);
	list_len = len;
	start->temp = start->a;
	while (list_len > 3)
	{
		if (start->temp->index != len - 1 && start->temp->index != len - 2
			&& start->temp->index != len - 3)
		{
			pb(start, 1);
			start->temp = start->a;
			list_len--;
		}
		else
		{
			ra(start, 1);
			start->temp = start->a;
		}
	}
}

void	main_algorithm(t_swap *start)
{
	int	len;

	first_step(start);
	algorithm_under_three(start);
	len = ft_lstsize(start->b);
	while (len)
	{
		count_steps(start);
		cooking(start);
		swap_stacks(start);
		start->temp = start->b;
		while (start->temp->index != start->init.first_ind)
		{
			if (start->init.flag == 1)
				rb(start, 1);
			else
				rrb(start, 1);
			start->temp = start->b;
		}
		start->temp = start->b;
		push_to_a(start);
		pa(start, 1);
		len--;
	}
}
