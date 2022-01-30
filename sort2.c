/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:06 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/30 22:47:58 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_vars(t_swap *swap, int *set1, int *set2)
{
	*set1 = 0;
	*set2 = 0;
	swap->i = 0;
}

int	setting_b(int r, t_element **a, t_element **b, t_swap *swap)
{
	swap->flag = r_range(r, *b);
	if (r == 0)
		return (1);
	else if (r == 1)
	{
		pab(a, b, "pa");
		return (1);
	}
	return (0);
}

void	btoa(int r, t_element **a, t_element **b, t_swap *swap)
{
	int			rb_cnt;
	int			pa_cnt;

	set_vars(swap, &rb_cnt, &pa_cnt);
	if (setting_b(r, a, b, swap) == 1)
		return ;
	pivot_sort(swap->arr, &swap->p, r, *b);
	while (r-- > 0)
	{
		if ((*b)->val < swap->p)
		{
			rab(b, "rb");
			(rb_cnt)++;
		}
		else
		{
			pab(a, b, "pa");
			(pa_cnt)++;
		}
	}
	swap->i = rb_cnt;
	while ((swap->i)-- > 0 && swap->flag != 0)
		rrab(b, "rrb");
	atob(pa_cnt, a, b, swap);
	btoa(rb_cnt, a, b, swap);
}

int	setting_a(int r, t_element **a, t_swap *swap)
{
	swap->flag = r_range(r, *a);
	if (check_sort(r, *a) == 1)
		return (1);
	if (r == 2 && (*a)->val > (*a)->next->val)
	{
		sab(a, "sa");
		return (1);
	}
	else if (r == 3 && swap->flag == 0)
	{
		sort_three(a);
		return (1);
	}
	return (0);
}

void	atob(int r, t_element **a, t_element **b, t_swap *swap)
{
	int			ra_cnt;
	int			pb_cnt;

	set_vars(swap, &ra_cnt, &pb_cnt);
	if (setting_a(r, a, swap) == 1)
		return ;
	pivot_sort(swap->arr, &swap->p, r, *a);
	while (r-- > 0)
	{
		if ((*a)->val > swap->p)
		{
			rab(a, "ra");
			ra_cnt += 1;
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt += 1;
		}
	}
	swap->i = ra_cnt;
	while ((swap->i)-- > 0 && swap->flag != 0)
		rrab(a, "rra");
	atob(ra_cnt, a, b, swap);
	btoa(pb_cnt, a, b, swap);
}
