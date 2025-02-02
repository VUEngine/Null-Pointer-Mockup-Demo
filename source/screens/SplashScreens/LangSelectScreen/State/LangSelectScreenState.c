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
#include <I18n.h>
#include <LangSelectScreenState.h>
#include <TitleScreenState.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef EMPTY_ST;
extern LangROMDef* __LANGUAGES[];


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void LangSelectScreenState_destructor(LangSelectScreenState this);
static void LangSelectScreenState_constructor(LangSelectScreenState this);
static void LangSelectScreenState_processInput(LangSelectScreenState this, u16 pressedKey);
static void LangSelectScreenState_print(LangSelectScreenState this);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(LangSelectScreenState, SplashScreenState);
__SINGLETON_DYNAMIC(LangSelectScreenState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
static void LangSelectScreenState_constructor(LangSelectScreenState this)
{
	__CONSTRUCT_BASE();

	SplashScreenState_setNextstate(__GET_CAST(SplashScreenState, this), __GET_CAST(GameState, TitleScreenState_getInstance()));
	this->stageDefinition = (StageDefinition*)&EMPTY_ST;

    u8 activeLanguage = I18n_getActiveLanguage(I18n_getInstance());
	this->languageSelector = OptionsSelector_new(1, 8, "\xB", kString);

	VirtualList languageNames = VirtualList_new();

	int i = 0;
	for(; __LANGUAGES[i]; i++)
	{
		I18n_setActiveLanguage(I18n_getInstance(), i);
		VirtualList_pushBack(languageNames, I18n_getActiveLanguageName(I18n_getInstance()));
	}

	I18n_setActiveLanguage(I18n_getInstance(), activeLanguage);

    OptionsSelector_setOptions(this->languageSelector, languageNames);
	__DELETE(languageNames);
}

// class's destructor
static void LangSelectScreenState_destructor(LangSelectScreenState this)
{
	if(this->languageSelector)
	{
		__DELETE(this->languageSelector);
	}

	// destroy base
	__SINGLETON_DESTROY;
}

void LangSelectScreenState_processInput(LangSelectScreenState this, u16 pressedKey)
{
	if ((pressedKey & K_LU) || (pressedKey & K_RU))
	{
		OptionsSelector_selectPrevious(this->languageSelector);
	}
    else if ((pressedKey & K_LD) || (pressedKey & K_RD))
	{
		OptionsSelector_selectNext(this->languageSelector);
	}
	else if ((pressedKey & K_A) || (pressedKey & K_STA))
	{
	    I18n_setActiveLanguage(I18n_getInstance(), OptionsSelector_getSelectedOption(this->languageSelector));
	    Game_changeState(Game_getInstance(), __GET_CAST(GameState, this->nextState));
	}
}

static void LangSelectScreenState_print(LangSelectScreenState this)
{
    char* strLanguageSelect = I18n_getText(I18n_getInstance(), STR_LANGUAGE_SELECT);
    Size size = Printing_getTextSize(Printing_getInstance(), strLanguageSelect, "GUIFont");

    u8 strHeaderXPos = (__SCREEN_WIDTH >> 4) - (size.x >> 1);

    Printing_text(Printing_getInstance(), strLanguageSelect, strHeaderXPos, 8, "GUIFont");

	OptionsSelector_showOptions(this->languageSelector, strHeaderXPos, 9 + size.y);
}

