#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	j = ft_strlen(s1);
	copy = malloc (j + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int ft_lstsize(t_list *begin_list)
{
    int     i;
    t_list  *current;
    
    if (!begin_list)
        return (0);
    
    i = 0;
    current = begin_list;
    while (current)
    {
        i++;
        current = current->next;
    }
    return (i);
}

t_list	*ft_lstnew(int content, int i)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return (0);
	s->number = content;
	s->index = i;
	s->next = NULL;
	return (s);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}