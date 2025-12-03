/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:32:31 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/18 13:32:42 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	ft_lenjoin(char *dst, const char *s1, const char *s2, size_t len1)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	len2;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len + len2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	ft_lenjoin(str, s1, s2, len);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	str;

	if (!s)
		return (NULL);
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
