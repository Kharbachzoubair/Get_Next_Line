/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:43:24 by zkharbac          #+#    #+#             */
/*   Updated: 2024/12/04 11:37:17 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif  
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


char *get_next_line(int fd);
int ft_strlen(const char *s);
char *ft_strdup(const char *s1);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_substr(const char *s, unsigned int start, size_t len);
char *ft_strchr(const char *s, int c);

#endif