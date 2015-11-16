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

#ifndef TITLE_SCREEN_STATE_H_
#define TITLE_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SplashScreenState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

// declare the virtual methods
#define TitleScreenState_METHODS												\
	SplashScreenState_METHODS;													\

// declare the virtual methods which are redefined
#define TitleScreenState_SET_VTABLE(ClassName)									\
	SplashScreenState_SET_VTABLE(ClassName)										\
	__VIRTUAL_SET(ClassName, TitleScreenState, print);							\
	__VIRTUAL_SET(ClassName, TitleScreenState, processInput);					\


__CLASS(TitleScreenState);

#define TitleScreenState_ATTRIBUTES												\
														            			\
	/* inherits */																\
	SplashScreenState_ATTRIBUTES												\


//---------------------------------------------------------------------------------------------------------
// 										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

TitleScreenState TitleScreenState_getInstance(void);


#endif