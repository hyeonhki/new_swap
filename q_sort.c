/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:05:09 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/27 18:35:59 by hyeonhki         ###   ########.fr       */
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

void	pivot_sort(int *p, int r, t_element *a)
{
	int	i;
	int	j;
	int	*arr;
	int	cnt;

	i = a->val;
	j = 0;
	*p = 0;
	cnt = 0;
	arr = (int *)malloc(r * sizeof(int));
	while (1)
	{
		arr[j] = a->val;
		a = a->next;
		j++;
		if (a->next->val == i)
		{
			arr[j++] = a->val;
			break ;
		}
		cnt++;
	}
	while (cnt >= 0)
	{
		a = a->prev;
		cnt--;
	}
	q_sort(arr, 0, r - 1);
	*p = arr[r / 2];
//	free(arr);
//	arr = 0;
//	free(arr);
}
