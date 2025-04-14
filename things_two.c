/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:53:47 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/14 16:53:49 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normal_indexing(t_list *s)
{
	int		i;

	i = 0;
	while (s)
	{
		s->index = i;
		i++;
		s = s->next;
	}
}

t_list	*min_node(t_list **stack)
{
	int			first_time;
	t_list		*p;
	t_list		*min;

	first_time = 1;
	p = *stack;
	min = NULL;
	while (p)
	{
		if ((p->index == -1) && (first_time || p->number < min->number))
		{
			min = p;
			first_time = 0;
		}
		p = p->next;
	}
	return (min);
}

void	index_by_ascending_order(t_list **s)
{
	int			i;
	t_list		*p;

	i = 0;
	p = min_node(s);
	while (p)
	{
		p->index = i++;
		p = min_node(s);
	}
}

void	free_stacks(t_list **a, t_list **b)
{
	if (*a)
	{
		free_stack(*a);
		*a = NULL;
	}
	if (*b)
	{
		free_stack(*b);
		*b = NULL;
	}
}
