/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:25:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/27 19:07:35 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->nbrneg = 0;
	prgm->range = 0;
}

void	check_stack(t_element *a, t_element *b)
{
	t_element	*temp;

	temp = 0;
	printf("A : ");
	temp = a;
	while (1 && temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
		if ((a)->val == temp->val)
			break ;
	}
	printf("\nB : ");
	temp = b;
	while (1 && temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
		if ((b)->val == temp->val)
			break ;
	}
	printf("\n");
}

void	stack_free(int r, t_element **ab)
{
	t_element *next;

	while (r > 0)
	{
		if (r != 1)
			next = (*ab)->next;
		free(*ab);
		*ab = next;
		r--;
	}
}

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;
	int		flag;

	a = NULL;
	b = NULL;
	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	flag = 0;
	A_to_B(nb - 1, &flag, &a, &b);
//	check_stack(a, b);
	system("leaks push_swap | grep \"total leaked\"");
	return (0);
}