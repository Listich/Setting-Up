/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** util.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "include/setting_up.h"

int read_int(int fd)
{
    int result = 0;
    char buffer = '\0';

    read(fd, &buffer, sizeof(buffer));
    while (buffer != '\n' && buffer != ' ') {
        result *= 10;
        result += buffer - 48;
        read(fd, &buffer, sizeof(buffer));
    }
    return result;
}

map_t *init_map(int fd)
{
    map_t *map = malloc(sizeof(map_t));

    map->height = read_int(fd);
    map->lines = malloc(sizeof(char *)* map->height);
    for (int i = 0; i < map->height; i++) {
        map->lines[i] = malloc(sizeof(char)*10000);
    }
    my_printf("%d\n", map->height);
    map->width = read_lines(fd, map);
    return map;
}

int read_lines(int fd, map_t *map)
{
    int width = 0;
    char buffer = '\0';
    int pos = 0;
    int r;

    for (int i = 0; i < map->height; i++) {
        buffer = '\0';
        pos = 0;
        r = read(fd, &buffer, sizeof(buffer));
        while (buffer != '\n' && buffer != ' ' && buffer != EOF && r != 0) {
            map->lines[i][pos] = buffer;
            pos++;
            r = read(fd, &buffer, sizeof(buffer));
        }
        width = pos;
    }
    return width;
}

int is_inbound(map_t *map, int x, int y)
{
    return x >= 0 && y >= 0 && x < map->height && y < map->width;
}

int is_inside(square_t *square, int x, int y)
{
    return (x >= square->pos->x && x <= (square->pos->x + square->length)) &&
    (y >= square->pos->y && y <= (square->pos->y + square->length));
}
