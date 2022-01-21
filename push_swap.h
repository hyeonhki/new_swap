/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:28:29 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 16:26:04 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_program
{
	int					letter;
	int					range;
	int					error;
	int					nbrneg;
}				t_program;

typedef struct s_element
{
	int					val;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

unsigned int		my_strlen(const char *str, t_program *prgm);
int					my_getnbr(char *str, t_program *prgm);
void	my_putstr(char *str);

t_element	*stack_init(int nb, char **arg, t_program *prgm);

int	error_check(t_program *prgm, int nb, t_element *a);
int	double_check(int nb, t_element *a);
int	msg_error(char *str);

//void	pab(t_element **ab, t_element **ba, char *com);
void	pab(t_element **b, t_element **a, char *com);
void	rab(t_element **ab, char *com);
void	sab(t_element **ab, char *com);
void	rrab(t_element **ab, char *com);
void	rrr(t_element **a, t_element **b);
void	ss(t_element **a, t_element **b);
void	rr(t_element **a, t_element **b);


void	atob(int r, int flag, t_element **a, t_element **b);
void	btoa(int r, int flag, t_element **a, t_element **b);

int	pivot_sort(int r, t_element *a);

void	check_stack(t_element *a, t_element *b);

#endif