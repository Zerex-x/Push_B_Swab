/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 04:01:30 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/06 07:56:14 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int i)
{
	t_list		*p;

	if (!(*stack_a))
		return ;
	else if ((*stack_a)->next == NULL)
		return ;
	p = *stack_a;
	ft_lstlast(*stack_a)->next = p;
	*stack_a = p->next;
	p->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int i)
{
	t_list		*p;

	if (!(*stack_b))
		return ;
	else if (!((*stack_b)->next))
		return ;
	p = *stack_b;
	ft_lstlast(*stack_b)->next = p;
	*stack_b = p->next;
	p->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rra(t_list **stack_a, int i)
{
	t_list		*j;
	t_list		*p;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	p = *stack_a;
	j = next_to_last(*stack_a);
	*stack_a = j->next;
	j->next->next = p;
	j->next = 0;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int i)
{
	t_list		*j;
	t_list		*p;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	p = *stack_b;
	j = next_to_last(*stack_b);
	*stack_b = j->next;
	j->next->next = p;
	j->next = 0;
	if (i == 0)
		write(1, "rrb\n", 4);
}
