/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:12:09 by carmarqu          #+#    #+#             */
/*   Updated: 2024/04/16 13:51:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *str, char c)//talvez precisa ser um int
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_strcpy(char *og, char *dest)
{
    int i;

    i = 0;
    while (og[i])
    {
        dest[i] = og[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strdup(char *src, char *dest)
{
    int i;

    i = 0;
    dest = (char *)malloc(ft_strlen(src) + 1);
    if (!dest)
        return (0);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(char *src, char *dest)
{
    char *final;
    int i;
    int x;

    x = 0;
    i = 0;
    final = malloc((ft_strlen(src) + ft_strlen(dest)) + 1);
    if (!src || !dest)
        return (NULL);
    if (!final)
        return (NULL);
    while (src[i])
    {
        final[i] = src[i];
        i++;
    }
    while (dest[x])
    {
        final[i] = dest[x];
        i++;
        x++;
    }
    final[i] = '\0';
    free(src);
    return (final);
}

char *get_next_line (int fd)
{
    static char buff[BUFFER_SIZE + 1];
    char *all;
    char *line;
    int line_end;
    int bt_read;

    line = ft_strdup(line, buff);
    while (!(all = ft_strchr(line, '\n')) && (bt_read = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[BUFFER_SIZE] = '\0';
        line = ft_strjoin(line, buff);
    }
    if (ft_strlen(line) == 0)
        return (free(line), 0);
    if (all != NULL)
    {
        line_end = (ft_strlen(all) - ft_strlen(line)) + 1;
        ft_strcpy(buff, all);
    }
    else
    {
        line_end = ft_strlen(line);
        buff[0] = '\0';
    }
    line[line_end] = '\0';
    return (line);   
}