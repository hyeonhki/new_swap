/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:28:29 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/31 20:54:45 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_program
{
	int					letter;
	int					range;
	int					error;
	int					nbrneg;
	int					pm_cnt;
	int					flag;
	int					len;
	int					result;
	int					sign;
	int					cnt;
	int					sp;
}				t_program;

typedef struct s_element
{
	int					val;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_swap
{
	int					flag;
	int					*arr;
	int					i;
	int					p;
}				t_swap;

void			atob(int r, t_element **a, t_element **b, t_swap *swap);
unsigned int	my_strlen(const char *str, t_program *prgm);
void			my_putstr(char *str);
int				my_atoi(char **str, t_program *prgm);

t_element		*stack_init(int nb, char **arg, t_program *prgm);

int				error_check(t_program *prgm, int nb, t_element *a);
int				double_check(int nb, t_element *a);
int				msg_error(char *str);

void			pab(t_element **b, t_element **a, char *com);
void			rab(t_element **ab, char *com);
void			sab(t_element **ab, char *com);
void			rrab(t_element **ab, char *com);
void			rrr(t_element **a, t_element **b);
void			ss(t_element **a, t_element **b);
void			rr(t_element **a, t_element **b);

void			sort_three(t_element **a);
void			find_maxmin(int r, t_element *a, int *max, int *min);
int				check_sort(int r, t_element *temp);
int				r_range(int r, t_element *b);

void			pivot_sort(int *arr, int *p, int r, t_element *a);
#endif