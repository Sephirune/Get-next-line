/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:33:02 by aarogarc          #+#    #+#             */
/*   Updated: 2025/11/18 13:36:26 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 8

# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);







#endif
