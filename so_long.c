/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/07 18:41:17 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;

	(void)argc;
	(void)argv;
	(void)x;

	x.mlx_ptr = mlx_init();
	if (x.mlx_ptr == NULL)
		return (MLX_ERROR);
	x.win_ptr = mlx_new_window(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window !");
	if (x.win_ptr == NULL)
	{
		free(x.win_ptr);
		return (MLX_ERROR);
	}
	x.img.mlx_img = mlx_new_image(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	x.img.addr = mlx_get_data_addr(x.img.mlx_img, &x.img.bpp, &x.img.line_len, &x.img.endian);
	mlx_loop_hook(x.mlx_ptr, &render, &x);
	mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	mlx_loop(x.mlx_ptr);
	mlx_destroy_display(x.mlx_ptr);
	free(x.mlx_ptr);
	// ft_check_args(argc, argv);
	// ft_open_map(argv, &x);
	// close(x.file);
	return (0);
}
