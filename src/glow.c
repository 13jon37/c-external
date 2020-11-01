#include "include/glow.h"

/*Glow_game* glow_con(Glow_game* glow_g)
{
    glow_g = calloc(1, sizeof(struct GLOW_GAME_STRUCT));
    
    glow_g->r = 1.f;
    glow_g->g = 0.f;
    glow_g->b = 0.f;
    glow_g->a = 1.f;
    
	glow_g->m_flBloomAmount = 1.f; //1 max
    glow_g->m_bRenderWhenOccluded = true;
	glow_g->m_bRenderWhenUnoccluded = false;
	glow_g->m_bFullBloomRender = false; //outline or inline
	glow_g->m_nGlowStyle = 0;
    
    return glow_g;
}

void glow_esp(Glow* glow, Glow_game* glow_g, Window* window, uintptr_t module_base)
{
    glow->local_player = ReadProcessMemory(window->handle, (PVOID)module_base + 0xD3DD14, &glow->local_player, sizeof(glow->local_player), 0);
    
    glow->local_team = ReadProcessMemory(window->handle, (PVOID)glow->local_player + 0xF4, &glow->local_team, sizeof(glow->local_team), 0);
    
    glow->glow_obj = ReadProcessMemory(window->handle, (PVOID)module_base + 0x529A1D0, &glow->glow_obj, sizeof(glow->glow_obj), 0);
    
    for (size_t i = 1; i < 64; ++i)
    {
        glow->entity = ReadProcessMemory(window->handle, (PVOID)module_base + 0x4D5239C, &glow->entity, sizeof(glow->entity), 0);
        glow->health = ReadProcessMemory(window->handle, (PVOID)glow->entity + 0xB3E4, &glow->health, sizeof(glow->health), 0);
        if (glow->health < 0 || glow->health > 100) continue;
        
        glow->dormant = ReadProcessMemory(window->handle, (PVOID)glow->entity + 0xED, &glow->dormant, sizeof(glow->dormant), 0);
        if (glow->dormant) continue;
        
        if (glow->entity != 0)
        {
            glow->glow_index = ReadProcessMemory(window->handle, (PVOID)glow->entity + 0xED, &glow->glow_index, sizeof(glow->glow_index), 0);
            glow->entity_team = ReadProcessMemory(window->handle, (PVOID)glow->entity +  0xF4, &glow->entity_team, sizeof(glow->entity_team), 0);
            
            if (glow->local_team != glow->entity_team)
            {
                WriteProcessMemory(window->handle, (PVOID)glow->glow_obj + ((glow->glow_index * 0x38) + 0x4), &glow_g, sizeof(glow_g), 0);
            }
        }
    }
    
}*/