/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:47:56 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/15 19:31:12 by qrolande         ###   ########.fr       */
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

static void	search_for_3(t_swap *start, char *line)
{
	int	i;

	i = 0;
	if (line[i + 1] != 'r' || (line[i + 2] != 'r' && line[i + 2] != 'a'
			&& line[i + 2] != 'b'))
		cleaning_company(start);
}

void	search(t_swap *start, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (len == 2)
	{
		if (line[i] != 's' && line[i] != 'r' && line[i] != 'p')
			cleaning_company(start);
		if (line[i] != 'r' && line[i + 1] != 'r' && line[i + 1] != 'a'
			&& line[i + 1] != 'b')
			cleaning_company(start);
		if (line[i] == 's' && line[i + 1] != 'a' && line[i + 1] != 'b'
			&& line[i + 1] != 's')
			cleaning_company(start);
		if (line[i] == 'p' && (line[i + 1] != 'a' && line[i + 1] != 'b'))
			cleaning_company(start);
	}
	else if (len == 3)
		search_for_3(start, line);
	else
		cleaning_company(start);
}
