/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:59:35 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:35:11 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putbackfour2(t_stack *a, t_stack *b)
{
	if (b->top->data < a->top->next->next->next->data)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else
	{
		pa(a, b);
		ra(a);
	}
}

void	putbackfour1(t_stack *a, t_stack *b)
{
	if (b->top->data < a->top->data)
		pa(a, b);
	else if (b->top->data < a->top->next->data)
	{
		pa(a, b);
		sa(a);
	}
	else if (b->top->data < a->top->next->next->data)
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else
		putbackfour2(a, b);
}

void	putbackthree(t_stack *a, t_stack *b)
{
	if (b->top->data < a->top->data)
		pa(a, b);
	else if (b->top->data < a->top->next->data)
	{
		pa(a, b);
		sa(a);
	}
	else if (b->top->data < a->top->next->next->data)
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else
	{
		pa(a, b);
		ra(a);
	}
}

void	sortthree(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->data;
	second = a->top->next->data;
	third = a->top->next->next->data;
	if (first < second && second > third && third > first)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && second < third && third > first)
		sa(a);
	else if (first < second && second > third && third < first)
		rra(a);
	else if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && third < first)
		ra(a);
}

void	sortsmall(t_stack *a, t_stack *b, int stacksize)
{
	if (stacksize == 2)
	{
		sa(a);
	}
	else if (stacksize == 3)
		sortthree(a);
	else if (stacksize == 4)
	{
		pb(a, b);
		sortthree(a);
		putbackthree(a, b);
	}
	else
	{
		pb(a, b);
		pb(a, b);
		sortthree(a);
		putbackthree(a, b);
		putbackfour1(a, b);
	}
}
