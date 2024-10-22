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

#ifndef CONFIG_H_
#define CONFIG_H_

//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Oop.h>


//---------------------------------------------------------------------------------------------------------
// 										DEBUGGING TOOLS
//---------------------------------------------------------------------------------------------------------

#ifdef __DEBUG
#define __PRINT_FRAMERATE
#define __PRINT_MEMORY_POOL_STATUS
#define __DEBUG_TOOLS
#define __STAGE_EDITOR
#define __ANIMATION_EDITOR
//#define __ALERT_STACK_OVERFLOW
#endif


//---------------------------------------------------------------------------------------------------------
// 										OPTICS / PROJECTION
//---------------------------------------------------------------------------------------------------------

// screen width in pixels
#define __SCREEN_WIDTH							384

// screen height in pixels
#define __SCREEN_HEIGHT							224

// screen depth in pixels
#define __SCREEN_DEPTH							0

// z position of the screen
#define __ZZERO									0

// game world limit to unload entities
#define __Z_GAME_LIMIT							__ZZERO - 30

// lowest possible z coordinate
#define __ZLOWLIMIT 							-200

// distance from player's eyes to the virtual screen
#define __DISTANCE_EYE_SCREEN					384

// maximum view distance (Depth)
// always use a power of 2 as the maximum view distance, and update the number of bits to make projection faster
#define __MAXIMUM_VIEW_DISTANCE_POWER			9

// distance between eyes
#define __BASE_FACTOR							768

// player's eyes' horizontal position
#define __HORIZONTAL_VIEW_POINT_CENTER			192

// player's eyes' vertical position
#define __VERTICAL_VIEW_POINT_CENTER			112

// zoom factor to distortoine zooming
#define __ZOOM_FACTOR							0.2f

// parallax values are divide by this factor to control their strength
#define __PARALLAX_CORRECTION_FACTOR			20


//---------------------------------------------------------------------------------------------------------
// 										FRAME RATE CONTROL
//---------------------------------------------------------------------------------------------------------

// determine whether frame rate is capped or not
#define __CAP_FPS					1

// clock resolution
#define __TIMER_RESOLUTION			10

// target frames per second
// must be a muliple of 50 to being able to use a timer resolution greater than 1
// if finer control is needed, change timer resolution to 1
#define __TARGET_FPS 				50

// target frames per second
#define __OPTIMUM_FPS 				__TARGET_FPS

// target frames per second
#define __MINIMUM_GOOD_FPS 			(__TARGET_FPS - 0)

#define __MILLISECONDS_IN_SECOND	1000

// set animation delays as if they are 60 FPS, and multiply by this factor
#define __FPS_ANIM_FACTOR 			(__TARGET_FPS / (float)__OPTIMUM_FPS)

// seconds that must elapse to call rest state (in seconds)
#define __REST_DELAY 				900 // 15 minutes

// if defined, user input is only read in the Game's update logic cycle;
// otherwise, it is read on each pass of the Game's main update loop, ensuring
// that no user's input is lost, but introducing a considerable lost of loop's 
// passes because of the delay needed to read the keypad
#define __POLL_USER_INPUT_ONLY_ON_LOGIC_CYCLE


//---------------------------------------------------------------------------------------------------------
// 										ANIMATION
//---------------------------------------------------------------------------------------------------------

// max length of an animation function's name
#define __MAX_ANIMATION_FUNCTION_NAME_LENGTH	20

// max number of frames per animation function
#define __MAX_FRAMES_PER_ANIMATION_FUNCTION		32

// max number of animation functions per description
#define __MAX_ANIMATION_FUNCTIONS				32


//---------------------------------------------------------------------------------------------------------
// 										MEMORY POOL
//---------------------------------------------------------------------------------------------------------

// reset to 0 each byte of each free block on reseting game
// only use for debugging, proper object's initialization must make this macro unnecessary
#undef __MEMORY_POOL_CLEAN_UP

#define __MEMORY_POOLS		11

#define __MEMORY_POOL_ARRAYS													\
	__BLOCK_DEFINITION(180, 1)													\
	__BLOCK_DEFINITION(164, 2)													\
	__BLOCK_DEFINITION(160, 2)													\
	__BLOCK_DEFINITION(132, 44)													\
	__BLOCK_DEFINITION(112, 16)													\
	__BLOCK_DEFINITION(96, 40)													\
	__BLOCK_DEFINITION(76, 24)													\
	__BLOCK_DEFINITION(68, 80)													\
	__BLOCK_DEFINITION(28, 280)													\
	__BLOCK_DEFINITION(20, 512)													\
	__BLOCK_DEFINITION(16, 256)													\

#define __SET_MEMORY_POOL_ARRAYS												\
	__SET_MEMORY_POOL_ARRAY(180)												\
	__SET_MEMORY_POOL_ARRAY(164)												\
	__SET_MEMORY_POOL_ARRAY(160)												\
	__SET_MEMORY_POOL_ARRAY(132)												\
	__SET_MEMORY_POOL_ARRAY(112)												\
	__SET_MEMORY_POOL_ARRAY(96)													\
	__SET_MEMORY_POOL_ARRAY(76)													\
	__SET_MEMORY_POOL_ARRAY(68)													\
	__SET_MEMORY_POOL_ARRAY(28)													\
	__SET_MEMORY_POOL_ARRAY(20)													\
	__SET_MEMORY_POOL_ARRAY(16)													\

// percentage (0-100) above which the MemoryPool's status shows the pool usage
#define __MEMORY_POOL_WARNING_THRESHOLD	85


//---------------------------------------------------------------------------------------------------------
// 										CHAR MANAGEMENT
//---------------------------------------------------------------------------------------------------------

// number of char segments
// the fourth segment is used for text allocation, changing this value to 4 may cause text corruption
#define __CHAR_SEGMENTS					3

// number of chars per char segment
#define __CHAR_SEGMENT_TOTAL_CHARS 		512


//---------------------------------------------------------------------------------------------------------
// 										SPRITE MANAGEMENT
//---------------------------------------------------------------------------------------------------------

// total number of layers (basically the number of Worlds)
#define __TOTAL_LAYERS			32


//---------------------------------------------------------------------------------------------------------
// 										TEXTURE MANAGEMENT
//---------------------------------------------------------------------------------------------------------

// bgmaps to use (leave 2 bgmaps to allocate param table)
#define __TOTAL_NUMBER_OF_BGMAPS_SEGMENTS 	14

// bgmaps to use (leave 2 bgmaps to allocate param table)
#define __MAX_NUMBER_OF_BGMAPS_SEGMENTS 	(__TOTAL_NUMBER_OF_BGMAPS_SEGMENTS - 1)

// number of bgmap definitions in each bgmap segment
#define __NUM_BGMAPS_PER_SEGMENT 			16

// number of bgmap segments for dynamically allocated textures when preloading
#define __NUMBER_OF_BGMAPS_SEGMENTS_ROOM 	1

// printing area
#define __PRINTING_BGMAP_X_OFFSET			0
#define __PRINTING_BGMAP_Y_OFFSET			0
#define __PRINTING_BGMAP_Z_OFFSET			__ZZERO
#define __PRINTABLE_BGMAP_AREA 				(64 * 28)

#define __PALETTE_MASK						0x0600
#define __WORLD_LAYER_MASK					0x01F0
#define __SEGMENT_MASK						0x000F

#define __PALETTE_MASK_DISP					0x09 /* 6 */
#define __WORLD_LAYER_MASK_DISP				0x04 /* 1 */
#define __SEGMENT_MASK_DISP					0x00 /* 0 */


//---------------------------------------------------------------------------------------------------------
// 										PARAM TABLE
//---------------------------------------------------------------------------------------------------------

// param table for affine and hbias render
#define __PARAM_TABLE_END 					0x0003D800

// maximum possible scale: affects param table allocation space
#define __MAXIMUM_SCALE						2

// maximum number of rows to write on each call to affine calculation functions
#define __MAXIMUM_AFFINE_ROWS_PER_CALL		20


//---------------------------------------------------------------------------------------------------------
// 										    STREAMING
//---------------------------------------------------------------------------------------------------------

// the number of total calls to the streaming method which completes a cycle
// there are 4 parts for the streaming algorithm:
// 1) unload entities
// 2) select the next entity to load
// 3) create the selected entity
// 4) initialize the loaded entity
#define __STREAM_CYCLE_DURATION		24

// pad to determine if an entity must be loaded/unloaded 
// load pad must always be lower than unload pad!
// too close values will put the streaming under heavy usage!
#define __ENTITY_LOAD_PAD 			192
#define __ENTITY_UNLOAD_PAD 		(__ENTITY_LOAD_PAD + 32)

// the number of entities in the stage's definition to check for streaming in on each preload cycle
// since there are 32 layers, that's the theoretical limit of entities to display
#define __STREAMING_AMPLITUDE		16


//---------------------------------------------------------------------------------------------------------
// 										PHYSICS
//---------------------------------------------------------------------------------------------------------

// physical friction
#define __NO_FRICTION 				0.0f
#define __FLOOR_FRICTION 			10.0f
#define __AIR_FRICTION 				50.0f

#define __GRAVITY					9800

#define __MAX_SHAPES_PER_LEVEL		32
#define __MAX_BODIES_PER_LEVEL		32


//---------------------------------------------------------------------------------------------------------
// 										SOUND
//---------------------------------------------------------------------------------------------------------

// channels per bgms
#define __BGM_CHANNELS			2

// channels per fx
#define __FX_CHANNELS			1

// simultaneous bgms
#define __BGMS					1

// simultaneous fx
#define __FXS					2

#define __TOTAL_SOUNDS			(__BGMS + __FXS)
#define __LEFT_EAR_CENTER		96
#define __RIGHT_EAR_CENTER		288


//---------------------------------------------------------------------------------------------------------
// 										COLOR PALETTES
//---------------------------------------------------------------------------------------------------------

#define __PRINTING_PALETTE		3


//---------------------------------------------------------------------------------------------------------
// 									LOW BATTERY INDICATOR
//---------------------------------------------------------------------------------------------------------

// when this is defined, the engine's default low battery indicator is used
#define __LOW_BATTERY_INDICATOR

// position of low battery indicator
#define __LOW_BATTERY_INDICATOR_POS_X			45
#define __LOW_BATTERY_INDICATOR_POS_Y			1

// delay between showing/not showing the low battery indicator (in milliseconds)
#define __LOW_BATTERY_INDICATOR_BLINK_DELAY		500

// wait this long after first receiving the PWR signal before showing the low battery indicator
// (in milliseconds)
#define __LOW_BATTERY_INDICATOR_INITIAL_DELAY	2000


//---------------------------------------------------------------------------------------------------------
// 										AUTOMATIC PAUSE
//---------------------------------------------------------------------------------------------------------

// amount of time after which to show auto pause (in milliseconds)
#define __AUTO_PAUSE_DELAY			(30 * 60 * 1000)

// the automatic pause state is not pushed until there is only one state in the game's stack.
// the following defines the time between checks whether the condition is met (in milliseconds)
#define __AUTO_PAUSE_RECHECK_DELAY	(60 * 1000)


//---------------------------------------------------------------------------------------------------------
// 											FONTS
//---------------------------------------------------------------------------------------------------------

// when this is defined, custom fonts are loaded instead of the default one
#define __CUSTOM_FONTS


//---------------------------------------------------------------------------------------------------------
// 									RANDOM NUMBER GENERATION
//---------------------------------------------------------------------------------------------------------

// how many times the randomSeed function cycles generate a random seed
#define __RANDOM_SEED_CYCLES		2


//---------------------------------------------------------------------------------------------------------
// 											EXCEPTIONS
//---------------------------------------------------------------------------------------------------------

#define __EXCEPTION_COLUMN	0
#define __EXCEPTION_LINE	0


#endif