/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:31:13 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/18 13:32:19 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
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

char	*get_next_line(int fd)
{
	static char	helpy;
	int	r;
	char	*str;
	char	*buff;
	
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	r = read(fd, buff, BUFFER_SIZE);
	if (!str || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		free(buff);
		return (NULL);
	}
	while (!ft_strchr(helpy, '\n') && r > 0)
	{
		if (r < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		helpy = ft_strjoin(helpy, buff);
	}
	free (buff);
	return (helpy);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
}
