/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:40:20 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/09 15:57:35 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct snode
{
	int				data;
	int				rel;
	char			bin[33];
	struct snode	*next;
}				t_node;

typedef struct sstack
{
	struct snode	*top;
}				t_stack;

int			main(int argc, char **argv);
void		pb(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		printstacks(t_stack *a, t_stack*b);
t_node		*createnode(int argv);
int			createstack(t_stack *a, char **argv);
void		stackinit(t_stack *stack);
int			inputcheck(int argc, char **argv);
int			dupcheck(t_stack *a);
int			intcheck(const char *str, t_stack *a);
int			stacksize(t_stack *a, t_stack *b);
int			issorted(t_stack *a);
void		sortthree(t_stack *a);
void		sortsmall(t_stack *a, t_stack *b, int stacksize);
void		putbackthree(t_stack *a, t_stack *b);
void		putbackfour1(t_stack *a, t_stack *b);
void		putbackfour2(t_stack *a, t_stack *b);
void		fillrel(t_stack *a);
void		fillbin(t_stack *a);
int			ft_atoi(const char *str);
int			ft_printf(const char *str, ...);
void		invertbinary(t_node *current, char *binary);
void		resetbinary(char *binary);
void		sortbig(t_stack *a, t_stack *b, int size);
int			stringinput(int argc, char **argv);
int			maxbits(t_stack *a);
int			createstackstr(t_stack *a, char **argv);
int			inpututil(t_stack *a, t_stack *b, int argc, char **argv);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
static char	**fillarr(char **arr, const char *s, char c, int wcount);
static int	wordcount(const char *s, char c);
static char	**getarray(char *dup, char c, int wcount);
static int	wordlen(char *dup, char c);
size_t		ft_strlen(const char *s);
int			finddelimiter(char *input);
void		freestack(t_stack *a);
void		freearray(char **arr);

#endif
