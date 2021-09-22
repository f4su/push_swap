/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:11:40 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/17 15:11:46 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_ptr to)
{
	t_data	data;

	data = to->top->data;
	to->top->data = to->top->llink->data;
	to->top->llink->data = data;
}

void	sa(t_ptr to_a)
{
	swap(to_a);
	write(1, "sa\n", 3);
}

void	sb(t_ptr to_b)
{
	swap(to_b);
	write(1, "sb\n", 3);
}

void	ss(t_ptr to_a, t_ptr to_b)
{
	sa(to_a);
	sb(to_b);
}
