/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:23:30 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:32:32 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxbits(t_stack *a)
{
	int		i;
	int		max;
	t_node	*current;

	i = 0;
	max = 32;
	current = a->top;
	while (current != NULL)
	{
		while (current->bin[i] != '1' && current->bin[i] != '\0')
			i++;
		if (i < max)
			max = i;
		current = current->next;
		i = 0;
	}
	return (max);
}

void	sortbig(t_stack *a, t_stack *b, int size)
{
	int		i;
	int		stacksize;
	int		bitlimit;
	t_node	*current;

	i = 31;
	stacksize = size;
	bitlimit = maxbits(a);
	while (i >= bitlimit)
	{
		current = a->top;
		while (size > 0)
		{
			if (current->bin[i] == '0')
				pb(a, b);
			else
				ra(a);
			current = a->top;
			size--;
		}
		while (b->top != NULL)
			pa(a, b);
		i--;
		size = stacksize;
	}
}
