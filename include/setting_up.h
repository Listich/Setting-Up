/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** bsq.h
*/


#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <stddef.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <string.h>

typedef struct map {
    int height;
    int width;
    char **lines;
}map_t;

typedef struct position {
    int x;
    int y;
    char **lines;
}position_t;

typedef struct square {
    position_t *pos;
    int length;
}square_t;

void display_unit(map_t *map, square_t *square, int i, int j);
void display_lines(map_t *map, square_t *square);
int is_valid_sq(square_t *square);
int biggest_valid_sq(map_t *map, int x, int y);
void update_square(square_t *square, int length, int x, int y);
square_t *find_bsq(map_t *map);
#endif /*MY_H_*/
