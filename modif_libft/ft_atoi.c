/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:08:06 by qrolande          #+#    #+#             */
/*   Updated: 2021/10/11 20:47:38 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	max_min_int(long nmbr, int res)
{
	long	max_int;

	max_int = 2147483647;
	if ((nmbr > max_int + 1 && res == -1) || (nmbr > max_int && res == 1))
	{
		write(1, "error\n", 7);
		exit (0);
	}
}

static long	ft_numcheck(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "error\n", 7);
			exit (0);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	long	nmbr;
	int		i;
	long	res;

	res = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		if (str[i++] == '-')
			res = -1;
	nmbr = ft_numcheck(&str[i]);
	max_min_int(nmbr, res);
	return ((int)(res * nmbr));
}
