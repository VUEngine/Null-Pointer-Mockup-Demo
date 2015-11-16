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
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE ScrapyardBackgroundSPillarFrontTiles[];
extern BYTE ScrapyardBackgroundSPillarFrontMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

TextureROMDef SCRAPYARD_BACKGROUND_S_PILLAR_FRONT_TX =
{
    {
        // number of chars, depending on allocation type:
        // __ANIMATED_SINGLE: number of chars of a single animation frame (cols * rows of this texture)
        // __ANIMATED_MULTI: sum of chars of all animation frames
        // __ANIMATED_SHARED: number of chars of a single animation frame (cols * rows of this texture)
        // __NOT_ANIMATED: number of chars of whole image
        7,

        // allocation type
        __NOT_ANIMATED,

        // char definition
        ScrapyardBackgroundSPillarFrontTiles,
    },

    // bgmap definition
    ScrapyardBackgroundSPillarFrontMap,

    // cols (max 64)
    2,

    // rows (max 64)
    13,

    // number of frames
    1,

    // palette number
    2,
};

BgmapSpriteROMDef SCRAPYARD_BACKGROUND_S_PILLAR_FRONT_BGMAP_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)&SCRAPYARD_BACKGROUND_S_PILLAR_FRONT_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},

	// bgmap mode (WRLD_BGMAP, WRLD_AFFINE, WRLD_HBIAS OR WRLD_OBJ)
	WRLD_BGMAP,

	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_ON,
};

BgmapSpriteROMDef* const SCRAPYARD_BACKGROUND_S_PILLAR_SPRITES[] =
{
	&SCRAPYARD_BACKGROUND_S_PILLAR_FRONT_BGMAP_SPRITE,
	NULL
};

ImageROMDef SCRAPYARD_BACKGROUND_S_PILLAR_IM =
{
	__TYPE(Image),
	(SpriteROMDef**)SCRAPYARD_BACKGROUND_S_PILLAR_SPRITES,
};