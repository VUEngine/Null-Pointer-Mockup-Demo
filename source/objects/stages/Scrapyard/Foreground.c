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

#include <MBackground.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE ScrapyardForegroundTiles[];
extern BYTE ScrapyardForeground1Map[];
extern BYTE ScrapyardForeground2Map[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

TextureROMDef SCRAPYARD_FOREGROUND_1_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        31,

        // allocation type
        __NOT_ANIMATED,

        // char definition
        ScrapyardForegroundTiles,
    },

    // bgmap definition
    ScrapyardForeground1Map,

    // cols (max 64)
    64,

    // rows (max 64)
    26,

    // number of frames
    1,

    // palette number
    1,
};

BgmapSpriteROMDef SCRAPYARD_FOREGROUND_1_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)&SCRAPYARD_FOREGROUND_1_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const SCRAPYARD_FOREGROUND_1_SPRITES[] =
{
	&SCRAPYARD_FOREGROUND_1_SPRITE,
	NULL
};

MBackgroundROMDef SCRAPYARD_FOREGROUND_1_MB =
{
	__TYPE(MBackground),
	(SpriteROMDef**)SCRAPYARD_FOREGROUND_1_SPRITES,
};


/////////////////////////////////////////////////////////////////////////////////////


TextureROMDef SCRAPYARD_FOREGROUND_2_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        31,

        // allocation type
        __NOT_ANIMATED,

        // char definition
        ScrapyardForegroundTiles,
    },

    // bgmap definition
    ScrapyardForeground2Map,

    // cols (max 64)
    64,

    // rows (max 64)
    26,

    // number of frames
    1,

    // palette number
    1,
};

BgmapSpriteROMDef SCRAPYARD_FOREGROUND_2_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)&SCRAPYARD_FOREGROUND_2_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const SCRAPYARD_FOREGROUND_2_SPRITES[] =
{
	&SCRAPYARD_FOREGROUND_2_SPRITE,
	NULL
};

MBackgroundROMDef SCRAPYARD_FOREGROUND_2_MB =
{
	__TYPE(MBackground),
	(SpriteROMDef**)SCRAPYARD_FOREGROUND_2_SPRITES,
};