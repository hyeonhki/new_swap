/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:42:56 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 14:46:46 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_element **a, t_element **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rrab(a, 0);
	rrab(b, 0);
	my_putstr("rrr");
}

void	ss(t_element **a, t_element **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	sab(a, 0);
	sab(b, 0);
	my_putstr("ss");
}

void	rr(t_element **a, t_element **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rab(a, 0);
	rab(b, 0);
	my_putstr("rr");
}