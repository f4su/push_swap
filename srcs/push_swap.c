/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:10:21 by jgainza-          #+#    #+#             */
/*   Updated: 2021/09/22 12:37:43 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	argv_treat(int argc, char **argv, t_ptr to)
{
	char	**s;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		s = ft_split(argv[i], ' ');
		if (s == 0 || s[0] == 0)
			return (-1);
		j = 0;
		while (s[j])
		{
			if (error_treat(s[j], to) == -1)
				return (-1);
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ptr	to_a;
	int		check;

	if (argc == 1)
		exit(1);
	to_a = malloc(sizeof(t_stack));
	if (to_a == 0)
		error_write();
	to_a->llink = NULL;
	to_a->rlink = NULL;
	if (argv_treat(argc, argv, to_a) == -1)
		error_write();
	check = sorted(to_a);
	if (check == 0)
		exit(1);
	else if (check == -2)
		error_write();
	if (sortage(to_a) == -1)
		error_write();
	to_a = stack_free(to_a);
	return (0);
}
