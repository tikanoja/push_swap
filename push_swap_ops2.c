/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:26:42 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:34:08 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*current;

	if (a->top->next == NULL)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*current;

	if (b->top->next == NULL)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	current = b->top;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*current;

	if (a->top->next != NULL)
	{
		tmp = a->top;
		a->top = a->top->next;
		current = a->top;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
	if (a->top->next != NULL)
	{
		tmp = b->top;
		b->top = b->top->next;
		current = b->top;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}
