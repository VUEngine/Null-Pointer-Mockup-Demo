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
#include <Printing.h>
#include <MessageDispatcher.h>
#include <KeypadManager.h>
#include <I18n.h>
#include <PrecautionScreenState.h>
#include <AdjustmentScreenState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef EMPTY_ST;


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void PrecautionScreenState_destructor(PrecautionScreenState this);
static void PrecautionScreenState_constructor(PrecautionScreenState this);
static void PrecautionScreenState_enter(PrecautionScreenState this, void* owner);
static void PrecautionScreenState_print(PrecautionScreenState this);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(PrecautionScreenState, SplashScreenState);
__SINGLETON_DYNAMIC(PrecautionScreenState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
static void PrecautionScreenState_constructor(PrecautionScreenState this)
{
	__CONSTRUCT_BASE();

	SplashScreenState_setNextstate(__GET_CAST(SplashScreenState, this), __GET_CAST(GameState, AdjustmentScreenState_getInstance()));
	this->stageDefinition = (StageDefinition*)&EMPTY_ST;
}

// class's destructor
static void PrecautionScreenState_destructor(PrecautionScreenState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

// state's enter
static void PrecautionScreenState_enter(PrecautionScreenState this, void* owner)
{
    SplashScreenState_enter(__GET_CAST(SplashScreenState, this), owner);

    // show this screen for at least 2 seconds, as defined by Nintendo in the official development manual
	Clock_delay(Game_getClock(Game_getInstance()), 2000);
	KeypadManager_flush(KeypadManager_getInstance());
}

static void PrecautionScreenState_print(PrecautionScreenState this)
{
    char* strPrecautionTitle = I18n_getText(I18n_getInstance(), STR_PRECAUTION_SCREEN_TITLE);
    char* strPrecautionText = I18n_getText(I18n_getInstance(), STR_PRECAUTION_SCREEN_TEXT);
    Size titleSize = Printing_getTextSize(Printing_getInstance(), strPrecautionTitle, NULL);
    Size textSize = Printing_getTextSize(Printing_getInstance(), strPrecautionText, NULL);

    u8 totalHeight = titleSize.y + 1 + textSize.y;

    Printing_text(
        Printing_getInstance(),
        strPrecautionTitle,
        (__SCREEN_WIDTH >> 4) - (titleSize.x >> 1),
        (__SCREEN_HEIGHT >> 4) - (totalHeight >> 1),
        NULL
    );

    Printing_text(
        Printing_getInstance(),
        strPrecautionText,
        (__SCREEN_WIDTH >> 4) - (textSize.x >> 1),
        (__SCREEN_HEIGHT >> 4) - (totalHeight >> 1) + titleSize.y + 1,
        NULL
    );
}

