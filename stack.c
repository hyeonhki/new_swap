/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:32:14 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/30 20:45:22 by hyeonhki         ###   ########.fr       */
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

t_element	*new_node(t_element *dest, int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	if (dest == NULL)
	{
		free(out);
		return (create_list(val));
	}
	out->val = val;
	out->next = dest;
	out->prev = dest->prev;
	dest->prev->next = out;
	dest->prev = out;
	return (dest);
}

t_element	*stack_init(int nb, char **arg, t_program *prgm)
{
	int			i;
	t_element	*a;
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	a = NULL;
	i = 1;
	prgm->len = 0;
	while (i <= nb)
	{
		while (arg[i])
		{
			temp->val = my_atoi(&arg[i], prgm);
			if (prgm->pm_cnt > 1 || prgm->range == 1 || prgm->letter == 1)
				return (0);
			if (prgm->flag == 1)
				break ;
			a = new_node(a, temp->val);
			prgm->len += 1;
		}
		i++;
	}
	free(temp);
	return (a);
}
