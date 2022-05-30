/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:07:37 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/30 18:09:59 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*ft_add_back(t_map *a_list, char *value)
{
	t_map	*a;
	t_map	*tmp;

	a = malloc(sizeof(t_map) + 1);
	tmp = NULL;
	tmp = a_list;
	if (a != NULL)
	{
		a->map = value;
		a->next = NULL;
	}
	if (!tmp)
		a_list = a;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
	return (a_list);
}
