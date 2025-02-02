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

#include "HeroIdle.h"
#include "HeroMoving.h"
#include "../Hero.h"

#include <PlatformerLevelState.h>
#include <MessageDispatcher.h>

#ifdef __DEBUG
#endif


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void HeroIdle_constructor(HeroIdle this);
void HeroIdle_destructor(HeroIdle this);
void HeroIdle_enter(HeroIdle this, void* owner);
void HeroIdle_execute(HeroIdle this, void* owner);
void HeroIdle_exit(HeroIdle this, void* owner);
bool HeroIdle_handleMessage(HeroIdle this, void* owner, Telegram telegram);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(HeroIdle, State);
__SINGLETON(HeroIdle);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void HeroIdle_constructor(HeroIdle this)
{
	// construct base
	__CONSTRUCT_BASE();
}

// class's destructor
void HeroIdle_destructor(HeroIdle this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

// state's enter
void HeroIdle_enter(HeroIdle this, void* owner)
{
	// make sure it's not moving anymore
	Actor_stopMovement(__GET_CAST(Actor, owner));
	
    // show animation
    AnimatedInGameEntity_playAnimation(__GET_CAST(AnimatedInGameEntity, owner), "Idle");

#ifdef __DEBUG
	Printing_text(Printing_getInstance(), "HeroIdle::enter   ", 0, (__SCREEN_HEIGHT >> 3) - 2, NULL);
#endif
}

// state's execute
void HeroIdle_execute(HeroIdle this, void* owner)
{
}

// state's exit
void HeroIdle_exit(HeroIdle this, void* owner)
{
}

// state's on message
bool HeroIdle_handleMessage(HeroIdle this, void* owner, Telegram telegram)
{
	switch(Telegram_getMessage(telegram))
    {
		case kCollision:

			return false;
			break;

		case kBodyStartedMoving:

			Hero_startedMovingOnAxis((Hero)owner, *(int*)Telegram_getExtraInfo(telegram));
			break;

		case kKeyPressed:

			{
				u16 pressedKey = *((u16*)Telegram_getExtraInfo(telegram));

				if((K_LL | K_LR | K_A) & pressedKey)
                {
                    Hero_checkDirection((Hero)owner, pressedKey, "Idle");

                    Hero_startedMovingOnAxis((Hero)owner, __XAXIS);

    				if(K_A & pressedKey)
                    {
                        Hero_jump((Hero)owner, true, true);
    				}

                    return true;
                    break;
				}


				if(K_LU & pressedKey)
                {
                    Hero_checkDirection((Hero)owner, pressedKey, "Back");

                    return true;
                    break;
				}				

				if(K_LD & pressedKey)
                {
                    Hero_checkDirection((Hero)owner, pressedKey, "Front");

                    return true;
                    break;
				}				
			}

		case kKeyHold:
			
			{
				u16 holdKey = *((u16*)Telegram_getExtraInfo(telegram));

				if((K_LL | K_LR) & holdKey)
                {
                    Hero_checkDirection((Hero)owner, holdKey, "Idle");

                    Hero_startedMovingOnAxis((Hero)owner, __XAXIS);

                    return true;
                    break;
				}
			}
			break;
	}

	return false;
}