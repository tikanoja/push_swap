/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:19:43 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:38:04 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack *a)
{
	t_node	*current;
	int		i;

	i = a->top->data;
	current = a->top->next;
	while (current != NULL)
	{
		if (i > current->data)
			return (-1);
		else
		{
			i = current->data;
			current = current->next;
		}
	}
	freestack(a);
	return (1);
}

int	intcheck(const char *str, t_stack *a)
{
	long	i;
	int		sign;

	i = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	i = i * sign;
	if (i < -2147483648 || i > 2147483647)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	inputcheck(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc <= 1)
		return (-1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "Error\n", 6);
				return (-2);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	dupcheck(t_stack *a)
{
	int		i;
	t_node	*current;
	t_node	*reference;

	i = 0;
	reference = a->top;
	while (reference != NULL)
	{
		current = a->top;
		while (current != NULL)
		{
			if (reference->data == current->data)
				i++;
			if (i > 1)
			{
				write(2, "Error\n", 6);
				freestack(a);
				return (-1);
			}
			current = current->next;
		}
		reference = reference->next;
		i = 0;
	}
	return (0);
}
