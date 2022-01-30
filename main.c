/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:25:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/30 20:41:26 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->nbrneg = 0;
	prgm->range = 0;
	prgm->pm_cnt = 0;
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

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;
	t_swap		swap;

	a = NULL;
	b = NULL;
	if (nb == 1)
		return (0);
	swap.arr = (int *)malloc((nb - 1) * sizeof(int));
	swap.flag = 0;
	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	atob(prgm.len, &a, &b, &swap);
	return (0);
}
