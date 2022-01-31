/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:05:09 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/31 16:24:25 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, int a, int b)
{
	int	temp;

	temp = *(arr + a);
	*(arr + a) = *(arr + b);
	*(arr + b) = temp;
}

int	partition(int *arr, int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return (high);
}

void	q_sort(int *arr, int left, int right)
{
	int	pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		q_sort(arr, left, pivot - 1);
		q_sort(arr, pivot + 1, right);
	}
}

void	pivot_sort(int *arr, int *p, int r, t_element *a)
{
	int	i;
	int	j;
	int	cnt;

	i = r;
	j = 0;
	*p = 0;
	cnt = 0;
	while (i-- > 0)
	{
		arr[j] = a->val;
		a = a->next;
		cnt++;
		j++;
	}
	while (cnt-- >= 0)
		a = a->prev;
	q_sort(arr, 0, r - 1);
	if (r == 5)
		*p = arr[1];
	else
		*p = arr[r / 2];
}
