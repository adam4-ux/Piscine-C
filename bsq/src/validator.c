/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:10 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/02 19:06:16 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	valid_cell(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle);
}

int	validate_one_row(char *content, int *pos, t_map *map)
{
	int	col;

	col = 0;
	while (content[*pos] && content[*pos] != '\n')
	{
		if (!valid_cell(content[*pos], map) || col >= map->cols)
			return (0);
		col++;
		(*pos)++;
	}
	if (col != map->cols || content[*pos] != '\n')
		return (0);
	(*pos)++;
	return (1);
}

int	validate_map_body(char *content, int start, int size, t_map *map)
{
	int	row;
	int	pos;

	if (start >= size)
		return (0);
	map->cols = count_map_columns(content, start, size);
	if (map->cols <= 0)
		return (0);
	row = 0;
	pos = start;
	while (row < map->rows)
	{
		if (!validate_one_row(content, &pos, map))
			return (0);
		row++;
	}
	return (pos == size);
}
