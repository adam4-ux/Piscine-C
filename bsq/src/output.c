/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:58:53 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:27 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->rows)
	{
		write(1, map->grid[row], map->cols);
		write(1, "\n", 1);
		row++;
	}
}

void	print_error(void)
{
	write(1, "map error\n", 10);
}
