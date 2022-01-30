/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:02:25 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/31 00:23:42 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	range_check(char **str, t_program *prgm)
{
	if (prgm->cnt == 10)
	{
		prgm->range = 1;
		return (0);
	}
	if (prgm->cnt == 9)
	{
		if (prgm->sign == -1 && prgm->result >= 214748364)
		{
			if (**str > '8')
			{
				prgm->range = 1;
				return (0);
			}
		}
		if (prgm->sign == 1 && prgm->result >= 214748364)
		{
			if (**str > '7')
			{
				prgm->range = 1;
				return (0);
			}
		}
	}
	return (1);
}

void	set_prgm(t_program *prgm)
{
	prgm->result = 0;
	prgm->sign = 1;
	prgm->cnt = 0;
	prgm->flag = 1;
	prgm->pm_cnt = 0;
}

void	letter_check(char *str, t_program *prgm)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (!(str[i] == '-' || str[i] == '+' || str[i] == ' '))
				prgm->letter = 1;
		}
		i++;
	}
}

int	my_atoi(char **str, t_program *prgm)
{
	set_prgm(prgm);
	letter_check(*str, prgm);
	while (is_space(**str) == 1)
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
		{
			prgm->sign *= -1;
			prgm->nbrneg += 1;
		}
		prgm->pm_cnt += 1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		prgm->flag = 0;
		if (range_check(str, prgm) == 0)
			return (0);
		prgm->result = prgm->result * 10 + **str - '0';
		(*str)++;
		prgm->cnt += 1;
	}
	return (prgm->result * prgm->sign);
}
