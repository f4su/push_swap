/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:12:16 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/22 12:10:36 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			j = -1;
		if (s[0] == '-' || s[0] == '+')
			j = 0;
		i++;
	}
	return (j);
}

void	error_write(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	error_treat(char *s, t_ptr to)
{
	long long	value;

	value = ftatoi(s);
	if (value > 2147483647 || value < -2147483648)
		return (-1);
	if (is_digit(s) == -1 || stack_init((int)value, to) == -1)
		return (-1);
	return (0);
}

long long	ftatoi(const char *s)
{
	long long	num;
	long long	sign;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	sign = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	num = 0;
	while (*s - '0' >= 0 && *s - '0' <= 9)
	{
		num *= 10;
		num += *s - '0';
		s++;
	}
	return (num * sign);
}
