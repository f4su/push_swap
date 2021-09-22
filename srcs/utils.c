/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:11:54 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/17 15:13:31 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_init(int value, t_ptr to)
{
	t_ptr	b;

	b = malloc(sizeof(t_stack));
	if (b == 0)
		return (-1);
	b->data.value = value;
	if (to->rlink != NULL)
	{
		b->llink = to;
		b->rlink = to->rlink;
		to->rlink->llink = b;
		to->rlink = b;
	}
	else
	{
		to->rlink = b;
		to->top = b;
		b->llink = to;
		b->rlink = NULL;
	}
	to->count++;
	return (0);
}

t_ptr	stack_free(t_ptr to)
{
	t_ptr	s;
	t_ptr	tmp;

	s = to->top;
	while (s)
	{
		tmp = s;
		s = s->llink;
		free(tmp);
	}
	return (to);
}

void	rank_get(t_ptr to)
{
	t_ptr	s;
	t_ptr	next;

	s = to->top;
	while (s != to)
	{
		next = to->top;
		while (next != to)
		{
			if (s->data.value > next->data.value)
				s->data.rank++;
			next = next->llink;
		}
		s = s->llink;
	}
}

void	rank_init(t_ptr to_a, t_ptr to_b)
{
	t_ptr	s;

	if (to_a->count != 0)
	{
		s = to_a->top;
		while (s != to_a)
		{
			s->data.rank = 0;
			s = s->llink;
		}
	}
	if (to_b->count != 0)
	{
		s = to_b->top;
		while (s != to_b)
		{
			s->data.rank = 0;
			s = s->llink;
		}
	}
}

int	sorted(t_ptr to)
{
	t_ptr	s;
	t_ptr	temp;
	int		ret_value;

	ret_value = 0;
	s = to->top;
	while (s != to)
	{
		temp = s->llink;
		while (temp != to)
		{
			if (temp->data.value < s->data.value)
				ret_value = -1;
			else if (temp->data.value == s->data.value)
				return (-2);
			temp = temp->llink;
		}
		s = s->llink;
	}
	return (ret_value);
}
