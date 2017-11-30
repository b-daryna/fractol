/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:54:01 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 15:15:47 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char **dst, char *src)
{
	char	*str;
	size_t	len;

	len = ft_strlen(*dst) + ft_strlen(src);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strcpy(str, *dst);
	ft_strcat(str, src);
	free(*dst);
	*dst = str;
	return (*dst);
}

static int	ft_pos(char *s, char c, int *i)
{
	while (s[*i] != 0)
	{
		if (s[*i] == c)
			return (*i);
		(*i)++;
	}
	return (-1);
}

static int	ft_read(const int fd, char *buf, char *trash, char **line)
{
	int		cnt;
	int		p;
	int		len;

	while ((cnt = read(fd, buf, BUFF_SIZE)))
	{
		len = 0;
		p = ft_pos(buf, '\n', &len);
		buf[cnt] = 0;
		if (p >= 0)
		{
			if (cnt > p + 1)
				ft_strcpy(trash, buf + p + 1);
			buf[p] = 0;
			ft_join(line, buf);
			return (1);
		}
		ft_join(line, buf);
		if (cnt < BUFF_SIZE)
			return (1);
	}
	free(buf);
	return (0);
}

static int	get_data_from_trash(char *trash, int *len, char **line)
{
	int	p;

	if (trash[0])
	{
		p = ft_pos(trash, '\n', len);
		if (p >= 0)
		{
			*line = ft_strnew(p);
			ft_strncpy(*line, trash, p);
			ft_strcpy(trash, trash + p + 1);
			return (1);
		}
		*line = ft_strnew(*len);
		ft_strcpy(*line, trash);
		trash[0] = 0;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			len;
	static char trash[BUFF_SIZE];
	char		*buf;

	len = 0;
	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	if (get_data_from_trash(trash, &len, line))
		return (1);
	else
		*line = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	if (ft_read(fd, buf, trash, line) == 1)
	{
		free(buf);
		return (1);
	}
	if (*line[0])
	{
		free(buf);
		return (1);
	}
	return (0);
}
