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

#include <string.h>

#include <Game.h>
#include <Screen.h>
#include <Screen.h>
#include <Printing.h>
#include <MessageDispatcher.h>
#include <PhysicalWorld.h>
#include <I18n.h>
#include <PlatformerLevelState.h>
#include <AdjustmentScreenState.h>
#include <TitleScreenState.h>
#include <PauseScreenState.h>
#include <Hero.h>
#include "../stages/stages.h"
#include <macros.h>
#include <Languages.h>
#include <objects.h>



//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void PlatformerLevelState_constructor(PlatformerLevelState this);
static void PlatformerLevelState_destructor(PlatformerLevelState this);
static void PlatformerLevelState_enter(PlatformerLevelState this, void* owner);
static void PlatformerLevelState_exit(PlatformerLevelState this, void* owner);
static void PlatformerLevelState_suspend(PlatformerLevelState this, void* owner);
static void PlatformerLevelState_resume(PlatformerLevelState this, void* owner);
static bool PlatformerLevelState_handleMessage(PlatformerLevelState this, void* owner, Telegram telegram);
static void PlatformerLevelState_getEntityNamesToIngnore(PlatformerLevelState this, VirtualList entityNamesToIgnore);
void PlatformerLevelState_setModeToPaused(PlatformerLevelState this);
void PlatformerLevelState_setModeToPlaying(PlatformerLevelState this);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(PlatformerLevelState, GameState);
__SINGLETON(PlatformerLevelState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
static void PlatformerLevelState_constructor(PlatformerLevelState this)
{
	__CONSTRUCT_BASE();

	this->platformerStageDefinition = (PlatformerStageDefinition*)&SCRAPYARD_ST;

	this->heroLastPosition.x = 0;
	this->heroLastPosition.y = 0;
	this->heroLastPosition.z = 0;
	
	this->isExitingRoom = false;
}

// class's destructor
static void PlatformerLevelState_destructor(PlatformerLevelState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

static void PlatformerLevelState_getEntityNamesToIngnore(PlatformerLevelState this, VirtualList entityNamesToIgnore)
{
	ASSERT(entityNamesToIgnore, "PlatformerLevelState::getEntityNamesToIngnore: null entityNamesToIgnore");
}

// state's enter
static void PlatformerLevelState_enter(PlatformerLevelState this, void* owner)
{
	VirtualList entityNamesToIgnore = __NEW(VirtualList);
	PlatformerLevelState_getEntityNamesToIngnore(this, entityNamesToIgnore);
	
	// check if exiting room
	if(this->isExitingRoom)
	{
		VBVec3D screenPosition = 
		{
			this->heroLastPosition.x - ITOFIX19_13(__SCREEN_WIDTH >> 1),
			this->heroLastPosition.y - ITOFIX19_13(__SCREEN_HEIGHT >> 1),
			this->heroLastPosition.z
		};
		
		// set world's limits
		Screen_setStageSize(Screen_getInstance(), this->platformerStageDefinition->stageDefinition.size);

		// must set the screen's position before loading the stage
		Screen_setPosition(Screen_getInstance(), screenPosition);
	    
		// load stage
		GameState_loadStage(__GET_CAST(GameState, this), (StageDefinition*)&(this->platformerStageDefinition->stageDefinition), entityNamesToIgnore, false);

		Container hero = Container_getChildByName(__GET_CAST(Container, this->stage), HERO_NAME, true);

		if(!hero)
		{
			PositionedEntity positionedEntity =
			{
				&HERO_AC, 				
				{
					this->heroLastPosition.x, 
					this->heroLastPosition.y, 
					this->heroLastPosition.z
				}, 
				HERO_NAME, 
				NULL, 
				NULL,
				false
			};

			hero = __GET_CAST(Container, Stage_addPositionedEntity(this->stage, &positionedEntity, true));
			
			// make sure that the streaming doesn't load the hero again
			Stage_registerEntityId(this->stage, Container_getId(hero), &HERO_AC);
		}
		else
		{
			Actor_setPosition(__GET_CAST(Actor, hero), &this->heroLastPosition);
		}
		
		this->isExitingRoom = false;
	}
	else
	{
		GameState_loadStage(__GET_CAST(GameState, this), (StageDefinition*)&(this->platformerStageDefinition->stageDefinition), entityNamesToIgnore, true);
	}
	
	__DELETE(entityNamesToIgnore);

	// playing by default
	PlatformerLevelState_setModeToPaused(this);
	
	// show up level after a little bit
	MessageDispatcher_dispatchMessage(1000, __GET_CAST(Object, this), __GET_CAST(Object, Game_getInstance()), kSetUpLevel, NULL);

	// reset clock and render time
	Clock_reset(Game_getInGameClock(Game_getInstance()));
	
	// make a little bit of physical simulations so each entity is placed at the floor
	Clock_start(Game_getInGameClock(Game_getInstance()));
}

// state's exit
static void PlatformerLevelState_exit(PlatformerLevelState this, void* owner)
{
	// make a fade in
	Screen_startEffect(Screen_getInstance(), kFadeOut, FADE_DELAY);
	
	// call base
	GameState_exit(__GET_CAST(GameState, this), owner);
}

static void PlatformerLevelState_suspend(PlatformerLevelState this, void* owner)
{
	// pause physical simulations
	Clock_pause(Game_getInGameClock(Game_getInstance()), true);

#ifdef __DEBUG_TOOLS
	if(!Game_isEnteringSpecialMode(Game_getInstance()))
#endif
#ifdef __STAGE_EDITOR
	if(!Game_isEnteringSpecialMode(Game_getInstance()))
#endif
#ifdef __ANIMATION_EDITOR
	if(!Game_isEnteringSpecialMode(Game_getInstance()))
#endif
	// make a fade in
    Screen_startEffect(Screen_getInstance(), kFadeOut, FADE_DELAY);

	GameState_suspend(__GET_CAST(GameState, this), owner);
}

static void PlatformerLevelState_resume(PlatformerLevelState this, void* owner)
{
	GameState_resume(__GET_CAST(GameState, this), owner);

#ifdef __DEBUG_TOOLS
	if(!Game_isExitingSpecialMode(Game_getInstance()))
	{
#endif
#ifdef __STAGE_EDITOR
	if(!Game_isExitingSpecialMode(Game_getInstance()))
	{
#endif
#ifdef __ANIMATION_EDITOR
	if(!Game_isExitingSpecialMode(Game_getInstance()))
	{
#endif

	// make a fade in
    Screen_startEffect(Screen_getInstance(), kFadeIn, FADE_DELAY >> 1);
	
	// tell any interested entity
	GameState_propagateMessage(__GET_CAST(GameState, this), kResumeLevel);

#ifdef __DEBUG_TOOLS
	}
#endif
#ifdef __STAGE_EDITOR
	}
#endif
#ifdef __ANIMATION_EDITOR
	}
#endif
	
	// pause physical simulations
	Clock_pause(Game_getInGameClock(Game_getInstance()), false);

	PlatformerLevelState_setModeToPlaying(this);
}

// state's on message
static bool PlatformerLevelState_handleMessage(PlatformerLevelState this, void* owner, Telegram telegram)
{
	// process message
	switch(Telegram_getMessage(telegram))
    {
		case kSetUpLevel:

			{
				// tell any interested entity
				GameState_propagateMessage(__GET_CAST(GameState, this), kSetUpLevel);
	
				// account for any entity's tranform modification during their initialization
				GameState_transform(__GET_CAST(GameState, this));
				
				// show level after 0.25 second
				MessageDispatcher_dispatchMessage(250, __GET_CAST(Object, this), __GET_CAST(Object, Game_getInstance()), kStartLevel, NULL);
	
				this->mode = kShowingUp;
			}
			break;

		case kStartLevel:

			// fade screen
		    Screen_startEffect(Screen_getInstance(), kFadeIn, FADE_DELAY);

			// reset clock and restart
			Clock_reset(Game_getInGameClock(Game_getInstance()));

			// tell any interested entity
			GameState_propagateMessage(__GET_CAST(GameState, this), kStartLevel);

			// restart clock
			// pause physical simulations
			Clock_reset(Game_getInGameClock(Game_getInstance()));

        	PlatformerLevelState_setModeToPlaying(this);
			break;

		case kKeyPressed:

			if(kPlaying == this->mode)
            {
				u16 pressedKey = *((u16*)Telegram_getExtraInfo(telegram));

				if(K_SEL & pressedKey)
				{
    				// adjustment screen
	                PlatformerLevelState_setModeToPaused(this);
					SplashScreenState_setNextstate(__GET_CAST(SplashScreenState, AdjustmentScreenState_getInstance()), NULL);
					Game_pause(Game_getInstance(), __GET_CAST(GameState, AdjustmentScreenState_getInstance()));
					break;
            	}
				else if(K_STA & pressedKey)
                {
                    // pause screen
					PlatformerLevelState_setModeToPaused(this);
                    Game_pause(Game_getInstance(), __GET_CAST(GameState, PauseScreenState_getInstance()));
                    break;
                }
				
				Object_fireEvent(__GET_CAST(Object, this), EVENT_KEY_PRESSED);
			}
			return true;
			break;

		case kKeyReleased:

			if(kPlaying == this->mode)
            {
				Object_fireEvent(__GET_CAST(Object, this), EVENT_KEY_RELEASED);
			}
			return true;
			break;
			
		case kKeyHold:
			
			if(kPlaying == this->mode)
            {
				Object_fireEvent(__GET_CAST(Object, this), EVENT_KEY_HOLD);
			}
			return true;
			break;

		case kHeroDied:	
			
			Game_changeState(Game_getInstance(), __GET_CAST(GameState, TitleScreenState_getInstance()));
			return true;
			break;
	}

	return false;
}

// set the next state to load
void PlatformerLevelState_setStage(PlatformerLevelState this, PlatformerStageDefinition* platformerStageDefinition)
{
	this->platformerStageDefinition = platformerStageDefinition;
}

// start a given level
void PlatformerLevelState_goToLevel(PlatformerStageDefinition* platformerStageDefinition)
{
	PlatformerLevelState this = PlatformerLevelState_getInstance();
	this->platformerStageDefinition = platformerStageDefinition;
	Game_changeState(Game_getInstance(), __GET_CAST(GameState, this));
}

// start a given room
void PlatformerLevelState_enterRoom(PlatformerStageDefinition* platformerStageDefinition)
{
	PlatformerLevelState this = PlatformerLevelState_getInstance();

	// save hero's actual position
	Hero hero = __GET_CAST(Hero, Container_getChildByName(__GET_CAST(Container, this->stage), HERO_NAME, false));
	ASSERT(hero, "PlatformerLevelState::enterRoom: hero not found");

	if(hero)
	{
		this->heroLastPosition = *Container_getLocalPosition(__GET_CAST(Container, hero));
		this->isExitingRoom = false;
	}

	this->platformerStageDefinition = platformerStageDefinition;
	
	Game_changeState(Game_getInstance(), __GET_CAST(GameState, this));
}

// exit a given room
void PlatformerLevelState_exitRoom(PlatformerStageDefinition* platformerStageDefinition)
{
	PlatformerLevelState this = PlatformerLevelState_getInstance();
	this->platformerStageDefinition = platformerStageDefinition;
	this->isExitingRoom = true;
	Game_changeState(Game_getInstance(), __GET_CAST(GameState, this));
}

// set paused mode
void PlatformerLevelState_setModeToPaused(PlatformerLevelState this)
{
	this->mode = kPaused;
}

// set kplaying mode
void PlatformerLevelState_setModeToPlaying(PlatformerLevelState this)
{
	this->mode = kPlaying;
}