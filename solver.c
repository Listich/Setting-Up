/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** solver.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "include/setting_up.h"

int is_valid_sq(square_t *square)
{
    for (int i = square->pos->x; i < (square->pos->x + square->length); i++) {
        for (int j = square->pos->y; j <
        (square->pos->y + square->length); j++) {
            if (square->pos->lines[i][j] != '.') {
                return 0;
            }
        }
    }
    return 1;
}

int biggest_valid_sq(map_t *map, int x, int y)
{
    position_t pos = {
        .lines = map->lines, .x = x, .y = y,
    };
    square_t square = {
        .pos = &pos, .length = 0,
    };

    while (is_valid_sq(&square) &&
    is_inbound(map, x + square.length, y + square.length)) {
        square.length++;
    }
    return square.length -1;
}

void update_square(square_t *square, int length, int x, int y)
{
    if (length > square->length) {
        square->length = length;
        square->pos->x = x;
        square->pos->y = y;
    }
}

square_t *find_bsq(map_t *map)
{
    position_t *pos = malloc(sizeof(position_t));
    square_t *square;
    int current;

    pos->lines = map->lines;
    pos->x = -1;
    pos->y = -1;
    square = malloc(sizeof(square_t));
    square->pos = pos;
    square->length = 0;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            current = biggest_valid_sq(map, i, j);
            update_square(square, current, i, j);
        }
    }
    return square;
}
