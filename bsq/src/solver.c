/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:04 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:39 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	*new_dp_row(int cols)
{
	int	*row;
	int	i;

	row = malloc(sizeof(int) * cols);
	if (!row)
		return (NULL);
	i = 0;
	while (i < cols)
	{
		row[i] = 0;
		i++;
	}
	return (row);
}

void	update_best(t_square *best, int value, int row, int col)
{
	if (value > best->size)
	{
		best->size = value;
		best->row = row;
		best->col = col;
	}
}

int	cell_value(t_map *map, int row, int col, int **dp)
{
	if (map->grid[row][col] == map->obstacle)
		return (0);
	if (row == 0 || col == 0)
		return (1);
	return (1 + ft_min3(dp[0][col], dp[1][col - 1], dp[0][col - 1]));
}

void	solve_rows(t_map *map, t_square *best, int **dp)
{
	int	row;
	int	col;
	int	*temp;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			dp[1][col] = cell_value(map, row, col, dp);
			update_best(best, dp[1][col], row, col);
			col++;
		}
		temp = dp[0];
		dp[0] = dp[1];
		dp[1] = temp;
		row++;
	}
}

t_square	solve_map(t_map *map)
{
	t_square	best;
	int			*dp[2];

	best.size = 0;
	best.row = 0;
	best.col = 0;
	dp[0] = new_dp_row(map->cols);
	dp[1] = new_dp_row(map->cols);
	if (!dp[0] || !dp[1])
	{
		free(dp[0]);
		free(dp[1]);
		return (best);
	}
	solve_rows(map, &best, dp);
	free(dp[0]);
	free(dp[1]);
	return (best);
}
