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

#ifndef LANGUAGES_H_
#define LANGUAGES_H_


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

enum LanguageIdentifiers
{
    LANG_EN,
    LANG_DE,
};

enum LanguageStrings
{
    /* Splash Screens */
	STR_PRECAUTION_SCREEN_TITLE,
	STR_PRECAUTION_SCREEN_TEXT,
	STR_AUTOMATIC_PAUSE,
	STR_AUTOMATIC_PAUSE_EXPLANATION,
    STR_AUTOMATIC_PAUSE_TEXT,
    STR_ON,
    STR_OFF,
    STR_LANGUAGE_SELECT,

    /* Level Names */
    STR_LEVEL,
    STR_LEVEL_SCRAPYARD_NAME,
};


#endif