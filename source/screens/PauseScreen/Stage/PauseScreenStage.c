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
#include <objects.h>
#include <macros.h>
#include <PauseScreenState.h>
#include <screens.h>
#include <VPUManager.h>


//---------------------------------------------------------------------------------------------------------
// 												DEFINES
//---------------------------------------------------------------------------------------------------------

#define LEVEL_X_SIZE 	    __SCREEN_WIDTH
#define LEVEL_Y_SIZE 	    __SCREEN_HEIGHT
#define LEVEL_Z_SIZE 	    __SCREEN_WIDTH

#define SCREEN_X_POSITION 	0
#define SCREEN_Y_POSITION 	0
#define SCREEN_Z_POSITION 	0


//---------------------------------------------------------------------------------------------------------
// 												ASSETS
// ---------------------------------------------------------------------------------------------------------
/* Don't forget to place the NULL markers at the end of each array. It's the only way the engine has to
 * know that it must stop reading the stage's/ui's textures and entities.
 */

PositionedEntityROMDef PAUSE_SCREEN_ST_ENTITIES[] =
{
	// since these are always visible it doesn't matter that they are not logically placed in this definition
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

PositionedEntityROMDef PAUSE_SCREEN_ST_UI_ENTITIES[] =
{
	{NULL, {0,0,0}, NULL, NULL, NULL, false},
};

TextureROMDef* PAUSE_SCREEN_ST_TEXTURES[] =
{
	NULL
};


//---------------------------------------------------------------------------------------------------------
// 											STAGE DEFINITION
//---------------------------------------------------------------------------------------------------------

StageROMDef PAUSE_SCREEN_ST =
{
    // size
    {
        // x
        LEVEL_X_SIZE,
        // y
        LEVEL_Y_SIZE,
        // z
        LEVEL_Z_SIZE
    },

    // gravity
    {
	    ITOFIX19_13(0),
	    ITOFIX19_13(0),
	    ITOFIX19_13(0)
    },

    // friction
    ITOFIX19_13(0),
    
    // Palette's config
    {
    	// background color
    	__COLOR_BLACK,
    	
    	{
    		0xE4,
    		0xE0,
    		0xD0,
    		0xE0,
    	},
    	{
    		0xE4,
    		0xE0,
    		0xD0,
    		0xE0,
    	} 
    },

	// OBJs segments sizes (must total 1024)
    {
        // SPT0
    	__AVAILABLE_CHAR_OBJECTS / __TOTAL_OBJECT_SEGMENTS,
        // SPT1
    	__AVAILABLE_CHAR_OBJECTS / __TOTAL_OBJECT_SEGMENTS,
        // SPT2
    	__AVAILABLE_CHAR_OBJECTS / __TOTAL_OBJECT_SEGMENTS,
        // SPT3
    	__AVAILABLE_CHAR_OBJECTS / __TOTAL_OBJECT_SEGMENTS,
    },


	// OBJs segments z coordinates
	// Note that each SPT's z coordinate much be larger than or equal to the previous one's,
	// since the VIP renders OBJ Worlds in reverse order (SPT3 to SPT0)
    {
        // SPT0
		ITOFIX19_13(0),
        // SPT1
		ITOFIX19_13(0),
        // SPT2
		ITOFIX19_13(0),
        // SPT3
    	ITOFIX19_13(0),
    },

    // initial screen position
    {
        // x
        ITOFIX19_13(SCREEN_X_POSITION),
        // y
        ITOFIX19_13(SCREEN_Y_POSITION),
        // z
        ITOFIX19_13(SCREEN_Z_POSITION)
    },

    // optical configuration values
    {
        // maximum view distance's power into the horizon
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
    (TextureDefinition**)PAUSE_SCREEN_ST_TEXTURES,

    // UI
    {
        PAUSE_SCREEN_ST_UI_ENTITIES,
        __TYPE(UI),
    },

    // entities
    PAUSE_SCREEN_ST_ENTITIES,

    // background music
    NULL,
    //(const u16 (*)[])WORLD_0_0_0_BGM,
};