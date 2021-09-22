/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:06:16 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/22 12:55:01 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	int	value;
	int	rank;
}	t_data;

typedef struct s_stack	*t_ptr;
typedef struct s_stack
{
	t_data	data;
	int		count;
	t_ptr	llink;
	t_ptr	rlink;
	t_ptr	top;
}	t_stack;

void		swap(t_ptr to);
void		sa(t_ptr to_a);
void		sb(t_ptr to_b);
void		ss(t_ptr to_a, t_ptr to_b);

t_data		pop(t_ptr to);
int			push(t_data data, t_ptr to);
int			pa(t_ptr to_b, t_ptr to_a);
int			pb(t_ptr to_a, t_ptr to_b);

void		ra(t_ptr to_a);
void		rb(t_ptr to_b);
void		rr(t_ptr to_a, t_ptr to_b);

void		rra(t_ptr to_a);
void		rrb(t_ptr to_b);
void		rrr(t_ptr to_a, t_ptr to_b);

int			stack_init(int value, t_ptr to);
t_ptr		stack_free(t_ptr to);
void		rank_get(t_ptr to);
void		rank_init(t_ptr to_a, t_ptr to_b);
int			sorted(t_ptr to);

int			is_digit(const char *s);
void		error_write(void);
int			error_treat(char *s, t_ptr to);
long long	ftatoi(const char *s);

int			argv_treat(int argc, char **argv, t_ptr to);
int			main(int argc, char **argv);

void		sortage_for_three(t_ptr to_a, t_ptr to_b);
void		sortage_for_four(t_ptr to_a, t_ptr to_b);
void		sortage_for_five(t_ptr to_a, t_ptr to_b);
void		sortage_radix(t_ptr to_a, t_ptr to_b);
int			sortage(t_ptr to_a);

int			count_row(const char *s, char c);
char		**free_if_fail(char **split, int size);
char		**put_split(char const *s, char c, int row, char **split);
char		**ftsplit(char const *s, char c);

#endif
