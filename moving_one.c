/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:52:31 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/14 16:52:33 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int i)
{
	t_list	*p;

	if (!(*stack_a))
		return ;
	else if ((*stack_a)->next == NULL)
		return ;
	p = *stack_a;
	*stack_a = (*stack_a)->next;
	p->next = (*stack_a)->next;
	(*stack_a)->next = p;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*j;

	if (!(*stack_b))
		return ;
	j = *stack_b;
	*stack_b = (*stack_b)->next;
	j->next = NULL;
	ft_lstadd_front(stack_a, j);
	if (i == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*p;

	if (!(*stack_a))
		return ;
	p = *stack_a;
	*stack_a = (*stack_a)->next;
	p->next = NULL;
	ft_lstadd_front(stack_b, p);
	if (i == 0)
		write(1, "pb\n", 3);
}
