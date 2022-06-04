/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:54:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/04 16:46:35 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_lstclear(t_map **tab)
{
	t_map	*map;

	map = *tab;
	while (*tab)
	{
		map = (*tab)->next;
		free((*tab)->x);
		free(*tab);
		*tab = map;
	}
}
