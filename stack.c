/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:32:14 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/31 21:49:13 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_list(int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	out->val = val;
	out->next = out;
	out->prev = out;
	return (out);
}

t_element	*new_node(t_element *dest, t_program *prgm, int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	prgm->len += 1;
	if (dest == NULL)
	{
		free(out);
		return (create_list(val));
	}
	out->val = val;
	out->prev = dest->prev;
	dest->prev->next = out;
	dest->prev = out;
	out->next = dest;
	return (dest);
}

int	prgm_error(t_program *prgm)
{
	if (prgm->empty == 1 && prgm->flag == 1)
		prgm->letter = 1;
	if (prgm->flag == 1 && prgm->pm_cnt == 1)
		prgm->letter = 1;
	prgm->empty = 0;
	if (prgm->pm_cnt > 1 || prgm->range == 1 || prgm->letter == 1)
		return (1);
	return (0);
}

t_element	*stack_init(int nb, char **arg, t_program *prgm)
{
	int			i;
	t_element	*a;
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	a = NULL;
	i = 1;
	while (i <= nb)
	{
		prgm->empty = 1;
		while (arg[i])
		{
			if (prgm->empty == 1 && *(arg[i]) == 0)
				prgm->letter = 1;
			temp->val = my_atoi(&arg[i], prgm);
			if (prgm_error(prgm) == 1)
				return (0);
			if (prgm->flag == 1)
				break ;
			a = new_node(a, prgm, temp->val);
		}
		i++;
	}
	free(temp);
	return (a);
}
