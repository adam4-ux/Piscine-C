/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:02 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:36 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_chunk(t_chunk **head, t_chunk **tail, int fd, int *total)
{
	t_chunk	*new;
	int		bytes;

	new = malloc(sizeof(t_chunk));
	if (!new)
		return (-1);
	bytes = read(fd, new->data, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(new);
		if (bytes < 0)
			return (-1);
		return (0);
	}
	new->size = bytes;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		(*tail)->next = new;
	*tail = new;
	*total += bytes;
	return (1);
}

char	*join_chunks(t_chunk *head, int total)
{
	char	*content;
	int		i;
	int		pos;

	content = malloc(total + 1);
	if (!content)
		return (NULL);
	pos = 0;
	while (head)
	{
		i = 0;
		while (i < head->size)
			content[pos++] = head->data[i++];
		head = head->next;
	}
	content[pos] = '\0';
	return (content);
}

char	*read_all(int fd, int *size)
{
	t_chunk	*head;
	t_chunk	*tail;
	char	*content;
	int		status;

	head = NULL;
	tail = NULL;
	*size = 0;
	status = 1;
	while (status == 1)
		status = read_chunk(&head, &tail, fd, size);
	if (status == -1)
	{
		free_chunks(head);
		return (NULL);
	}
	content = join_chunks(head, *size);
	free_chunks(head);
	return (content);
}
