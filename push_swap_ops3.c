/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:30:29 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:43:32 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*tmp;
	t_node	*current;

	if (a->top->next == NULL)
		return ;
	current = a->top;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*tmp;
	t_node	*current;

	if (b->top->next == NULL)
		return ;
	current = b->top;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*current;

	if (a->top != NULL && a->top->next != NULL)
	{
		current = a->top;
		while (current->next->next != NULL)
			current = current->next;
		tmp = current->next;
		current->next = NULL;
		tmp->next = a->top;
		a->top = tmp;
		write(1, "rra\n", 4);
	}
	if (b->top != NULL && b->top->next != NULL)
	{
		current = b->top;
		while (current->next->next != NULL)
			current = current->next;
		tmp = current->next;
		current->next = NULL;
		tmp->next = b->top;
		b->top = tmp;
		write(1, "rrb\n", 4);
	}
}
