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
#include <BgmapAnimatedSprite.h>
#include "Hero.h"


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE HeroTiles[];
extern BYTE HeroMap[];
extern BYTE HeroOutlineTiles[];
extern BYTE HeroOutlineMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMDef HERO_IDLE_ANIM =
{
	// number of frames of this animation function
	22,
	
	// frames to play in animation
	{0,1,0,1,2,3,2,3,0,1,0,1,2,3,4,3,4,3,0,1,0,1},
	
	// number of cycles a frame of animation is displayed
	8 * __FPS_ANIM_FACTOR,
	
	// whether to play it in loop or not
	true,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Idle",
};

// a function which defines the frames to play
AnimationFunctionROMDef HERO_WALKING_ANIM =
{
	// number of frames of this animation function
	8,
	
	// frames to play in animation
	{5,6,7,8,9,10,11,12},
	
	// number of cycles a frame of animation is displayed
	4 * __FPS_ANIM_FACTOR,
	
	// whether to play it in loop or not
	true,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Walk",
};

// a function which defines the frames to play
AnimationFunctionROMDef HERO_JUMPING_ANIM =
{
	// number of frames of this animation function
	1,
	
	// frames to play in animation
	{12},
	
	// number of cycles a frame of animation is displayed
	0,
	
	// whether to play it in loop or not
	false,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Jump",
};

// a function which defines the frames to play
AnimationFunctionROMDef HERO_FALLING_ANIM =
{
	// number of frames of this animation function
	1,
	
	// frames to play in animation
	{6},
	
	// number of cycles a frame of animation is displayed
	0,
	
	// whether to play it in loop or not
	false,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Fall",
};

// a function which defines the frames to play
AnimationFunctionROMDef HERO_SLIDING_ANIM =
{
	// number of frames of this animation function
	1,
	
	// frames to play in animation
	{10},
	
	// number of cycles a frame of animation is displayed
	0,
	
	// whether to play it in loop or not
	false,
	
	// method to call on function completion
	NULL,
	
	// function's name
	"Slide",
};

// an animation definition
AnimationDescriptionROMDef HERO_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&HERO_IDLE_ANIM,
		(AnimationFunction*)&HERO_WALKING_ANIM,
		(AnimationFunction*)&HERO_JUMPING_ANIM,
		(AnimationFunction*)&HERO_FALLING_ANIM,
		(AnimationFunction*)&HERO_SLIDING_ANIM,
		NULL,
	}
};

TextureROMDef HERO_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        20,

        // allocation type
        __ANIMATED_SINGLE,

        // char definition
        HeroTiles,
    },

    // bgmap definition
    HeroMap,

    // cols (max 64)
    4,

    // rows (max 64)
    5,

    // number of frames
    13,

    // palette number
    0,
};

TextureROMDef HERO_OUTLINE_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        20,

        // allocation type
        __ANIMATED_SINGLE,

        // char definition
        HeroOutlineTiles,
    },

    // bgmap definition
    HeroOutlineMap,

    // cols (max 64)
    4,

    // rows (max 64)
    5,

    // number of frames
    13,

    // palette number
    1,
};

BgmapSpriteROMDef HERO_SPRITE =
{
	// sprite's type
	__TYPE(BgmapAnimatedSprite),

	// texture definition
	(TextureDefinition*)&HERO_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},

	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_AFFINE,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef HERO_OUTLINE_SPRITE =
{
	// sprite's type
	__TYPE(BgmapAnimatedSprite),

	// texture definition
	(TextureDefinition*)&HERO_OUTLINE_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},

	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_AFFINE,

	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const HERO_SPRITES[] =
{
	&HERO_OUTLINE_SPRITE,
	&HERO_SPRITE,
	NULL
};

ActorROMDef HERO_AC =
{
	{
	    {
	        {
	            __TYPE(Hero),
	            (SpriteROMDef**)HERO_SPRITES,
	        },

	        // collision detection gap (up, down, left, right)
	        {3, 1, 13, 11},

	        // in game type
	        kHero,

	        // width
	        // if 0, width and height will be inferred from the texture's size
	    	0,

	    	// height
	        // if 0, width and height will be inferred from the texture's size
	    	0,

	    	// depth
	        8
	    },

	    // pointer to the animation definition for the character
	    (AnimationDescription*)&HERO_ANIM,

	    // initial animation
	    NULL,
	},

	// friction for physics
	ITOFIX19_13(0),

	// elasticity for physics
	ITOFIX19_13(0),

	// mass
	ITOFIX19_13(10)
};