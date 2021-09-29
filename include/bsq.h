/*
** EPITECH PROJECT, 2020
** Struct manager
** File description:
** NO DESCRIPTION FOUND
*/

#ifndef BSQ_H_
#define BSQ_H_

#define BUFF_SIZE 100000

typedef struct file_h {
    int width;
    int height;
    int size;
    char *path_file;
    char *content;
} file_t;

void analyse_file(file_t *file);
void set_height(file_t *file);
void set_width(file_t *file);
void get_file(file_t *file);
void load_file(file_t *file);

#endif /* !BSQ_H_ */
