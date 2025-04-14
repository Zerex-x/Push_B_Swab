#include "push_swap.h"

int	max_nbr(t_list *stack)
{
	int		max;

	max = stack->number;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	return (max);
}

int	max_nbr_place(t_list *stack_b)
{
	int		i;
	int		max;

	i = 0;
	max = max_nbr(stack_b);
	while (stack_b)
	{
		if (stack_b->number == max)
			return (i);
		i++;
		stack_b = stack_b->next;
	}
	return (i);
}

void    sort_stack_b(t_list **stack_a, t_list **stack_b)
{
    int     size;
    int     max_pos;

    size = ft_lstsize(*stack_b) - 1;
    while (*stack_b)
    {
        if ((*stack_b)->index == size && size >= 0)
        {
            pa(stack_a, stack_b, 0);
            size--;
        }
        else
        {
            max_pos = max_nbr_place(*stack_b);
            if (max_pos <= size / 2)
                rb(stack_b, 0);
            else
                rrb(stack_b, 0);
        }
    }
}

int	if_bad_distribution(t_list *stack)
{
	t_list	*p;
	int		diff_count;
	int		diff;
	int		size;

	size = ft_lstsize(stack);
	diff_count = 0;
	p = stack;
	while (p && p->next)
	{
		diff = p->index - p->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			diff_count++;
		p = p->next;
	}
	if (diff_count * 10 >= size * 6)
		return (1);
	return (0);
}

void	large_numbers(t_list **stack_a, t_list **stack_b, int j)
{
	int		i;

	i = 0;
	index_by_ascending_order(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= i + j)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else if (if_bad_distribution(*stack_a))
			rra(stack_a, 0);
		else
			ra(stack_a, 0);
	}
	sort_stack_b(stack_a, stack_b);
}
