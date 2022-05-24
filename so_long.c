/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/24 13:56:46 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;

	if (argc != 2)
		return (write(2, "Error : invalid number of arguments.\n", 35));
	if (ft_read_infile(argv[1]) == 1)
		x.file = open(argv[1], O_RDONLY);
	printf("file = %d\n", x.file);
	return (0);
}
