/* "Null Pointer" Mockup: VBJaEngine demo program
 *
 * Copyright (C) 2015 Christian Radke <chris@vr32.de>
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Stage.h>
#include <macros.h>
#include <PlatformerLevelState.h>
#include <Languages.h>
#include <VPUManager.h>

#include <objects.h>
#include <sound.h>
#include "stages/textures.h"


//---------------------------------------------------------------------------------------------------------
// 												DEFINES
//---------------------------------------------------------------------------------------------------------

#define LAYER_FOREGROUND	0
#define LAYER_BACKGROUND	39


//---------------------------------------------------------------------------------------------------------
// 												ASSETS
//---------------------------------------------------------------------------------------------------------
/* Don't forget to place the NULL markers at the end of each array. It's the only way the engine has to
 * know that it must stop reading the stage's/ui's textures and entities.
 */

PositionedEntityROMDef SCRAPYARD_FOREGROUND_1_MB_CHILDREN[] =
{
	{&COLLISION_2x28x48,    {FTOFIX19_13(-240), FTOFIX19_13(0),  FTOFIX19_13(0)}, NULL, NULL, NULL, false},
	{&COLLISION_64x1x8, 	{FTOFIX19_13(0),    FTOFIX19_13(93), FTOFIX19_13(0)}, NULL, NULL, NULL, false},
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef SCRAPYARD_FOREGROUND_2_MB_CHILDREN[] =
{
	{&COLLISION_2x28x48,    {FTOFIX19_13(232),  FTOFIX19_13(0),  FTOFIX19_13(0)}, NULL, NULL, NULL, false},
	{&COLLISION_64x1x8, 	{FTOFIX19_13(0),    FTOFIX19_13(93), FTOFIX19_13(0)}, NULL, NULL, NULL, false},
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef SCRAPYARD_BACKGROUND_1_MB_CHILDREN[] =
{
    {&LAMP_AG,                          {FTOFIX19_13(-104), FTOFIX19_13(8),  FTOFIX19_13(0)}, NULL, NULL, NULL, false},
    {&SCRAPYARD_BACKGROUND_S_PILLAR_IM, {FTOFIX19_13(-60),  FTOFIX19_13(39), FTOFIX19_13(-8)}, NULL, NULL, NULL, false},
    {&PIPE_IM,                          {FTOFIX19_13(12),   FTOFIX19_13(4),  FTOFIX19_13(-8)}, NULL, NULL, NULL, false},
    {&WATER_PS,                         {FTOFIX19_13(-24),  FTOFIX19_13(12),  FTOFIX19_13(-7.9f)}, NULL, NULL, NULL, false},
    {&WATER_PS,                     {FTOFIX19_13(-20),  FTOFIX19_13(12),  FTOFIX19_13(-7.9f)}, NULL, NULL, NULL, false},
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef SCRAPYARD_BACKGROUND_2_MB_CHILDREN[] =
{
    {&SCRAPYARD_BACKGROUND_S_PILLAR_IM, {FTOFIX19_13(-14), FTOFIX19_13(39), FTOFIX19_13(-8)}, NULL, NULL, NULL, false},
    {&SCREEN_A_6x3_AG,                  {FTOFIX19_13(35), FTOFIX19_13(27), FTOFIX19_13(0)}, NULL, NULL, NULL, false},
    {&SCREEN_A_1x1_AG,                  {FTOFIX19_13(18), FTOFIX19_13(57), FTOFIX19_13(0)}, NULL, NULL, NULL, false},
    {&KEYPAD_IM,                        {FTOFIX19_13(22), FTOFIX19_13(72), FTOFIX19_13(0)}, NULL, NULL, NULL, false},
    {&SCRAPYARD_BACKGROUND_S_PILLAR_IM, {FTOFIX19_13(80), FTOFIX19_13(39), FTOFIX19_13(-8)}, NULL, NULL, NULL, false},
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef SCRAPYARD_ST_ENTITIES[] =
{
	// since these are always visible it doesn't matter that they are not logically placed in this definition
	{&HERO_AC, 	{FTOFIX19_13(88), FTOFIX19_13(180), FTOFIX19_13(24)}, HERO_NAME, NULL, NULL, false},

	// the following entities must be placed in logical (spatial) order, according to the level's disposition,
	// for the streaming to work properly. beware of edge case scenarios!
	{&SCRAPYARD_FOREGROUND_1_MB,	    {FTOFIX19_13(248),  FTOFIX19_13(111), FTOFIX19_13(0)},   NULL, (struct PositionedEntity*)SCRAPYARD_FOREGROUND_1_MB_CHILDREN, NULL, false},
	{&SCRAPYARD_FOREGROUND_2_MB,	    {FTOFIX19_13(735),  FTOFIX19_13(111), FTOFIX19_13(0)},   NULL, (struct PositionedEntity*)SCRAPYARD_FOREGROUND_2_MB_CHILDREN, NULL, false},
	{&SCRAPYARD_BACKGROUND_1_MB,	    {FTOFIX19_13(256),  FTOFIX19_13(112), FTOFIX19_13(64)},  NULL, (struct PositionedEntity*)SCRAPYARD_BACKGROUND_1_MB_CHILDREN, NULL, false},
	{&SCRAPYARD_BACKGROUND_2_MB,	    {FTOFIX19_13(750),  FTOFIX19_13(112), FTOFIX19_13(64)},  NULL, (struct PositionedEntity*)SCRAPYARD_BACKGROUND_2_MB_CHILDREN, NULL, false},
	{&SCRAPYARD_BACKGROUND_L_PILLAR_IM, {FTOFIX19_13(436),  FTOFIX19_13(108), FTOFIX19_13(96)},  NULL, NULL, NULL, false},
	{&SCRAPYARD_BACKGROUND_FENCES_IM,   {FTOFIX19_13(418),  FTOFIX19_13(167), FTOFIX19_13(88)},  NULL, NULL, NULL, false},
	{&COLLISION_2x28x48,                {FTOFIX19_13(590),  FTOFIX19_13(24),  FTOFIX19_13(24)},  NULL, NULL, NULL, false},
	{&DOOR_FRAME_LEFT_IM,               {FTOFIX19_13(586),  FTOFIX19_13(137), FTOFIX19_13(56)},  NULL, NULL, NULL, false},
	{&DOOR_FRAME_RIGHT_IM,              {FTOFIX19_13(592),  FTOFIX19_13(135), FTOFIX19_13(8)},   NULL, NULL, NULL, false},
	{&SCRAPYARD_FAR_BACKGROUND_IM, 	    {FTOFIX19_13(444),  FTOFIX19_13(111), FTOFIX19_13(128)}, NULL, NULL, NULL, false},

	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef SCRAPYARD_ST_UI_ENTITIES[] =
{
	{&MINI_MAP_AG, {FTOFIX19_13(345), FTOFIX19_13(33), FTOFIX19_13(-33)}, NULL, NULL, NULL, false},

	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

TextureROMDef* SCRAPYARD_ST_TEXTURES[] =
{
    &SCRAPYARD_FOREGROUND_1_TX,
    &SCRAPYARD_FOREGROUND_2_TX,
    &SCRAPYARD_BACKGROUND_1_TX,
    &SCRAPYARD_BACKGROUND_2_TX,
    &WATER_PARTICLE_TX,
    &MINI_MAP_TX,
	NULL
};


//---------------------------------------------------------------------------------------------------------
// 											STAGE DEFINITION
//---------------------------------------------------------------------------------------------------------

PlatformerStageROMDef SCRAPYARD_ST =
{
    {
        // size
        {
            // x
            1200,
            // y
            224,
            // z
            512
        },

        // gravity
        {
            ITOFIX19_13(0),
            ITOFIX19_13(__GRAVITY / 2),
            ITOFIX19_13(0)
        },

        // friction
        FTOFIX19_13(0.1f),

        // Palette's config
        {
        	// background color
        	__COLOR_BLACK,
        	
        	{
        		0xE4,
        		0xE0,
        		0x90,
        		0xE0,
        	},
        	{
        		0xE4,
        		0xE0,
        		0x90,
        		0xE0,
        	} 
        },

    	// OBJs segments sizes (must total 1024)
        {
            // SPT0
        	256,
            // SPT1
        	256,
            // SPT2
        	256,
            // SPT3
        	256,
        },
        
        // OBJs segments z coordinates
        // Note that each SPT's z coordinate much be larger than or equal to the previous one's,
        // since the VIP renders OBJ Worlds in reverse order (SPT3 to SPT0)
        {
            // SPT0
            ITOFIX19_13(LAYER_FOREGROUND),
            // SPT1
            ITOFIX19_13(LAYER_BACKGROUND),
            // SPT2
            ITOFIX19_13(LAYER_BACKGROUND),
            // SPT3
            ITOFIX19_13(LAYER_BACKGROUND),
        },

        // initial screen position
        {
            // x
            ITOFIX19_13(0),
            // y
            ITOFIX19_13(0),
            // z
            ITOFIX19_13(0)
        },

        // optical configuration values
        {
            // maximum view distance's power into the horizont
        	__MAXIMUM_VIEW_DISTANCE_POWER,
            // distance of the eyes to the screen
            ITOFIX19_13(__DISTANCE_EYE_SCREEN),
            // distance from left to right eye (depth sensation)
            ITOFIX19_13(__BASE_FACTOR),
            // horizontal View point center
            ITOFIX19_13(__HORIZONTAL_VIEW_POINT_CENTER),
            // vertical View point center
            ITOFIX19_13(__VERTICAL_VIEW_POINT_CENTER),
        },

        // textures to preload
        (TextureDefinition**)SCRAPYARD_ST_TEXTURES,

        // UI
        {
            SCRAPYARD_ST_UI_ENTITIES,
            __TYPE(UI),
        },

        // entities
        SCRAPYARD_ST_ENTITIES,

        // background music
        NULL
    },

    // identifier
    "Scrapyard",

    // name
    (void*)STR_LEVEL_SCRAPYARD_NAME,
};