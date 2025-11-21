/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:31:13 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/20 16:24:32 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_boole(char *aux)
{
	int	i;

	i = 0;
	if (aux[i] == '\n')
		return (1);
	else
		return(0);
}

char	*ft_parse_line(char *aux)
{
	int	i;
	char	*line;
	int	boole;
	int	j;
	
	i = 0;
	j = 0;
	boole = 0;
	if (!aux || aux[0] == '\0')
		return (NULL);
	while (aux[i] && aux[i] != '\n')
		i++;
	/* if (aux[i] == '\n')
		boole = 1;
	else
		boole = 0; */
	ft_boole(aux);
	line = malloc((i + boole + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (aux[j] && aux[j] != '\n')
	{
			line[j] = aux[j];
			j++;
	}
	if (aux[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_update_line(char *upi)
{
	int	i;
	int	j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!upi)
		return (NULL);
	while (upi[i] && upi[i] != '\n')
		i++;
	if (!upi[i])
	{
		free(upi);
		return (NULL);
	}
	new_line = malloc(((ft_strlen(upi) - i) + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	if (upi[i] == '\n')
		i++;
	while (upi[i])
		new_line[j++] = upi[i++];
	new_line[j] = '\0';
	free(upi);
	return (new_line);
}

static char	*ft_read_file(int fd, char *aux)
{
	char	*buff;
	int		r;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	while (!ft_strchr(aux, '\n') && r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		aux = ft_strjoin(aux, buff);
		if (!aux)
			return (NULL);
	}
	free(buff);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char        *helpy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
	{
		buff = malloc(sizeof(char));
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	buff = ft_read_file(fd, buff);
	if (!buff)
		return (NULL);
	helpy = ft_parse_line(buff);
	buff = ft_update_line(buff);
	return (helpy);
}


int main(int argc, char **argv)
{
	(void)argc;
	int   fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
