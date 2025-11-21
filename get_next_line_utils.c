/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:32:31 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/18 13:32:42 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_malloc(char *s1, char *s2)
{
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = ft_malloc(s1, s2);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	free (s1);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	str;

	str = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == str)
			return ((char *)s + i);
		i++;
	}
	if (str == '\0')
		return ((char *)(s + i));
	return (NULL);
}

