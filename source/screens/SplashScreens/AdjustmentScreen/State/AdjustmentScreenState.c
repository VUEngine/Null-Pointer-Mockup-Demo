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

#include <Game.h>
#include <Screen.h>
#include <MessageDispatcher.h>
#include <AdjustmentScreenState.h>
#include <AutoPauseSelectScreenState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef ADJUSTMENT_SCREEN_ST;


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void AdjustmentScreenState_destructor(AdjustmentScreenState this);
static void AdjustmentScreenState_constructor(AdjustmentScreenState this);
static void AdjustmentScreenState_print(AdjustmentScreenState this);
static void AdjustmentScreenState_processInput(AdjustmentScreenState this, u16 pressedKey);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(AdjustmentScreenState, SplashScreenState);
__SINGLETON_DYNAMIC(AdjustmentScreenState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
static void AdjustmentScreenState_constructor(AdjustmentScreenState this)
{
	__CONSTRUCT_BASE();

	SplashScreenState_setNextstate(__GET_CAST(SplashScreenState, this), __GET_CAST(GameState, AutoPauseSelectScreenState_getInstance()));
	this->stageDefinition = (StageDefinition*)& ADJUSTMENT_SCREEN_ST;
}

// class's destructor
static void AdjustmentScreenState_destructor(AdjustmentScreenState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

static void AdjustmentScreenState_print(AdjustmentScreenState this)
{
}

static void AdjustmentScreenState_processInput(AdjustmentScreenState this, u16 pressedKey)
{
    // TODO: replace this ugly hack with a proper Game_isPaused check or something similar
    if(this->nextState == NULL)
    {
        Game_unpause(Game_getInstance(), __GET_CAST(GameState, this));
    } 
    else 
    {
	    Game_changeState(Game_getInstance(), this->nextState);
    }
}
