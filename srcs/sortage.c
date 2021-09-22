/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:11:22 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/22 12:53:31 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sortage_for_three(t_ptr to_a, t_ptr to_b)
{
	char	s[4];

	rank_init(to_a, to_b);
	rank_get(to_a);
	s[0] = to_a->top->data.rank + '0';
	s[1] = to_a->top->llink->data.rank + '0';
	s[2] = to_a->top->llink->llink->data.rank + '0';
	s[3] = 0;
	if (!ft_strncmp(s, "021", 3))
	{
		rra(to_a);
		sa(to_a);
	}
	else if (!ft_strncmp(s, "102", 3))
		sa(to_a);
	else if (!ft_strncmp(s, "120", 3))
		rra(to_a);
	else if (!ft_strncmp(s, "201", 3))
		ra(to_a);
	else if (!ft_strncmp(s, "210", 3))
	{
		sa(to_a);
		rra(to_a);
	}
}

void	sortage_for_four(t_ptr to_a, t_ptr to_b)
{
	rank_get(to_a);
	while (1)
	{
		if (to_a->top->data.rank == 0)
		{
			pb(to_a, to_b);
			break ;
		}
		else
			ra(to_a);
	}
	rank_init(to_a, to_b);
	sortage_for_three(to_a, to_b);
	pa(to_b, to_a);
}

void	sortage_for_five(t_ptr to_a, t_ptr to_b)
{
	static int	flag_0;
	static int	flag_1;

	while (!flag_0 || !flag_1)
	{
		if (to_a->top->data.rank == 0)
		{
			pb(to_a, to_b);
			flag_0 = 1;
		}
		else if (to_a->top->data.rank == 1)
		{
			pb(to_a, to_b);
			flag_1 = 1;
		}
		else
			ra(to_a);
	}
	if (to_b->top->data.rank < to_b->top->llink->data.rank)
		sb(to_b);
	rank_init(to_a, to_b);
	sortage_for_three(to_a, to_b);
	pa(to_b, to_a);
	pa(to_b, to_a);
}

void	sortage_radix(t_ptr to_a, t_ptr to_b)
{
	int	i;
	int	j;
	int	count;
	int	maxn;
	int	maxl;

	maxn = to_a->count - 1;
	maxl = 0;
	while ((maxn >> maxl) != 0)
		++maxl;
	i = -1;
	while (++i < maxl)
	{
		j = -1;
		count = to_a->count;
		while (++j < count)
		{
			if (((to_a->top->data.rank >> i) & 1) == 0)
				pb(to_a, to_b);
			else
				ra(to_a);
		}
		while (to_b->count != 0)
			pa(to_b, to_a);
	}
}

int	sortage(t_ptr to_a)
{
	t_ptr	to_b;

	to_b = malloc(sizeof(t_stack));
	if (to_b == 0)
		return (-1);
	to_b->llink = NULL;
	to_b->rlink = NULL;
	rank_get(to_a);
	if (to_a->count == 2)
		sa(to_a);
	else if (to_a->count == 3)
	{
		sortage_for_three(to_a, to_b);
		exit(1);
	}
	else if (to_a->count == 4)
		sortage_for_four(to_a, to_b);
	else if (to_a->count == 5)
		sortage_for_five(to_a, to_b);
	else
		sortage_radix(to_a, to_b);
	to_b = stack_free(to_b);
	return (0);
}
