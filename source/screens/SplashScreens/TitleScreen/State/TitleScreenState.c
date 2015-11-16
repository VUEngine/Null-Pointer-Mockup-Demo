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
#include <TitleScreenState.h>
#include <PlatformerLevelState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef TITLE_SCREEN_ST;


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void TitleScreenState_destructor(TitleScreenState this);
static void TitleScreenState_constructor(TitleScreenState this);
static void TitleScreenState_print(TitleScreenState this);
static void TitleScreenState_processInput(TitleScreenState this, u16 pressedKey);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(TitleScreenState, SplashScreenState);
__SINGLETON_DYNAMIC(TitleScreenState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
static void TitleScreenState_constructor(TitleScreenState this)
{
	__CONSTRUCT_BASE();

	SplashScreenState_setNextstate(__GET_CAST(SplashScreenState, this), __GET_CAST(GameState, PlatformerLevelState_getInstance()));
	this->stageDefinition = (StageDefinition*)& TITLE_SCREEN_ST;
}

// class's destructor
static void TitleScreenState_destructor(TitleScreenState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

static void TitleScreenState_print(TitleScreenState this)
{
}

static void TitleScreenState_processInput(TitleScreenState this, u16 pressedKey)
{
    Game_changeState(Game_getInstance(), this->nextState);
}
