/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:12:33 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 19:38:26 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_swap *start, int i)
{
	if (start->a == NULL || start->a->next == NULL)
		return ;
	start->temp = start->a;
	start->temp = start->temp->next;
	start->a->next = start->temp->next;
	start->temp->next = start->a;
	start->a = start->temp;
	if (i)
		write(1, "sa\n", 3);
}

void	ra(t_swap *start, int i)
{
	if (start->a == NULL || start->a->next == NULL)
		return ;
	start->temp = ft_lstlast(start->a);
	start->temp->next = start->a;
	start->temp = start->a;
	start->a = start->a->next;
	start->temp->next = NULL;
	if (i)
		write(1, "ra\n", 3);
}

void	rra(t_swap *start, int i)
{
	if (start->a == NULL || start->a->next == NULL)
		return ;
	start->temp = start->a;
	while (start->temp->next->next != NULL)
		start->temp = start->temp->next;
	start->rotate = start->temp->next;
	start->temp->next = NULL;
	start->rotate->next = start->a;
	start->a = start->rotate;
	if (i)
		write(1, "rra\n", 4);
}

void	pa(t_swap *start, int i)
{
	if (start->b == NULL)
		return ;
	if (start->b->next)
	{
		start->temp = start->b;
		start->temp = start->temp->next;
	}
	else
		start->temp = NULL;
	if (start->a == NULL)
	{
		start->a = start->b;
		start->a->next = NULL;
	}
	else
	{
		start->b->next = start->a;
		start->a = start->b;
	}
	start->b = start->temp;
	if (i)
		write(1, "pa\n", 3);
}
