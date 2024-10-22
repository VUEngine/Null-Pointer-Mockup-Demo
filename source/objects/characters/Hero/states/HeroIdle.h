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

#ifndef HERO_IDLE_H_
#define HERO_IDLE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <StateMachine.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

// declare the virtual methods
#define HeroIdle_METHODS									\
	State_METHODS;									

// declare the virtual methods which are redefined
#define HeroIdle_SET_VTABLE(ClassName)						\
	State_SET_VTABLE(ClassName)								\
	__VIRTUAL_SET(ClassName, HeroIdle, enter);				\
	__VIRTUAL_SET(ClassName, HeroIdle, execute);			\
	__VIRTUAL_SET(ClassName, HeroIdle, exit);				\
	__VIRTUAL_SET(ClassName, HeroIdle, handleMessage);		\
	
__CLASS(HeroIdle);

#define HeroIdle_ATTRIBUTES				\
										\
	/* inherits */						\
	State_ATTRIBUTES


//---------------------------------------------------------------------------------------------------------
// 										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

// setup the init focus screen
HeroIdle HeroIdle_getInstance();


#endif