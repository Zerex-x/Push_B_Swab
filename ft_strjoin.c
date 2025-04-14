#include "push_swap.h"

static char	*check_null(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;
	int		len;

	if (!s1 || !s2)
		return (check_null(s1, s2));
	i = 0;
	j = 0;
	len = ft_strlen (s1) + ft_strlen (s2);
	tab = malloc (len + 1);
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	free((void *)s1);
	return (tab);
}
