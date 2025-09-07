// struct s_stock_str *ft_strs_to_tab(int ac, char **av);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

// for testing
void ft_show_tab(struct s_stock_str *par);
void ft_putchar(int num);
// for testing

int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i;

    t_stock_str *array;

    array = malloc(sizeof(t_stock_str) * (ac + 1));
    if (!array)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        array[i].str = malloc(ft_strlen(av[i]) + 1);
        if (array[i].str == NULL)
        {
            while (--i >= 0)
            {
                free(array[i].str);
                free(array[i].copy);
            }
            free(array);
            return (NULL);
        }
        array[i].copy = malloc(ft_strlen(av[i]) + 1);
        if (array[i].copy == NULL)
        {
            while (--i >= 0)
            {
                free(array[i].str);
                free(array[i].copy);
            }
            free(array);
            return (NULL);
        }
        i++;
    }
    array[i].str = malloc(1);
    if (array[i].str == NULL)
    {
        while (--i >= 0)
        {
            free(array[i].str);
            free(array[i].copy);
        }
        free(array);
        return (NULL);
    }
    array[i].copy = malloc(1);
    if (array[i].copy == NULL)
    {
        while (--i >= 0)
        {
            free(array[i].str);
            free(array[i].copy);
        }
        free(array);
        return (NULL);
    }

    i = 0;

    while (i < ac)
    {
        ft_strcpy(array[i].str, av[i]);
        ft_strcpy(array[i].copy, av[i]);
        array[i].size = ft_strlen(av[i]);
        i++;
    }
    array[i].str[0] = '0';
    array[i].copy[0] = '0';
    return (array);
}

int ft_strlen(char *str)
{
    int len = 0;
    int i;

    i = 0;

    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}

void ft_strcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main(void)
{
    int ac = 6;
    char *texts[6] = {"new", "sample", "text", "APPLE", "BANANA", "Growth begins where comfort ends, step into change"};
    t_stock_str *array = ft_strs_to_tab(ac, texts);
    ft_show_tab(array);
    return (0);
}
// for testing:

void ft_show_tab(struct s_stock_str *par)
{
    int j;

    while (par->str[0] != '0')
    {
        j = 0;
        while (par->str[j] != '\0')
        {
            write(1, &(par->str[j]), 1);
            j++;
        }
        write(1, "\n", 1);
        ft_putchar(par->size);
        write(1, "\n", 1);
        j = 0;
        while (par->copy[j] != '\0')
        {
            write(1, &(par->copy[j]), 1);
            j++;
        }
        write(1, "\n", 1);
        par++;
    }
}

void ft_putchar(int num)
{
    char c;
    if (num <= 9)
    {
        c = num + '0';
        write(1, &c, 1);
        return ;
    }
    else
    {
        ft_putchar(num / 10);
        c = (num % 10) + '0';
        write(1, &c, 1);
    }
}
