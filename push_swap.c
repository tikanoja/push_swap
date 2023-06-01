/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:19:48 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/10 13:50:23 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	freestack(t_stack *a)
{
	t_node	*current;
	t_node	*tmp;

	current = a->top;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	inpututil(t_stack *a, t_stack *b, int argc, char **argv)
{
	if (argc == 2)
	{
		if (stringinput(argc, argv) < 0)
			return (0);
	}
	else
	{
		if (inputcheck(argc, argv) < 0)
			return (0);
	}
	stackinit(a);
	stackinit(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		size;

	if (inpututil(&a, &b, argc, argv) == 0)
		return (0);
	if (argc == 2 && finddelimiter(argv[1]) == 1)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL || createstackstr(&a, argv) < 0)
			return (0);
	}
	else
		if (createstack(&a, argv) < 0)
			return (0);
	if (dupcheck(&a) < 0 || issorted(&a) > 0)
		return (0);
	size = stacksize(&a, &b);
	if (size <= 5)
		sortsmall(&a, &b, size);
	else
		sortbig(&a, &b, size);
	freestack(&a);
	return (0);
}
