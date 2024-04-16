/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:12:09 by carmarqu          #+#    #+#             */
/*   Updated: 2024/04/16 14:51:37 by carmarqu         ###   ########.fr       */
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

char *ft_strdup(char *src)
{
    int i;
    char *dest;
    
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
    static char buff[BUFFER_SIZE + 1];//guarda o que é lido
    char *all; //guarda temporariamente o que há depois do '\n'
    char *line; //linha a ser devolvida 
    int line_end; //onde é o final da linha a ser devolvida
    int bt_read; // quantidade de bts lidos

    line = ft_strdup(buff); //coloca o que esté em buff para line
    while (!(all = ft_strchr(line, '\n')) && (bt_read = read(fd, buff, BUFFER_SIZE)) > 0)//enquanto n encontrar um salto de linha e tiver algo a ser lido (o que há depois do salto de linha é guardado em all)
    {
        buff[BUFFER_SIZE] = '\0';//adiciona um nulo ao final
        line = ft_strjoin(line, buff); //vai juntado tudo que for lido em line
    }
    if (ft_strlen(line) == 0)// se nao há nada em line
        return (free(line), NULL); //free de line e devolve 0
    if (all != NULL) // se há um \n
    {
        line_end = all - line + 1; //final igual o (tamanho de tudo - o tamanho da linha) + 1
        ft_strcpy(all + 1, buff);//atualiza o buff, copiando o que há depois do '\n' para buff
    }
    else
    {
        line_end = ft_strlen(line);//se nao houver \n copia tudo que tiver sido lido
        buff[0] = '\0';//free de buff
    }
    line[line_end] = '\0';//coloca um nulo ao final
    return (line);  //devolve line
}

int main ()
{
    int fd;
    char *line;
    
    fd = open("txt.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
}