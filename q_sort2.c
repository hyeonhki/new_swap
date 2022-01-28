/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:49:53 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/28 23:54:18 by hyeonhki         ###   ########.fr       */
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

void insertion_sort(int list[], int n){
  int i, j, key;

  // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
  for(i=1; i<n; i++){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
    // j 값은 음수가 아니어야 되고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
    for(j=i-1; j>=0 && list[j]>key; j--){
      list[j+1] = list[j]; // 레코드의 오른쪽으로 이동
    }

    list[j+1] = key;
  }
}

void	pivot_sort(int *p, int r, t_element *a)
{
	int	i;
	int	j;
	int	*arr;

	i = a->val;
	j = 0;
	arr = NULL;
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
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
	}
	a = a->next;
	q_sort(arr, 0, r - 1);
	*p = arr[r/2];
}

