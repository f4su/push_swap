/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:10:02 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/17 15:12:42 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	pop(t_ptr to)
{
	t_ptr	temp;
	t_data	data;

	temp = to->top;
	data = temp->data;
	to->top = temp->llink;
	to->top->rlink = NULL;
	temp->llink = NULL;
	free(temp);
	temp = NULL;
	to->count--;
	return (data);
}

int	push(t_data data, t_ptr to)
{
	t_ptr	b;

	b = malloc(sizeof(t_stack));
	if (b == 0)
		return (-1);
	b->data = data;
	if (to->rlink == NULL)
	{
		to->rlink = b;
		to->top = to->rlink;
		b->llink = to;
	}
	else
	{
		to->top->rlink = b;
		b->llink = to->top;
		to->top = b;
	}
	b->rlink = NULL;
	to->count++;
	return (0);
}

int	pa(t_ptr to_b, t_ptr to_a)
{
	t_data	data;

	data = pop(to_b);
	if (push(data, to_a) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_ptr to_a, t_ptr to_b)
{
	t_data	data;

	data = pop(to_a);
	if (push(data, to_b) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
