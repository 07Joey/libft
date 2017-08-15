/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:36:13 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/23 14:28:15 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_to_array(int const fd, char **array)
{
	char	*buff;
	char	*tmp;
	int		val;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	val = read(fd, buff, BUFF_SIZE);
	if (val > 0)
	{
		buff[val] = '\0';
		tmp = ft_strjoin(*array, buff);
		free(*array);
		*array = tmp;
	}
	free(buff);
	return (val);
}

int				get_next_line(int const fd, char **line)
{
	static char	*array;
	char		*temp;
	int			val;

	array = NULL;
	if ((!array && (array = (char *)malloc(sizeof(*array))) == NULL)
			|| !line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	temp = ft_strchr(array, '\n');
	while (temp == NULL)
	{
		val = read_to_array(fd, &array);
		if (val == 0)
		{
			if (ft_strlen(array) == 0)
				return (0);
			array = ft_strjoin(array, "\n");
		}
		if (val < 0)
			return (-1);
		else
			temp = ft_strchr(array, '\n');
	}
	*line = ft_strsub(array, 0, ft_strlen(array) - ft_strlen(temp));
	array = ft_strdup(temp + 1);
	return (1);
}
