/*
** C_Lib PROJECT, 2020
** task_listener.h
** File description:
** Include file for task listener
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#ifndef TASK_LISTENER_H_
    #define TASK_LISTENER_H_

    typedef struct task_listener_s {
        int fd;
    } task_listener_t;

    int format_time(struct tm *time);

#endif
