/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_begin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:31 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/14 14:54:13 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*free_spl(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		++i;
	}
	free(split);
	return (NULL);
}

void	lets_begin(t_swap *start, int ac, char **av)
{
	int		atoi_res;
	char	**spl_res;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		spl_res = ft_split(av[i], ' ');
		j = 0;
		while (spl_res[j])
		{
			atoi_res = ft_atoi(spl_res[j++]);
			start->temp = start->a;
			while (start->temp)
			{
				if (start->temp->content == atoi_res)
					cleaning_company(start);
				start->temp = start->temp->next;
			}
			start->temp = ft_lstnew(atoi_res);
			ft_lstadd_back(&start->a, start->temp);
		}
		free_spl(spl_res, j);
	}
}
