/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:34:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/22 23:29:33 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_makeline_saverest(char **leftover, char **line)
{
	char			*new_leftover;
	int				symb_qty;

	symb_qty = 0;
	while ((*leftover)[symb_qty] != '\n' && (*leftover)[symb_qty] != '\0')
		symb_qty++;
	if ((*leftover)[symb_qty] == '\n')
	{
		if (!(*line = (char *)malloc((symb_qty + 1))))
			return (-1);
		*line = ft_strncpy(*line, *leftover, symb_qty);
		new_leftover = ft_substr(*leftover, symb_qty + 1,
			(ft_strlen(*leftover) - symb_qty - 1));
		free(*leftover);
		*leftover = NULL;
		*leftover = new_leftover;
		return (1);
	}
	return (0);
}

int					ft_itt_check(int read_len, char **leftover,
						char **line, char *buff)
{
	char			*tmp;

	if (read_len == 0)
	{
		if (!(*line = ft_strjoin(*leftover, "")))
			return (-1);
		free(*leftover);
		*leftover = NULL;
	}
	if (!(*leftover) && read_len > 0)
	{
		if (!(*leftover = ft_strjoin(buff, "")))
			return (-1);
	}
	else if (read_len > 0)
	{
		tmp = *leftover;
		if (!(*leftover = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int					ft_get_line(int *fd, char **leftover, char **line)
{
	char			*buff;
	int				i;
	int				read_len;

	read_len = 1;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (read_len > 0)
	{
		if ((*leftover) && (i = ft_makeline_saverest(&(*leftover), line)) > 0)
		{
			free(buff);
			buff = NULL;
			return (i);
		}
		if ((read_len = read(*fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[read_len] = '\0';
		ft_itt_check(read_len, &(*leftover), line, buff);
	}
	free(buff);
	buff = NULL;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static t_fd_lst	*fd_lst;
	t_fd_lst		*fd_tmp;
	int				result;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_lst)
		if (!(fd_lst = ft_lstadd(fd)))
			return (-1);
	fd_tmp = fd_lst;
	while (fd_tmp && fd_tmp->fd != fd)
	{
		if (!fd_tmp->next)
			if (!(fd_tmp->next = ft_lstadd(fd)))
				return (-1);
		fd_tmp = fd_tmp->next;
	}
	result = ft_get_line(&fd_tmp->fd, &fd_tmp->leftover, line);
	if (result == 0)
	{
		free(fd_lst);
		fd_lst = NULL;
	}
	return (result);
}
