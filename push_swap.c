/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:54:36 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/16 00:46:44 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list	*s)
{
	while (s)
	{
		if (s->next && s->number > s->next->number)
			return (0);
		s = s->next;
	}
	return (1);
}

t_list	*make_stack(char **av)
{
	int		i;
	char	*str;
	t_list	*result;
	char	**tmp;

	i = 1;
	str = NULL;
	result = NULL;
	while (av[i])
	{
		str = ft_strjoin(str, av[i]);
		if (av[i + 1])
			str = ft_strjoin(str, " ");
		i++;
	}
	tmp = ft_split(str, ' ');
	if (!tmp)
	{
		free(str);
		return (NULL);
		
	}
	i = 0;
	while (tmp[i])
	{
		ft_lstadd_back(&result, ft_lstnew(ft_atoi(tmp[i]), -1));
		i++;
	}
	return (free(str), free_all(tmp), result);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ac > 1)
	{
		parsing(av);
		stack_a = make_stack(av);
		duplicated_check(stack_a);
		if (is_sorted(stack_a))
			return (free_stack(stack_a), 0);
		sort_it(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
	}
}
