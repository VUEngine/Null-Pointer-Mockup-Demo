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

extern BYTE AdjustmentScreenIconTiles[];
extern BYTE AdjustmentScreenIconMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

TextureROMDef ADJUSTMENT_SCREEN_ICON_TX =
{
    {
        // number of chars,
        5,

        // allocation type
        __NOT_ANIMATED,

        // char definition
        AdjustmentScreenIconTiles,
    },

    // ICONmap definition
    AdjustmentScreenIconMap,

    // cols (max 64)
    2,

    // rows (max 64)
    2,

    // number of frames
    1,

    // palette number
    0,
};

BgmapSpriteROMDef ADJUSTMENT_SCREEN_ICON_IM_L_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)& ADJUSTMENT_SCREEN_ICON_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// ICONmap mode ( ICONMAP, AFFINE, H-BIAS)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_LON,
};

BgmapSpriteROMDef* const ADJUSTMENT_SCREEN_ICON_IM_L_SPRITES[] =
{
	& ADJUSTMENT_SCREEN_ICON_IM_L_SPRITE,
	NULL
};

BgmapSpriteROMDef const ADJUSTMENT_SCREEN_ICON_IM_R_SPRITE =
{
	// sprite's type
	__TYPE(BgmapSprite),

	// texture definition
	(TextureDefinition*)& ADJUSTMENT_SCREEN_ICON_TX,

	// displacement (x, y, z) (in pixels)
	{0, 0, 0},
	
	// ICONmap mode ( ICONMAP, AFFINE, H-BIAS)
	WRLD_BGMAP,
	
	// display mode (WRLD_ON, WRLD_LON or WRLD_RON)
	WRLD_RON,
};

BgmapSpriteROMDef* ADJUSTMENT_SCREEN_ICON_IM_R_SPRITES[] =
{
	& ADJUSTMENT_SCREEN_ICON_IM_R_SPRITE,
	NULL

};

ImageROMDef ADJUSTMENT_SCREEN_ICON_IM_L =
{
	__TYPE(Image),
	(SpriteROMDef**) ADJUSTMENT_SCREEN_ICON_IM_L_SPRITES,
};

ImageROMDef ADJUSTMENT_SCREEN_ICON_IM_R =
{
	__TYPE(Image),
	(SpriteROMDef**) ADJUSTMENT_SCREEN_ICON_IM_R_SPRITES,
};