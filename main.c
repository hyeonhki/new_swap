/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:25:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/30 21:13:43 by hyeonhki         ###   ########.fr       */
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

int	is_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (!(str[i] == '-' || str[i] == '+'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	letter_check(int nb, char **arg)
{
	while (nb > 1)
	{
		if (is_letter(arg[nb - 1]) == 1)
			return (1);
		nb--;
	}
	return (0);
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
	if (letter_check(nb, arg) == 1)
		return (msg_error("Error\n"));
	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	atob(prgm.len, &a, &b, &swap);
	return (0);
}
