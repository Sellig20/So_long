/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/04 17:01:53 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;

	// (void)argc;
	// (void)argv;
	// (void)x;
	// x.mlx_ptr = mlx_init();
	// if (x.mlx_ptr == NULL)
	// 	return (MLX_ERROR);
	// x.win_ptr = mlx_new_window(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window !");
	// if (x.win_ptr == NULL)
	// {
	// 	free(x.win_ptr);
	// 	return (MLX_ERROR);
	// }
	// mlx_loop_hook(x.mlx_ptr, &handle_no_event, &x);
	// mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	// mlx_hook(x.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &x);

	// mlx_loop(x.mlx_ptr);

	// mlx_destroy_display(x.mlx_ptr);
	// free(x.mlx_ptr);
	ft_check_args(argc, argv);
	ft_open_map(argv, &x);
	close(x.file);
	return (0);
}
