/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:58:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:30 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_number(char *str, int len, int *value)
{
	long	number;
	int		i;

	if (len <= 0)
		return (0);
	number = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = number * 10 + str[i] - '0';
		if (number > 2147483647)
			return (0);
		i++;
	}
	if (number == 0)
		return (0);
	*value = number;
	return (1);
}

int	parse_header(char *content, int header_len, t_map *map)
{
	int	number_len;

	if (header_len < 4)
		return (0);
	number_len = header_len - 3;
	if (!parse_number(content, number_len, &map->rows))
		return (0);
	map->empty = content[number_len];
	map->obstacle = content[number_len + 1];
	map->full = content[number_len + 2];
	if (!is_printable(map->empty) || !is_printable(map->obstacle))
		return (0);
	if (!is_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full)
		return (0);
	if (map->obstacle == map->full)
		return (0);
	return (1);
}

int	count_map_columns(char *content, int start, int size)
{
	int	cols;

	cols = 0;
	while (start + cols < size && content[start + cols] != '\n')
		cols++;
	return (cols);
}
