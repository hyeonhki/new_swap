/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:06 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/29 01:16:44 by hyeonhki         ###   ########.fr       */
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

void	btoa(int r, int *flag, t_element **a, t_element **b, int arr[])
{
	int			p;
	int			i;
	int			rb_cnt;
	int			pa_cnt;

	if (r == 0)
		return ;
	else if (r == 1)
	{
		pab(a, b, "pa");
		return ;
	}
	*flag = r_range(r, *b);
	rb_cnt = 0;
	pa_cnt = 0;
	i = r - 1;
	pivot_sort(arr, &p, r, *b);
	while (r > 0)
	{
		if ((*b)->val < p)
		{
			rab(b, "rb");
			rb_cnt++;
		}
		else
		{
			pab(a, b, "pa");
			pa_cnt++;
		}
		r--;
	}
	i = rb_cnt;
	while (i-- > 0 && *flag != 0)
		rrab(b, "rrb");
	*flag = 1;
	atob(pa_cnt, flag, a, b, arr);
	btoa(rb_cnt, flag, a, b, arr);
}

void	atob(int r, int *flag, t_element **a, t_element **b, int arr[])
{
	int	p;
	int	i;
	int	ra_cnt;
	int	pb_cnt;

	if (r == 0)
		return ;
	if (check_sort(r, *a) == 1)
		return ;
	*flag = r_range(r, *a);
	if (r == 2 && (*a)->val > (*a)->next->val)
	{
		if ((*a)->val > (*a)->next->val)
			sab(a, "sa");
		return ;
	}
	else if (r == 3)
	{
		if (*flag == 0)
			return (sort_three(a));
	}
	ra_cnt = 0;
	pb_cnt = 0;
	pivot_sort(arr, &p, r, *a);
	i = r;
	while (i > 0)
	{
		if ((*a)->val > p)
		{
			rab(a, "ra");
			ra_cnt++;
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt++;
		}
		i--;
	}
	if (ra_cnt == 0)
		sab(b, "sb");
	i = ra_cnt;
	while (i-- > 0 && *flag != 0)
		rrab(a, "rra");
	atob(ra_cnt, flag, a, b, arr);
	btoa(pb_cnt, flag, a, b, arr);
}
