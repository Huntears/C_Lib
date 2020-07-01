/*
** C_Logger_Lib PROJECT, 2020
** init.c
** File description:
** Ctor/Dtor of logger
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "logger/logger.h"
#include "task_listener.h"

task_listener_t *create_task_listener(char *file_path, logger_t *logger)
{
    task_listener_t *task_l = NULL;

    if (file_path == NULL) {
        if (logger != NULL)
            log_msg(logger, WARN, asprinf("You need to prompt a task file\n"));
        return;
    }
    task_l = malloc(sizeof(*task_l));
    if (task_l != NULL)
        task_l->fd = open(file_path, (O_CREAT | O_RDWR | O_APPEND),
            (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    return (task_l);
}

void delete_task_listener(task_listener_t *task_l)
{
    if (task_l != NULL) {
        if (task_l->fd != -1)
            close(task_l->fd);
        free(task_l);
    }
    return;
}