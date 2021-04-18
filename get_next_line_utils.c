/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:35:01 by brattles          #+#    #+#             */
/*   Updated: 2021/01/22 23:23:34 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_lst			*ft_lstadd(int fd)
{
	t_fd_lst		*fd_lst;

	if (!(fd_lst = malloc(sizeof(t_fd_lst))))
		return (NULL);
	fd_lst->fd = fd;
	fd_lst->leftover = NULL;
	fd_lst->next = NULL;
	return (fd_lst);
}

int					ft_strlen(const char *s)
{
	int				len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char				*ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;

	i = 0;
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	int				i;
	int				j;
	int				len[2];

	i = 0;
	j = 0;
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	if (!(strjoin = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1))))
		return (NULL);
	while (s1 && i < len[0])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2 && j < len[1])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len[0] + len[1]] = '\0';
	return (strjoin);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		if (!(substr = (char *)malloc(1)))
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
