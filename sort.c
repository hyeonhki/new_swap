/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:34 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/27 19:31:50 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	r_range(int r, t_element **b)
{
	int	i;
	int	k;
	int	ret;

	

	k = 1;
	i = (*b)->prev->val;
	while (k++ < r)
		*b = (*b)->next;
	if (i == (*b)->val)
		ret = 0;
	else
		ret = 1;
	while (k-- > 2)
		*b = (*b)->prev;
	return (ret);
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

//	printf("check\n");
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
		{
			sab(a, "sa");
			rrab(a, "rra");
		}
		else
			rrab(a, "rra");
	}
}

void	btoa(int r, int flag, t_element **a, t_element **b)
{
	int	p;
	int	i;
	int	rb_cnt;
	int	pa_cnt;

//	printf("a->prev %d\n",(*a)->prev->val);
//	flag = 1;
	if (r == 0)
		return ;
	if (r == 1)
	{
		pab(a, b, "pa");
		return ;
	}
	else if (r == 2)
	{
		pab(a, b, "pa");
		pab(a, b, "pa");
		if ((*a)->val > (*a)->next->val)
			sab(a, "sa");
		return ;
	}
	flag = r_range(r, b);
	rb_cnt = 0;
	pa_cnt = 0;
//	printf("a->prev %d\n",(*a)->prev->val);
	pivot_sort(&p, r, *b);
//	printf("p : %d\n",p);
//	p = pivot_sort(r, *b);
//	p = (*b)->val;
//	printf("a->prev %d\n",(*a)->prev->val);
	while (r-- > 0)
	{
		if ((*b)->val < p)
		{
			rab(b, "rb");
			rb_cnt++;
		}
		else
		{
//			printf("a->prev %d\n",(*a)->prev->val);
			pab(a, b, "pa");
			pa_cnt++;
		}
	//	check_stack(*a, *b);
	}
	i = rb_cnt;
	while (i-- > 0 && flag != 0)
		rrab(b, "rrb");
//	printf("pa %d rb %d\n",pa_cnt,rb_cnt);
//	check_stack(*a, *b);
//	if (rb_cnt == 0)
	//	sab(a, "sa");
//	check_stack(*a, *b);
	atob(pa_cnt, flag, a, b);
	btoa(rb_cnt, flag, a, b);
}


void	atob(int r, int flag, t_element **a, t_element **b)
{
	int	p;
	int	i;
	int	ra_cnt;
	int	pb_cnt;

	if (r == 0)
		return ;
	if (check_sort(r, *a) == 1)
		return ;
	if (r == 2 && (*a)->val > (*a)->next->val)
		return (sab(a, "sa"));
	flag = r_range(r, a);
	if (r == 3 && flag == 0)
		return (sort_three(a));
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
//	printf("check\n");
//	p = (*a)->val;
	pivot_sort(&p, r, *a);
	while (r-- > 0)
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
	}
//	check_stack(*a, *b);
	i = ra_cnt;
	while (i-- > 0 && flag != 0)
		rrab(a, "rra");
//	printf("ra %d pb %d\n",ra_cnt,pb_cnt);
//	printf("a->prev %d\n",(*a)->prev->val);
//	check_stack(*a, *b);
	atob(ra_cnt, flag, a, b);
	btoa(pb_cnt, flag, a, b);
}
