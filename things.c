/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:53:37 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/14 16:53:39 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Fatals(int i)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	exit (0);
}

void	free_stack(t_list *s)
{
	t_list	*p;

	while (s)
	{
		p = s->next;
		free(s);
		s = p;
	}
}

void	free_all(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_list	*next_to_last(t_list *lst)
{
	while (lst)
	{
		if (!lst->next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	min_nbr_index(t_list *stack, int in)
{
	int		min;
	int		index;

	index = 0;
	min = stack->number;
	normal_indexing(stack);
	while (stack)
	{
		if ((min > stack->number) && stack->index != in)
		{
			index = stack->index;
			min = stack->number;
		}
		stack = stack->next;
	}
	return (index);
}
