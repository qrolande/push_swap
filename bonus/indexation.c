/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:56:42 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 19:25:13 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	all_indexation_action(t_swap *start, int len, int *temp_num)
{
	int	i;
	int	buff;

	i = 0;
	while (i < len - 1)
	{
		if (temp_num[i] > temp_num[i + 1])
		{
			buff = temp_num[i];
			temp_num[i] = temp_num[i + 1];
			temp_num[i + 1] = buff;
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	while (++i <= len - 1)
	{
		start->temp = start->a;
		while (temp_num[i] != start->temp->content)
			start->temp = start->temp->next;
		start->temp->index = i;
	}
}

void	indexation(t_swap *start)
{
	int	*temp_num;
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(start->a);
	temp_num = malloc(sizeof(int) * len);
	if (temp_num == NULL)
		cleaning_company(start);
	start->temp = start->a;
	while (start->temp)
	{
		temp_num[i++] = start->temp->content;
		start->temp = start->temp->next;
	}
	all_indexation_action(start, len, temp_num);
	free (temp_num);
}
