/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:58:53 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/22 13:28:15 by hyeonhki         ###   ########.fr       */
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

/*
t_element   *del_top2(t_element **head)
{
    t_element   *removed;

    if (*head == NULL)
        return NULL;
    removed = *head;
    if (*head == (*head)->next)
    {
        (*head)->next = NULL;
        (*head)->prev = NULL;
        *head = NULL;
        return removed;
    }
    (*head)->prev->next = (*head)->next;
    (*head)->next->prev= (*head)->prev;
    (*head) = (*head)->next;
    return removed;
}

t_element   *push2(t_element *ab, t_element *ba)
{
    if (ab == NULL)
    {
        ba->next = ba;
        ba->prev = ba;  
    }
    else
    {
        ba->next = ab;
        ba->prev = ab->prev;
        ab->prev->next = ba;
        ab->prev = ba;
    }
    return ba;
}

void	pab(t_element **ab, t_element **ba, char *com)
{
	t_element   *tem;
    if (*ba == NULL)
        return ;
    tem = del_top2(ba);
    *ab = push2(*ab, tem);
	check_stack(*ab, *ba);
    my_putstr(com);
}
*/


void	pab(t_element **b, t_element **a, char *com) //pb 기준
{
	t_element *temp;

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
		(*b) = (*a);
		(*a) = temp;
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*a)->next = *b;
		(*b)->prev->next = (*a);
		(*b)->prev = (*a);
		(*b) = (*a);
		(*a) = temp;
	}
	my_putstr(com);
}

void	pa(t_element **a, t_element **b, char *com)
{
	t_element *temp;

	if (*b == NULL)
		return ;
	(*b)->next->prev = (*b)->prev;
	(*b)->prev->next = (*b)->next;
	temp = (*b)->next;
	if ((*b)->next->val == (*b)->val)
		temp = NULL;
	if (*a == NULL)
	{
		(*b)->prev = (*b);
		(*b)->next = (*b);
		(*a) = (*b);
		(*b) = temp;
	}
	else
	{
		(*b)->prev = (*a)->prev;
		(*b)->next = *a;
		(*a)->prev->next = (*b);
		(*a)->prev = (*b);

		(*a) = (*b);
		(*b) = temp;
	}
	my_putstr(com);
}