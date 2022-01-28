/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:58:53 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/29 01:19:09 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_element **ab, char *com)
{
	int	temp;

	if (*ab == NULL || *ab == (*ab)->next)
		return ;
	temp = (*ab)->val;
	(*ab)->val = (*ab)->next->val;
	(*ab)->next->val = temp;
	if (com)
		my_putstr(com);
}

void	rab(t_element **ab, char *com)
{
	if ((*ab) == NULL)
		return ;
	*ab = (*ab)->next;
	if (com)
		my_putstr(com);
}

void	rrab(t_element **ab, char *com)
{
	if ((*ab) == NULL)
		return ;
	*ab = (*ab)->prev;
	if (com)
		my_putstr(com);
}

void	pab(t_element **b, t_element **a, char *com)
{
	t_element	*temp;

	temp = NULL;
	if (*a == NULL)
		return ;
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	temp = (*a)->next;
	if ((*a)->next->val == (*a)->val)
		temp = NULL;
	if (*b == NULL)
	{
		(*a)->prev = (*a);
		(*a)->next = (*a);
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*a)->next = *b;
		(*b)->prev->next = (*a);
		(*b)->prev = (*a);
	}
	(*b) = (*a);
	(*a) = temp;
	my_putstr(com);
}
