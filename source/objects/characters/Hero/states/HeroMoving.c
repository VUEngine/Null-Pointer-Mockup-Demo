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

#include "HeroMoving.h"
#include "HeroIdle.h"
#include "../Hero.h"

#include <PlatformerLevelState.h>
#include <MessageDispatcher.h>


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

void HeroMoving_constructor(HeroMoving this);
void HeroMoving_destructor(HeroMoving this);
void HeroMoving_enter(HeroMoving this, void* owner);
void HeroMoving_execute(HeroMoving this, void* owner);
void HeroMoving_exit(HeroMoving this, void* owner);
bool HeroMoving_handleMessage(HeroMoving this, void* owner, Telegram telegram);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(HeroMoving, State);
__SINGLETON(HeroMoving);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void HeroMoving_constructor(HeroMoving this)
{
	// construct base
	__CONSTRUCT_BASE();
	
	this->mustCheckDirection = false;
	this->bouncing = false;
}

// class's destructor
void HeroMoving_destructor(HeroMoving this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

// state's enter
void HeroMoving_enter(HeroMoving this, void* owner)
{
	this->mustCheckDirection = false;

#ifdef __DEBUG
	Printing_text(Printing_getInstance(), "HeroMoving::enter   ", 0, (__SCREEN_HEIGHT >> 3) - 2, NULL);
#endif
}

// state's execute
void HeroMoving_execute(HeroMoving this, void* owner)
{
	Hero_synchronizeDirectionWithVelocity(__GET_CAST(Hero, owner));
}

// state's exit
void HeroMoving_exit(HeroMoving this, void* owner)
{
}


// state's on message
bool HeroMoving_handleMessage(HeroMoving this, void* owner, Telegram telegram)
{
	switch(Telegram_getMessage(telegram))
    {
		case kKeyPressed:

			{
				u16 pressedKey = *((u16*)Telegram_getExtraInfo(telegram));

				// check direction
				if((K_LL | K_LR ) & pressedKey)
                {
					Hero_checkDirection((Hero)owner, pressedKey, "Walk");	
				}

				if(K_A & pressedKey)
                {
					Hero_jump((Hero)owner, false, !this->bouncing);			
				}
			}

			return true;
			break;
			
		case kKeyReleased:
			{
				u16 releasedKey = *((u16*)Telegram_getExtraInfo(telegram));

				if((K_LL | K_LR) & releasedKey)
                {
					Velocity velocity = Body_getVelocity(Actor_getBody(__GET_CAST(Actor, owner)));
					
					if(0 < abs(velocity.x))
                    {
						Hero_stopAddingForce((Hero)owner);		
					}
					else
                    {
						StateMachine_swapState(Actor_getStateMachine(__GET_CAST(Actor, owner)), __GET_CAST(State, HeroIdle_getInstance()));
					}
				}
			}
			break;
	
		case kKeyHold:
			{
				u16 holdKey = *((u16*)Telegram_getExtraInfo(telegram));

				// check direction
				if((K_LL | K_LR ) & holdKey)
                {
					Hero_addForce((Hero)owner, this->mustCheckDirection, __XAXIS);					
					this->mustCheckDirection = false;
				}
			}
			break;

		case kBodyStoped:
			
			Hero_stopMovingOnAxis((Hero)owner, *(int*)Telegram_getExtraInfo(telegram));
			break;

		case kBodyStartedMoving:

			{
				int axis = *(int*)Telegram_getExtraInfo(telegram);
				// start movement
				Hero_startedMovingOnAxis((Hero)owner, axis);
			}
			break;

		case kBodyChangedDirection:

			Hero_startedMovingOnAxis((Hero)owner, *(int*)Telegram_getExtraInfo(telegram));
			break;

		case kBodyBounced:
			
			this->mustCheckDirection = true;
			this->bouncing = true;
			MessageDispatcher_dispatchMessage(100, __GET_CAST(Object, this), __GET_CAST(Object, owner), kDisallowJumpOnBouncing, NULL);
			return true;
			break;
			
		case kDisallowJumpOnBouncing:
			
			this->bouncing = false;
			break;
			
		case kCollision:

			return Hero_processCollision((Hero)owner, telegram);
			break;

	}
	return false;
}