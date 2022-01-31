/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:25:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/31 15:20:08 by hyeonhki         ###   ########.fr       */
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
	prgm->len = 0;
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
	swap.flag = 0;
	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	swap.arr = (int *)malloc((prgm.len) * sizeof(int));
	if (error_check(&prgm, prgm.len + 1, a) == 1)
		return (0);
	atob(prgm.len, &a, &b, &swap);
	return (0);
}
