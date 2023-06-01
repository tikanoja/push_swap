/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:09:43 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:56:01 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackstrloop(t_stack *a, char **argv, t_node *newnode, int i)
{
	while (argv[i])
	{
		if (intcheck(argv[i], a) < 0)
			return (-1);
		if (newnode == NULL)
		{
			newnode = createnode(ft_atoi(argv[i]));
			if (newnode == NULL)
				return (-1);
			a->top = newnode;
		}
		else
		{
			newnode->next = createnode(ft_atoi(argv[i]));
			if (newnode == NULL)
				return (-1);
			newnode = newnode->next;
		}
		i++;
	}
	newnode->next = NULL;
	return (1);
}

int	createstackstr(t_stack *a, char **argv)
{
	int		i;
	t_node	*newnode;

	newnode = NULL;
	i = 0;
	if (stackstrloop(a, argv, newnode, i) < 0)
	{
		freearray(argv);
		freestack(a);
		return (-1);
	}
	freearray(argv);
	return (0);
}

int	stringinput(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[1][j])
		j++;
	if (j == 0)
		return (-1);
	while (i < j)
	{
		if (argv[1][i] == '-' || argv[1][i] == '+')
			i++;
		while (argv[1][i] != ' ' && argv[1][i])
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				write(2, "Error\n", 6);
				return (-2);
			}
			i++;
		}
		i++;
	}
	return (0);
}
