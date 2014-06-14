/*
  SDL_ttf:  A companion library to SDL for working with TrueType (tm) fonts
  Copyright (C) 2001-2012 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/* This library is a wrapper around the excellent FreeType 2.0 library,
   available at:
	http://www.freetype.org/
*/
/*
  severely hacked "lite" version for rendering glyphs only with SDL2

*/

#ifndef _SDL_TTF_H
#define _SDL_TTF_H

#include <SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

// used instead of SDL_Surface
struct TTF_Glyph {
  unsigned w, h, y_offset;
  Uint32* pixels;
};

/* The internal structure containing font information */
typedef struct _TTF_Font TTF_Font;

/* Initialize the TTF engine - returns 0 if successful, -1 on error */
extern DECLSPEC int SDLCALL TTF_Init(void);

/* Open a font file and create a font of the specified point size.
 * Some .fon fonts will have several sizes embedded in the file, so the
 * point size becomes the index of choosing which size.  If the value
 * is too high, the last indexed size will be the default. */
extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontIndexRW(SDL_RWops *src, int freesrc, int ptsize, long index);

/* Set and retrieve the font style */
#define TTF_STYLE_NORMAL	0x00
#define TTF_STYLE_BOLD		0x01
#define TTF_STYLE_ITALIC	0x02
#define TTF_STYLE_UNDERLINE	0x04
#define TTF_STYLE_STRIKETHROUGH	0x08
extern DECLSPEC int SDLCALL TTF_GetFontStyle(const TTF_Font *font);
extern DECLSPEC void SDLCALL TTF_SetFontStyle(TTF_Font *font, int style);

/* Create a 32-bit ARGB surface and render the given glyph at high quality,
   using alpha blending ^^^to dither the font with the given color.^^^
   The glyph is rendered without any padding or centering in the X
   direction, and aligned normally in the Y direction.
   This function returns the new surface, or NULL if there was an error.
*/
extern DECLSPEC TTF_Glyph* SDLCALL TTF_RenderGlyph_Blended(TTF_Font *font, Uint16 ch);

extern DECLSPEC void SDLCALL TTF_FreeGlyph(TTF_Glyph* data);

/* Close an opened font file */
extern DECLSPEC void SDLCALL TTF_CloseFont(TTF_Font *font);

/* De-initialize the TTF engine */
extern DECLSPEC void SDLCALL TTF_Quit(void);

/* Check if the TTF engine is initialized */
extern DECLSPEC int SDLCALL TTF_WasInit(void);

/* We'll use SDL for reporting errors */
#define TTF_SetError	SDL_SetError
#define TTF_GetError	SDL_GetError

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif


#endif /* _SDL_TTF_H */
