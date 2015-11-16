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
#include <ObjectAnimatedSprite.h>
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE LampTiles[];
extern BYTE LampMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMDef LAMP_STILL_ANIM =
{
	// number of frames of this animation function
	1,
	
	// frames to play in animation
	{0},
	
	// number of cycles a frame of animation is displayed
	0,
	
	// whether to play it in loop or not
	false,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Still",
};

// a function which defines the frames to play
AnimationFunctionROMDef LAMP_FLICKER_ANIM =
{
	// number of frames of this animation function
	2,

	// frames to play in animation
	{0,1},

	// number of cycles a frame of animation is displayed
	2 * __FPS_ANIM_FACTOR,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Flicker",
};

// an animation definition
AnimationDescriptionROMDef LAMP_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&LAMP_STILL_ANIM,
		(AnimationFunction*)&LAMP_FLICKER_ANIM,
		NULL,
	}
};

TextureROMDef LAMP_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        4,

        // allocation type
        __ANIMATED_SHARED_COORDINATED,

        // char definition
        LampTiles,
    },

    // bgmap definition
    LampMap,

    // cols (max 64)
    4,

    // rows (max 64)
    1,

    // number of frames
    2,

    // palette number
    1
};

ObjectSpriteROMDef LAMP_SPRITE =
{
	// sprite's type
	__TYPE(ObjectAnimatedSprite),

	// texture definition
	(TextureDefinition*)&LAMP_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, -1},
	
	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_OBJ,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

ObjectSpriteROMDef* const LAMP_SPRITES[] =
{
	&LAMP_SPRITE,
	NULL
};

AnimatedInGameEntityROMDef LAMP_AG =
{
    {
        {
            __TYPE(AnimatedInGameEntity),
            (SpriteROMDef**)LAMP_SPRITES,
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
    (AnimationDescription*)&LAMP_ANIM,

    // initial animation
    "Flicker",
};