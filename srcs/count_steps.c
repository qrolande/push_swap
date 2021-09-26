/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:08:44 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/10 22:58:48 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_steps_a(t_swap *start)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	j = 0;
	res = ft_lstsize(start->a);
	start->temp = start->a;
	while (j < res / 2 + res % 2)
	{
		start->temp->steps = ++i;
		j++;
		start->temp->flag = 1;
		start->temp = start->temp->next;
	}
	if (res % 2 == 0)
		i++;
	while (start->temp)
	{
		start->temp->steps = i--;
		start->temp->flag = 0;
		start->temp = start->temp->next;
	}
}

void	count_steps(t_swap *start)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	j = 0;
	count_steps_a(start);
	res = ft_lstsize(start->b);
	start->temp = start->b;
	while (j < res / 2 + res % 2)
	{
		start->temp->steps = ++i;
		j++;
		start->temp->flag = 1;
		start->temp = start->temp->next;
	}
	if (res % 2 == 0)
		i++;
	while (start->temp)
	{
		start->temp->steps = i--;
		start->temp->flag = 0;
		start->temp = start->temp->next;
	}
}
