/*
** EPITECH PROJECT, 2020
** BSQ OPTION
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/my.h"
#include "include/bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void analyse_file(file_t *file)
{
    for (int i = 0; i < file->size; i++) {
        if (file->content[i] == '.' || file->content[i] == '\n') {
            if (file->content[i] == '\n')
                continue;
            else
                file->content[i] = 'x';
        } else if (file->content[i] == 'o') {
            my_putstr("This project cannot analyse this file.");
            exit(84);
        }
    }
    my_putstr(file->content);
}

void set_height(file_t *file)
{
	int height = 0;
	char c;

	for (int i = 0; i < file->size; i++) {
		c = file->content[i];
		if (c >= '0' && c <= '9') {
			height *= 10;
			height += c - '0';
		} else
			break;
	}
	file->height = height;
}

void set_width(file_t *file)
{
	int width = 0;
	int status = 0;
	char c;

	for (int i = 0; i < file->size; i++) {
		c = file->content[i];
		if (status == 0 && c != '\n')
			continue;
		if (status == 0) {
			status = status + 1;
			continue;
		}
		if (status == 1 && c == '\n')
			status = status + 1;
		if (status == 1)
			width = width + 1;
	}
	file->width = width;
}

void get_file(file_t *file)
{
	struct stat info;
	stat(file->path_file, &info);
	int fd = open(file->path_file, O_RDONLY);
	char *buff;
	int offset = 0;

	file->size = info.st_size;
	buff = malloc(sizeof(char) * file->size);
	while (read(fd, buff + offset, 4096) > 0)
		offset += 4096;
	close(fd);
	file->content = buff;
}

void load_file(file_t *file)
{
    get_file(file);
    set_width(file);
    set_height(file);
}