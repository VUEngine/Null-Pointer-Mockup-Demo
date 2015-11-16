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

#include <libgccvb.h>
#include <ParticleSystem.h>
#include <ObjectSprite.h>
#include "../behaviors.h"


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE WaterdropTiles[];
extern BYTE WaterdropMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

TextureROMDef WATER_PARTICLE_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        1,

        // allocation type
		__NOT_ANIMATED,
        
        // char definition
        WaterdropTiles,
    },

    // bgmap definition
    WaterdropMap,

    // cols (max 64)
    1,

    // rows (max 64)
    1,

    // number of frames
    1,

    // palette number
    1,
};


//---------------------------------------------------------------------------------------------------------
// 										  OBJECT WATER_PARTICLE
//---------------------------------------------------------------------------------------------------------

ObjectSpriteROMDef WATER_PARTICLE_SPRITE =
{
	// sprite's type
	__TYPE(ObjectSprite),

	// texture definition
	(TextureDefinition*)&WATER_PARTICLE_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_OBJ,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

ObjectSpriteROMDef* const WATER_PARTICLE_SPRITES[] =
{
	&WATER_PARTICLE_SPRITE,
	NULL
};

// particle's definition
ParticleROMDef WATER_PARTICLE =
{
	// allocator
    __TYPE(Particle),

	// particle's minimum life span in milliseconds
	1000,

	// particle's maximum life span in milliseconds
	1001,

	// particle's minimum mass
	FTOFIX19_13(1.0f),

	// particle's maximum mass
	FTOFIX19_13(3.0f),
	
	// axis subject to gravity (false to disable)
	__YAXIS,
	
	// function pointer to control particle's behavior
	NULL,

	// animation description
	// used only if sprite is animated
	NULL,

	// animation's name to play 
	NULL
};

ParticleSystemROMDef WATER_PS =
{
    {
        __TYPE(ParticleSystem),
        NULL,
    },

	// reuse expired particles?
    false,

    // minimum generation delay in milliseconds
	500,

	// maximum generation delay in milliseconds
	1000,

	// maximum total particles
	2,

	// array of textures
	(const ObjectSpriteDefinition**)WATER_PARTICLE_SPRITES,

	// auto start
	true,
	
	// particle definition
	(ParticleDefinition*)&WATER_PARTICLE,
	
	// minimum random distance from the center of the system for spawn
	{ITOFIX19_13(0), ITOFIX19_13(0), ITOFIX19_13(0)},

	// minimum relative spawn position
	{ITOFIX19_13(0), ITOFIX19_13(0), ITOFIX19_13(0)},

	// maximum relative spawn position
	{ITOFIX19_13(0), ITOFIX19_13(0), ITOFIX19_13(0)},
	
	// minimum force to apply
	// use int values in the definition to avoid overflow
	{(0), (0), (0)},

	// maximum force to apply
	// use int values in the definition to avoid overflow
	{(0), (0), (0)},
};
