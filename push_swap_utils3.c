/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:24:50 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:38:55 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finddelimiter(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	resetbinary(char *binary)
{
	int	i;

	i = 0;
	while (i < 33)
	{
		binary[i] = '0';
		i++;
	}
	binary[32] = '\0';
}

void	invertbinary(t_node *current, char *binary)
{
	int	i;
	int	j;

	i = 0;
	j = 31;
	while (j >= 0 && binary[i])
	{
		current->bin[j] = binary[i];
		j--;
		i++;
	}
	while (j >= 0)
	{
		current->bin[j] = '0';
		j--;
	}
	current->bin[32] = '\0';
}

void	fillbin(t_stack *a)
{
	t_node	*current;
	int		i;
	int		num;
	char	binary[33];

	current = a->top;
	while (current != NULL)
	{
		i = 0;
		num = current->rel;
		while (num > 0)
		{
			if (num % 2 == 0)
				binary[i] = '0';
			else
				binary[i] = '1';
			num /= 2;
			i++;
		}
		binary[i] = '\0';
		invertbinary(current, binary);
		resetbinary(binary);
		current = current->next;
	}
}

void	fillrel(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		n;

	current = a->top;
	compare = a->top;
	n = 0;
	while (current != NULL)
	{
		while (compare != NULL)
		{
			if (compare->data < current->data)
				n++;
			compare = compare->next;
		}
		current->rel = n;
		n = 0;
		compare = a->top;
		current = current->next;
	}
}
