/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:34 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/30 18:09:41 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_range(int r, t_element *b)
{
	int	i;
	int	k;
	int	ret;

	k = 1;
	i = b->val;
	while (k < r)
	{
		b = b->next;
		k++;
	}
	if (b->next->val == i)
		ret = 0;
	else
		ret = 1;
	while (k > 1)
	{
		b = b->prev;
		k--;
	}
	return (ret);
}

int	check_sort(int r, t_element *temp)
{
	while (r > 1)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
		r--;
	}
	return (1);
}

void	find_maxmin(int r, t_element *a, int *max, int *min)
{
	int	val;

	val = a->val;
	*max = a->val;
	*min = a->val;
	while (r-- > 0)
	{
		if (a->val > *max)
			*max = a->val;
		if (a->val < *min)
			*min = a->val;
		a = a->next;
	}
}

void	sort_three(t_element **a)
{
	int	max;
	int	min;

	find_maxmin(3, *a, &max, &min);
	if ((*a)->val == min)
	{
		rab(a, "ra");
		sab(a, "sa");
		rrab(a, "rra");
	}
	else if ((*a)->next->val == min)
	{
		if ((*a)->val == max)
			rab(a, "ra");
		else
			sab(a, "sa");
	}
	else
	{
		if ((*a)->val == max)
			sab(a, "sa");
		rrab(a, "rra");
	}
}
