/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:15 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/30 15:50:41 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_theline(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = get_strlen(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	str_cpy(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buffer)
{
	t_list	*newnode;
	t_list	*lastnode;

	lastnode = find_lastnode(*list);
	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!lastnode)
		*list = newnode;
	else
		lastnode->next = newnode;
	newnode->str_buffer = buffer;
	newnode->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		read_char;

	while (!get_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (!read_char)
		{
			free(buffer);
			return ;
		}
		buffer[read_char] = '\0';
		append(list, buffer);
	}
}

void	clear_list(t_list **list)
{
	t_list	*cleannode;
	t_list	*lastnode;
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	lastnode = find_lastnode(*list);
	cleannode = malloc(sizeof(t_list));
	if (!cleannode || !buffer)
		return ;
	while (lastnode->str_buffer[i] != '\n' && lastnode->str_buffer[i])
		i++;
	if (lastnode->str_buffer[i] == '\n')
		i++;
	while (lastnode->str_buffer[i])
		buffer[j++] = lastnode->str_buffer[i++];
	buffer[j] = '\0';
	cleannode->str_buffer = buffer;
	cleannode->next = NULL;
	dealloc(list, cleannode, buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_theline(list);
	clear_list(&list);
	return (next_line);
}
