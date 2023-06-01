/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:14:25 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:37:20 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a->top;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	fillrel(a);
	fillbin(a);
	return (i);
}

t_node	*createnode(int argv)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode)
	{
		newnode->data = argv;
		newnode->next = NULL;
	}
	return (newnode);
}

int	stackloop(t_stack *a, char **argv, t_node *newnode, int i)
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

int	createstack(t_stack *a, char **argv)
{
	int		i;
	t_node	*newnode;

	newnode = NULL;
	i = 1;
	if (stackloop(a, argv, newnode, i) < 0)
	{
		freestack(a);
		return (-1);
	}
	return (1);
}

void	stackinit(t_stack *stack)
{
	stack->top = NULL;
}
