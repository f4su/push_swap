/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:10:35 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/17 15:10:46 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_ptr to_a)
{
	t_ptr	temp;

	if (to_a->count == 2)
		sa(to_a);
	else if (to_a->count > 2)
	{
		temp = to_a->rlink;
		to_a->rlink = temp->rlink;
		temp->rlink->llink = to_a;
		to_a->top->rlink = temp;
		temp->llink = to_a->top;
		to_a->top = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_ptr to_b)
{
	t_ptr	temp;

	if (to_b->count == 2)
		sb(to_b);
	else if (to_b->count > 2)
	{
		temp = to_b->rlink;
		to_b->rlink = temp->rlink;
		temp->rlink->llink = to_b;
		to_b->top->rlink = temp;
		temp->llink = to_b->top;
		to_b->top = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_ptr to_a, t_ptr to_b)
{
	rra(to_a);
	rrb(to_b);
}
