/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_company.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:12:59 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/10 22:58:36 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cleaning_company(t_swap *start)
{
	ft_lstclear(&start->a);
	ft_lstclear(&start->b);
	write(2, "error\n", 7);
	exit (0);
}
