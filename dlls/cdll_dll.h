/***
*
*	Copyright (c) 1999, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
//
//  cdll_dll.h

// this file is included by both the game-dll and the client-dll,

#ifndef CDLL_DLL_H
#define CDLL_DLL_H

#define MAX_WEAPONS		32		// ???

#define MAX_WEAPON_SLOTS		5	// hud item selection slots
#define MAX_ITEM_TYPES			6	// hud item selection slots

#define MAX_ITEMS				5	// hard coded item types

#define	HIDEHUD_WEAPONS		( 1<<0 )
#define	HIDEHUD_FLASHLIGHT	( 1<<1 )
#define	HIDEHUD_ALL			( 1<<2 )
#define 	HIDEHUD_HEALTH		( 1<<3 )

#define	MAX_AMMO_TYPES	32		// ???
#define MAX_AMMO_SLOTS  32		// not really slots

#define HUD_PRINTNOTIFY		1
#define HUD_PRINTCONSOLE	2
#define HUD_PRINTTALK		3
#define HUD_PRINTCENTER		4


#define WEAPON_SUIT			31

/*
#define WEAPON_CROWBAR          0
#define WEAPON_GLOCK            1
#define WEAPON_PYTHON           2
#define WEAPON_MP5              3
#define WEAPON_CHAINGUN         4
#define WEAPON_CROSSBOW         5
#define WEAPON_SHOTGUN          6
#define WEAPON_RPG              7
#define WEAPON_GAUSS            8
#define WEAPON_EGON             9
#define WEAPON_HORNETGUN        10
#define WEAPON_HANDGRENADE      11
#define WEAPON_TRIPMINE         12
#define WEAPON_SATCHEL          13
#define WEAPON_SNARK            14
*/
#define REGISTERED_WEAPONS  14 // counting from zero (without WEAPON_NONE)

#endif