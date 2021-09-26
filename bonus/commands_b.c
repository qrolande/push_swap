/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:10:29 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 19:38:50 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_swap *start, int i)
{
	if (start->b == NULL || start->b->next == NULL)
		return ;
	start->temp = start->b;
	start->temp = start->temp->next;
	start->b->next = start->temp->next;
	start->temp->next = start->b;
	start->b = start->temp;
	if (i)
		write(1, "sb\n", 3);
}

void	rb(t_swap *start, int i)
{
	if (start->b == NULL || start->b->next == NULL)
		return ;
	start->temp = ft_lstlast(start->b);
	start->temp->next = start->b;
	start->temp = start->b;
	start->b = start->b->next;
	start->temp->next = NULL;
	if (i)
		write(1, "rb\n", 3);
}

void	rrb(t_swap *start, int i)
{
	if (start->b == NULL || start->b->next == NULL)
		return ;
	start->temp = start->b;
	while (start->temp->next->next != NULL)
		start->temp = start->temp->next;
	start->rotate = start->temp->next;
	start->temp->next = NULL;
	start->rotate->next = start->b;
	start->b = start->rotate;
	if (i)
		write(1, "rrb\n", 4);
}

void	pb(t_swap *start, int i)
{
	if (start->a == NULL)
		return ;
	if (start->a->next)
	{
		start->temp = start->a;
		start->temp = start->temp->next;
	}
	else
		start->temp = NULL;
	if (start->b == NULL)
	{
		start->b = start->a;
		start->b->next = NULL;
	}
	else
	{
		start->a->next = start->b;
		start->b = start->a;
	}
	start->a = start->temp;
	if (i)
		write(1, "pb\n", 3);
}
