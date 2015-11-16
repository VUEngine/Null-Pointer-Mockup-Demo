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
#include <AnimatedInGameEntity.h>
#include <BgmapAnimatedSprite.h>
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE MiniMapTiles[];
extern BYTE MiniMapMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMDef MINI_MAP_BLINK_ANIM =
{
	// number of frames of this animation function
	2,

	// frames to play in animation
	{0, 1},

	// number of cycles a frame of animation is displayed
	16 * __FPS_ANIM_FACTOR,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Blink",
};

// an animation definition
AnimationDescriptionROMDef MINI_MAP_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&MINI_MAP_BLINK_ANIM,
		NULL,
	}
};

TextureROMDef MINI_MAP_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        30,

        // allocation type
        __ANIMATED_SINGLE,

        // char definition
        MiniMapTiles,
    },

    // bgmap definition
    MiniMapMap,

    // cols (max 64)
    6,

    // rows (max 64)
    5,

    // number of frames
    2,

    // palette number
    0
};

BgmapSpriteROMDef MINI_MAP_SPRITE =
{
	// sprite's type
	__TYPE(BgmapAnimatedSprite),

	// texture definition
	(TextureDefinition*)&MINI_MAP_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const MINI_MAP_SPRITES[] =
{
	&MINI_MAP_SPRITE,
	NULL
};

AnimatedInGameEntityROMDef MINI_MAP_AG =
{
    {
        {
            __TYPE(AnimatedInGameEntity),
            (SpriteROMDef**)MINI_MAP_SPRITES,
        },

        // collision detection gap (up, down, left, right)
        {0, 0, 0, 0},

        // in game type
        kNotSolid,

        // width
        // if 0, width and height will be inferred from the texture's size
    	0,

    	// height
        // if 0, width and height will be inferred from the texture's size
    	0,
    	
    	// depth
        1
    },

    // pointer to the animation definition for the item
    (AnimationDescription*)&MINI_MAP_ANIM,

    // initial animation
    "Blink",
};