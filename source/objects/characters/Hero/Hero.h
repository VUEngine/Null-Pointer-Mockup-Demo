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

#ifndef HERO_H_
#define HERO_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Actor.h>
#include <ParticleSystem.h>
#include <macros.h>


//---------------------------------------------------------------------------------------------------------
// 												MACROS
//---------------------------------------------------------------------------------------------------------

#define HERO_NAME "John Hero"


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

#define Hero_METHODS															\
	Actor_METHODS;

#define Hero_SET_VTABLE(ClassName)												\
	Actor_SET_VTABLE(ClassName);												\
	__VIRTUAL_SET(ClassName, Hero, ready);										\
	__VIRTUAL_SET(ClassName, Hero, die);										\
	__VIRTUAL_SET(ClassName, Hero, doMessage);									\
	__VIRTUAL_SET(ClassName, Hero, handleMessage);								\
	__VIRTUAL_SET(ClassName, Hero, suspend);									\

__CLASS(Hero);

#define Hero_ATTRIBUTES															\
																				\
	/* it is derivated from */													\
	Actor_ATTRIBUTES															\
																				\
	/* feet dust */																\
	ParticleSystem feetDust;													\
																				\
	/* direction of input */													\
	Direction inputDirection;													\


//---------------------------------------------------------------------------------------------------------
// 										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

Hero Hero_getInstance();

__CLASS_NEW_DECLARE(Hero, ActorDefinition* animatedEntityDefinition, int id, const char* const name);

void Hero_constructor(Hero this, ActorDefinition* definition, int id, const char* const name);
void Hero_destructor(Hero this);
void Hero_ready(Hero this);
void Hero_addForce(Hero this, int changedDirection, int axis);
void Hero_stopAddingForce(Hero this);
void Hero_startedMovingOnAxis(Hero this, int axis);
bool Hero_stopMovingOnAxis(Hero this, int axis);
void Hero_move(Hero this);
void Hero_jump(Hero this, int changeState, int checkIfYMovement);
void Hero_addMomentumToJump(Hero this);
void Hero_checkDirection(Hero this, u16 currentPressedKey, char * animation);
void Hero_synchronizeDirectionWithVelocity(Hero this);
void Hero_die(Hero this);
int Hero_processCollision(Hero this, Telegram telegram);
bool Hero_handleMessage(Hero this, Telegram telegram);
int Hero_doMessage(Hero this, int message);
void Hero_suspend(Hero this);


#endif