/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:28:44 by zkharbac          #+#    #+#             */
/*   Updated: 2024/12/03 11:03:20 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h> 

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        i++;
    }
    return (i);
}
char *ft_strdup(const char *s1)
{
    int i;
    int j;
    char    *str;
    int length =ft_strlen(s1);
    i = 0;
    j=0;
    str =malloc(length+1);
    if(!str)
        return NULL;
    while(s1[i])
    {
        str[j]=s1[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return str;


}
char *ft_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2) return NULL; 
    if (!s1) return ft_strdup(s2);
    if (!s2) return ft_strdup(s1);

    int length = ft_strlen(s1) + ft_strlen(s2);
    char *res = malloc(length + 1);
    if (!res) return NULL;

    int i = 0, j = 0;
    while (s1[i]) {
        res[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return res;
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    int i;
    char   *str;
    int length;

    if (!s)
        return (NULL);
    length =ft_strlen(s);
    if(start >= length)
        return (ft_strdup(""));
    if(start +len >length)
        len = length - start;
    str =malloc (len+1);
    if(!str)
        return  (NULL);
    i = 0;
    while(i<len && s[start + i])
    {
        str[i]=s[start+i];
        i++;
    }
    str[i]='\0';
    return str;
}
char *ft_strchr(const char *s, int c)
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i]==c)
        {
            return (char * )&s[i];
        }
        i++;
    }
    return NULL;
    if (c=='\0')
    return (char * )&s[i];
    
}
