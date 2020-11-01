/* date = October 29th 2020 9:28 pm */

#ifndef GLOW_H
#define GLOW_H

#include "getwind.h"

typedef struct GLOW_GAME_STRUCT {
    float r;
	float g;
	float b;
	float a;
    
	char m_unk[4];
	float m_flUnk;
	float m_flBloomAmount; //1 max
	float m_flUnk1;
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloomRender; //outline or inline
	char m_unk1;
	int m_nFullBloomStencilTestValue;
	int m_nGlowStyle; //3 - flicker, 2 - inline glow , 1 - inline+flicker, 0 - full body glow
} Glow_game;

typedef struct GLOW_STRUCT {
    DWORD local_player;
    int local_team;
	DWORD glow_obj;
	DWORD entity;
	int health;
	bool dormant;
    int glow_index;
    int entity_team;
} Glow;

Glow_game* glow_con(Glow_game* glow_g);

void glow_esp(Glow* glow,Glow_game* glow_g, Window* window, uintptr_t module_base);

#endif //GLOW_H
