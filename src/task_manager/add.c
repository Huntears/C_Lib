/*
** C_Lib PROJECT, 2020
** add.c
** File description:
** This file contains all functions needed to add a task to my taskfile
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <time.h>
#include "logger/logger.h"
#include "constant.h"
#include "task_listener.h"

int new_task(task_listener_t *task_l, struct tm time, logger_t *logger)
{
    if (format_time(&time) == ERROR) {
        if (logger != NULL) {
            log_msg(logger, WARN, asprint(&logger->msg,
                "Given time is not valid."
                "Creation of new task has been aborted\n"));
        }
        return (ERROR);
    }
    // APPEND NEW();
    if (logger != NULL) {
        log_msg(logger, INFO, asprint(&logger->msg,
            "New task Created\n"));
    }
    return (SUCCESS);
}