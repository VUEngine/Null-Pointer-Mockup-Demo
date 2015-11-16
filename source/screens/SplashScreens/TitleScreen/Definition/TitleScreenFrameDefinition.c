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

#include <Image.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE TitleScreenFrameTiles[];
extern BYTE TitleScreenFrameMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

TextureROMDef TITLE_SCREEN_FRAME_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        21,

        // allocation type
        __NOT_ANIMATED,

        // char definition
        TitleScreenFrameTiles,
    },

    // bgmap definition
    TitleScreenFrameMap,

    // cols (max 64)
    48,

    // rows (max 64)
    28,

    // number of frames
    1,

    // palette number
    1,
};

BgmapSpriteROMDef TITLE_SCREEN_FRAME_IM_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)& TITLE_SCREEN_FRAME_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// LOGOmap mode ( LOGOMAP, AFFINE, H-BIAS)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const TITLE_SCREEN_FRAME_IM_SPRITES[] =
{
	& TITLE_SCREEN_FRAME_IM_SPRITE,
	NULL
};

ImageROMDef TITLE_SCREEN_FRAME_IM =
{
	__TYPE(Image),
	(SpriteROMDef**) TITLE_SCREEN_FRAME_IM_SPRITES,
};