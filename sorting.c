/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 03:46:20 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/05 10:10:27 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_place(t_list *stack, int min_node)
{
	int		move;

	move = 0;
	while (stack)
	{
		if (stack->index == min_node)
			break ;
		move++;
		stack = stack->next;
	}
	return (move);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	move;

	move = min_place(*stack_a, min_nbr_index(*stack_a, -1));
	if (move == 1)
		ra(stack_a, 0);
	else if (move == 2)
	{
		ra(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (move == 3)
	{
		rra(stack_a, 0);
		rra(stack_a, 0);
	}
	else if (move == 4)
		rra(stack_a, 0);
	pb(stack_a, stack_b, 0);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 0);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min_index;

	min_index = min_place(*stack_a, min_nbr_index(*stack_a, -1));
	if (min_index == 1)
		ra(stack_a, 0);
	else if (min_index == 2)
	{
		ra(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (min_index == 3)
		rra(stack_a, 0);
	pb(stack_a, stack_b, 0);
	sort_three(stack_a);
	pa(stack_a, stack_b, 0);
}

void	sort_three(t_list **stack_a)
{
	int		min;
	int		second_min;

	if (is_sorted(*stack_a))
		return ;
	min = min_nbr_index(*stack_a, -1);
	second_min = min_nbr_index(*stack_a, min);
	if ((*stack_a)->index == min)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if ((*stack_a)->index == second_min)
	{
		if ((*stack_a)->next->index == min)
			sa(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	else
	{
		ra(stack_a, 0);
		sort_three(stack_a);
	}
}

void	sort_it(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(stack_a, 0);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size <= 100)
		large_numbers(stack_a, stack_b, 16);
	else
		large_numbers(stack_a, stack_b, 36);
}
