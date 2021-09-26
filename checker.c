/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:45:08 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/15 20:27:52 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker_initialization(t_swap *start, int ac, char **av)
{
	char	*line;
	int		res;

	start->a = NULL;
	start->b = NULL;
	if (ac > 1)
	{
		lets_begin(start, ac, av);
		res = ft_lstsize(start->a);
		indexation(start);
		res = get_next_line(&line);
		while (res && res != -1)
		{
			search(start, line);
			just_do_it(start, line);
			free(line);
			res = get_next_line(&line);
		}
		if (res == -1)
			cleaning_company(start);
	}
	else
		exit (0);
}

int	main(int ac, char **av)
{
	t_swap	start;
	int		res;

	checker_initialization(&start, ac, av);
	res = ft_lstsize(start.b);
	if (res && start.temp->index)
		ko_out(&start);
	start.temp = start.a;
	while (start.temp->next != NULL)
	{
		if (start.temp->index + 1 == start.temp->next->index)
			start.temp = start.temp->next;
		else
			ko_out(&start);
	}
	write(1, "OK\n", 3);
	ft_lstclear(&start.a);
	return (0);
}
