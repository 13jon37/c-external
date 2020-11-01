/* date = October 28th 2020 5:40 pm */

#ifndef GETWIND_H
#define GETWIND_H

#include <Windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <TlHelp32.h>

typedef struct WINDOW_STRUCT {
    HWND hwnd;
    HANDLE handle;
    DWORD proc_id;
} Window;

Window* init(const char* window_name);

uintptr_t get_module(Window* window, const char* mod_name);

void clean_up(Window* window);

#endif //GETWIND_H
