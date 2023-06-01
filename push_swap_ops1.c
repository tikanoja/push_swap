/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:23:55 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:33:29 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->top == NULL)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->top == NULL)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "pa\n", 3);
}

void	sa(t_stack *a)
{
	t_node	*tmp;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*tmp;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->next;
	b->top->next = b->top->next->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->top != NULL || a->top->next != NULL)
	{
		tmp = a->top->next;
		a->top->next = a->top->next->next;
		tmp->next = a->top;
		a->top = tmp;
	}
	if (b->top != NULL || b->top->next != NULL)
	{
		tmp = b->top->next;
		b->top->next = b->top->next->next;
		tmp->next = b->top;
		b->top = tmp;
	}
	write(1, "ss\n", 3);
}
