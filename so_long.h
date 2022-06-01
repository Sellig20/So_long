/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:40:17 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/01 17:59:41 by jecolmou         ###   ########.fr       */
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
	int		len;
	int		count_p;
	int		count_e;
};

typedef struct s_map	t_map;

struct s_map
{
	char	*x;
	t_map	*next;
};

//////////LINKED LISTS//////////
t_map	*ft_add_back(t_map *a_list, char *value);
int		ft_lstsize(t_map **lst);

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
int	ft_parsing_map_p(t_map **map, t_data *x, char *c);
int ft_return_count_p(t_data *x);
int ft_return_count_e(t_data *x);
int	ft_check(t_map **liste);
int	ft_check_doublons_p(t_map **liste);
int	ft_parsing_map_e(t_map **tab, t_data *x, char *c);
int ft_is_rectangle(t_map **tab, t_data *x);

#endif
