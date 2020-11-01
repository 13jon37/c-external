#include "include/getwind.h"

Window* init(const char* window_name)
{
    Window* window = calloc(1, sizeof(struct WINDOW_STRUCT));
    
    SetConsoleTitle("Antinous External");
    
    window->hwnd = FindWindowA(0, window_name);
    
    if (!window->hwnd)
    {
        printf("Window not found.\n");
        Sleep(1000);
        free(window);
        exit(1);
    }
    else
    {
        GetWindowThreadProcessId(window->hwnd, &window->proc_id);
        window->handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, window->proc_id);
        
        if (!window->handle)
        {
            printf("Could not get handle to process.\n");
            Sleep(1000);
            free(window);
            exit(1);
        }
        
    }
    return window;
}

uintptr_t get_module(Window* window, const char* mod_name)
{
    uintptr_t modBaseAddr = 0;
    
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, window->proc_id);
	if (handle != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 mod_entry;
		mod_entry.dwSize = sizeof(mod_entry);
		if (Module32First(handle, &mod_entry))
		{
			do
			{
				if (!strcmp(mod_entry.szModule, mod_name))
				{
					CloseHandle(handle);
					return (uintptr_t)mod_entry.modBaseAddr;
				}
			} while (Module32Next(handle, &mod_entry));
		}
	}
    return modBaseAddr;
}

void clean_up(Window* window)
{
    CloseHandle(window->handle);
    free(window);
}