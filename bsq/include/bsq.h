/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:19 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:49 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

typedef struct s_map
{
	int				rows;
	int				cols;
	char			empty;
	char			obstacle;
	char			full;
	char			**grid;
}					t_map;

typedef struct s_square
{
	int				size;
	int				row;
	int				col;
}					t_square;

typedef struct s_chunk
{
	char			data[BUFFER_SIZE];
	int				size;
	struct s_chunk	*next;
}					t_chunk;

char				*read_all(int fd, int *size);
int					read_chunk(t_chunk **head, t_chunk **tail, int fd,
						int *total);
char				*join_chunks(t_chunk *head, int total);
int					parse_map(char *content, int size, t_map *map);
int					find_header_end(char *content, int size);
int					allocate_grid(t_map *map);
void				copy_grid(char *content, int start, t_map *map);
int					parse_header(char *content, int header_len, t_map *map);
int					parse_number(char *str, int len, int *value);
int					count_map_columns(char *content, int start, int size);
int					validate_map_body(char *content, int start, int size,
						t_map *map);
int					valid_cell(char c, t_map *map);
int					validate_one_row(char *content, int *pos, t_map *map);
t_square			solve_map(t_map *map);
int					*new_dp_row(int cols);
void				update_best(t_square *best, int value, int row, int col);
int					cell_value(t_map *map, int row, int col, int **dp);
void				solve_rows(t_map *map, t_square *best, int **dp);
void				fill_square(t_map *map, t_square square);
void				print_map(t_map *map);
void				print_error(void);
void				free_map(t_map *map);
void				free_chunks(t_chunk *head);
int					ft_min3(int a, int b, int c);
int					is_printable(char c);
void				process_fd(int fd);
void				process_file(char *filename);

#endif
