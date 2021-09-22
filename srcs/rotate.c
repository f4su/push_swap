/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:10:53 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/17 15:11:05 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_ptr to_a)
{
	t_ptr	temp;

	if (to_a->count == 2)
		sa(to_a);
	else if (to_a->count > 2)
	{
		temp = to_a->top;
		to_a->top = temp->llink;
		temp->llink = to_a;
		temp->rlink = to_a->rlink;
		to_a->rlink->llink = temp;
		to_a->rlink = temp;
		to_a->top->rlink = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_ptr to_b)
{
	t_ptr	temp;

	if (to_b->count == 2)
		sb(to_b);
	else if (to_b->count > 2)
	{
		temp = to_b->top;
		to_b->top = temp->llink;
		temp->llink = to_b;
		temp->rlink = to_b->rlink;
		to_b->rlink->llink = temp;
		to_b->rlink = temp;
		to_b->top->rlink = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_ptr to_a, t_ptr to_b)
{
	ra(to_a);
	rb(to_b);
}
