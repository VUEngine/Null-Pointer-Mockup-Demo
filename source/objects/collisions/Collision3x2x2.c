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

#include <InanimatedInGameEntity.h>
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

InanimatedInGameEntityROMDef COLLISION_3x2x2 =
{
    {
        {
            __TYPE(InanimatedInGameEntity),
            NULL,
        },

        // collision detection gap (up, down, left, right)
        {0, 0, 0, 0},

        // in game type
        kSolid,

    	// width
        // if 0, width and height will be inferred from the texture's size
    	3 * 8,

    	// height
        // if 0, width and height will be inferred from the texture's size
    	2 * 8,

    	// depth
    	2 * 8
    },

    // friction FTOFIX19_13
    FTOFIX19_13(40),

    // elasticity FTOFIX19_13
    FTOFIX19_13(1.0f),

    // register shape
    true,
};