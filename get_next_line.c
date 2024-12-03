/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:58:31 by zkharbac          #+#    #+#             */
/*   Updated: 2024/12/03 19:41:55 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *append_read(char **str, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int br;

    if (!str || fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    br = 1;
    while (br != 0 && (!*str || ft_strchr(*str, '\n') == NULL))
    {
        br = read(fd, buffer, BUFFER_SIZE);
        if (br < 0)
        {
            free(*str);
            return NULL;
        }
        buffer[br] = '\0';
        *str = ft_strjoin(*str, buffer);
        if (!*str)
            return NULL;
    }
    return (*str);
}

char *get_line(char *line)
{
    int i = 0;

    if (!line || ft_strlen(line) == 0)
        return NULL;

    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == '\n')
        i++;
    return ft_substr(line, 0, i);
}

char *rest_func(char *reminder)
{
    int i = 0, j = 0;
    char *temp;

    if (!reminder)
        return NULL;

    while (reminder[i] != '\n' && reminder[i] != '\0')
        i++;
    if (reminder[i] == '\n')
        i++;
    if (reminder[i] == '\0')
    {
        free(reminder);
        return NULL;
    }
    temp = malloc(ft_strlen(reminder) - i + 1);
    if (!temp)
        return NULL;
    while (reminder[i])
        temp[j++] = reminder[i++];
    temp[j] = '\0';
    free(reminder);
    return temp;
}

char *get_next_line(int fd)
{
    static char *reminder = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    reminder = append_read(&reminder, fd);
    if (!reminder)
        return NULL;

    line = get_line(reminder);
    reminder = rest_func(reminder);
    return line;
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
    printf("%s",line);
	free(line);
    
    return 0;
}
