/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:06 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/27 19:49:42 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_to_B(int r, int *flag, t_element **a, t_element **b);
void	B_to_A(int r, int *flag, t_element **a, t_element **b);
void	change_pivot(int r, int *p, t_element **ab, char flag);

void	change_pivot(int r, int *p, t_element **ab, char flag)
{
	t_element *temp;
	int i;

	i = r;
	temp = *ab;
	while (i - 1 > 0)
	{
		temp = temp->next;
		i--;
	}
	if (temp->val != (*ab)->prev->val)
		return ;
	while (i++ <= r)
		temp = temp->prev;
	if (flag == 'a')
		rab(ab, "ra");
	if (flag == 'b')
		rab(ab, "rb");
	*p = (*ab)->prev->val;
}


void	sort_three_flag(t_element **a)
{
	int	max;
	int	min;
	
	find_maxmin(3, *a, &max, &min);
	if ((*a)->val == min)
	{
		rab(a, "ra");
		sab(a, "sa");
		rrab(a, "rra");
		return ;
	}
	else if ((*a)->next->val != max)
	sab(a, "sa");
	rab(a, "ra");
	sab(a, "sa");
	rrab(a, "rra");
	if ((*a)->val != min)
		sab(a, "sa");
}


int	get_pivot(int r, t_element *a)
{
	int i;
	int p;
	int cnt;
	t_element	*temp;
	t_element	*temp2;

	temp = a;
	temp2 = a;
	p = temp->val;
	cnt = 0;
	i = 0;
	while (i < r || i < 10)
	{
		if (p < temp->val)
			cnt += 1;
		if (cnt == 2)
			return (p);
		temp = temp->next;
		i++;
	}
	return (p);
}

int	r_range2(int r, t_element *b)
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

void	B_to_A(int r, int *flag, t_element **a, t_element **b)
{
	int p;
	int i;
	int rb_cnt;
	int pa_cnt;
	t_element *temp;

	if (r == 0)
		return ;
	else if (r == 1)
	{
		pab(a, b, "pa");
		return ;
	}
	*flag = r_range2(r, *b);
	temp = *b;
	rb_cnt = 0;
	pa_cnt = 0;
	i = r - 1;
	while (i-- > 0)
		temp = temp->next;	
	p = (*b)->val; //피봇 맨앞으로 옮김
//	printf("r %d p %d\n",r,p);
//	printf("B - p %d\n",p);
//	if ((*b)->val < p)
//		change_pivot(r, &p, b, 'b');
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
//	printf("check\n");
	*flag = 1;
//	check_stack(*a, *b);
	A_to_B(pa_cnt, flag, a, b);
	B_to_A(rb_cnt, flag, a, b);
}

void	A_to_B(int r, int *flag, t_element **a, t_element **b)
{
	int p;
	int i;
	int ra_cnt;
	int pb_cnt;

	if (r == 0)
		return ;
	*flag = r_range2(r, *a);
	if (check_sort(r, *a) == 1)
		return ;
	else if (r == 2 && (*a)->val > (*a)->next->val)
	{
		if ((*a)->val > (*a)->next->val)
			sab(a, "sa");
		return ;
	}
	else if (r == 3)
	{
		if (*flag == 0)
			return (sort_three(a));
//		else
//			return (sort_three_flag(a));
	}
	ra_cnt = 0;
	pb_cnt = 0;
//	p = (*a)->val; //피봇 맨앞으로 옮김
//	pivot_sort(&p, r, *a);
	p = get_pivot(r, *a);
	i = r;
//	printf("r %d p %d\n",r,p);
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
//	if (pb_cnt == 0)
//			*a = sab(a, "sa");
	i = ra_cnt;
//	if (ra_cnt > 1 && j + 1 != ra_cnt)
		while (i-- > 0 && *flag != 0)
			rrab(a, "rra");
//	check_stack(*a, *b);
	A_to_B(ra_cnt, flag, a, b); //마지막자리 피봇을 ra 안해주기로 했기에 + 1
	B_to_A(pb_cnt, flag, a, b);
}