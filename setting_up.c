/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** bsq.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "include/setting_up.h"


void display_unit(map_t *map, square_t *square, int i, int j)
{
    if (is_inside(square, i , j)){
        write(1, "x", sizeof(char));
    } else {
        write(1, &map->lines[i][j], sizeof(char));
    }
}

void display_lines(map_t *map, square_t *square)
{
    for (int i = 0; i < map->height ; i++) {
        for (int j = 0; j < map->width; j++) {
            display_unit(map, square, i, j);
        }
        write(1, "\n", sizeof(char));
    }
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    map_t *map = init_map(fd);
    square_t *square;

    square = find_bsq(map);
    display_lines(map, square);
    my_printf("%d\n", square->length);
    my_printf(" %d %d\n", square->pos->x, square->pos->y);
    free(map);
}
