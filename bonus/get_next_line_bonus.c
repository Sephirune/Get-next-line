/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:31:13 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/20 16:24:32 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_parse_line(char *aux)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (!aux || aux[0] == '\0')
		return (NULL);
	while (aux[i] && aux[i] != '\n')
		i++;
	line = malloc((i + (aux[i] == '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = aux[j];
		j++;
	}
	if (aux[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_update_line(char *upi)
{
	int		i;
	char	*new_line;
	int		j;
	int		k;

	if (!upi)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(upi) - i;
	while (upi[i] && upi[i] != '\n')
		i++;
	if (!upi[i])
		return (free(upi), NULL);
	i++;
	if (k == 0)
		return (free(upi), NULL);
	new_line = malloc((k + 1) * sizeof(char));
	if (!new_line)
		return (free(upi), NULL);
	while (j < k)
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
	while ((!aux || !ft_strchr(aux, '\n')) && r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (free(buff), free(aux), NULL);
		buff[r] = '\0';
		aux = ft_strjoin(aux, buff);
		if (!aux)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buff[FOPEN_MAX];
	char		*helpy;

	if (!buff[fd])
		buff[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	buff[fd] = ft_read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	helpy = ft_parse_line(buff[fd]);
	buff[fd] = ft_update_line(buff[fd]);
	return (helpy);
}

/*int main(int argc, char **argv)
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
}*/
