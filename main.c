/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** NO DESCRIPTION FOUND
*/

#include "include/bsq.h"

int main(int ac, char **argv)
{
    ac = ac;
    file_t file;
    file.path_file = argv[1];

    load_file(&file);
    analyse_file(&file);
}