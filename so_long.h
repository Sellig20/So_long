/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:40:17 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/27 17:12:52 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

//////////STRUCTURE//////////
typedef struct s_data t_data;

struct	s_data
{
	int		file;
	char	*str;
	int		index_line;
};

//////////GET_NEXT_LINE//////////
int			ft_strlen_gnl(char *str);
int			ft_read_buffer(int fd, char *buf);
int			ft_is_a_line(char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*get_next_line(int fd, int reset);
char		*ft_read_text(int fd, char *final);
char		*ft_extract_line(char *s1);
char		*ft_save_line(char *str);

//////////SO_LONG//////////
int	ft_read_infile(char *infile);
int	ft_parsing_map(char	**map);

#endif
