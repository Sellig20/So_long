/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:40:17 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/09 15:15:58 by jecolmou         ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

//////////STRUCTURE//////////
typedef struct s_map	t_map;

struct s_map
{
	char	*x;
	t_map	*next;
};

typedef struct s_data	t_data;

struct	s_data
{
	int		file;
	char	*str;
	int		len;
	int		count_p;
	int		count_e;
	int		count_c;
	t_map	*map;
	void	*wall;
	void	*ground;
	void	*exit;
	void	*charac;
	void	*collectible;
	void	*mlx_ptr;
	void	*win_ptr;
};

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

//////////LINKED LISTS//////////
t_map	*ft_add_back(t_map *a_list, char *value);
int		ft_lstsize(t_map **lst);
void	ft_lstclear(t_map **tab);

//////////GET_NEXT_LINE//////////
int		ft_strlen_gnl(char *str);
int		ft_read_buffer(int fd, char *buf);
int		ft_is_a_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd, int reset);
char	*ft_read_text(int fd, char *final);
char	*ft_extract_line(char *s1);
char	*ft_save_line(char *str);

//////////PARSING//////////
int		ft_check_args(int argc, char **argv);
int		ft_open_map(char **argv, t_data *x);
int		ft_read_infile(char *infile);
int		ft_return_count_p(t_data *x);
int		ft_return_count_e(t_data *x);
int		ft_return_count_c(t_data *x);
int		ft_check(t_map **liste);
int		ft_check_doublons_p(t_map **liste);
int		ft_parsing_map_e(t_map **tab, t_data *x, char *c);
int		ft_parsing_map_p(t_map **map, t_data *x, char *c);
int		ft_parsing_map_c(t_map **tab, t_data *x, char *c);
int		ft_is_rectangle(t_map **tab);
int		ft_is_wall_first(t_map **first);
int		ft_is_wall_last(t_map **tab);
int		ft_is_wall_first_case(t_map **tab);
int		ft_is_wall_last_case(t_map **tab);
void	ft_execution_parsing_items(t_map **tab, t_data *x);
void	ft_execution_rectangle(t_map **tab);
void	ft_execution_wall(t_map **tab);

//////////SO_LONG//////////
void	ft_free_args(char	**args);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *x);
int		handle_keypress(int keysym, t_data *x);
int		handle_keyrelease(int keysym, void *data);
int		render(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);

void	display_map(t_data *data, int i, int j);
int	ft_get_images(t_data *data);
t_data	create(t_data *data);


#endif
