/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:44:55 by eadam             #+#    #+#             */
/*   Updated: 2026/09/10 23:44:56 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bsq.h"

void	fill_square(t_map *map, t_square square)
{
	int	start_row;
	int	start_col;
	int	row;
	int	col;

	if (square.size <= 0)
		return ;
	start_row = square.row - square.size + 1;
	start_col = square.col - square.size + 1;
	row = start_row;
	while (row <= square.row)
	{
		col = start_col;
		while (col <= square.col)
		{
			map->grid[row][col] = map->full;
			col++;
		}
		row++;
	}
}
