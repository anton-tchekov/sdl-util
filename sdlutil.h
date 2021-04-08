#ifndef __SDLUTIL_H__
#define __SDLUTIL_H__

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef enum Align
{
	Align_Left,
	Align_Center,
	Align_Right
} Align;

SDL_Texture *TextureFromFile(const char *filename, SDL_Renderer *renderer);
SDL_Texture *TextureFromFont(const char *str, SDL_Renderer *renderer, TTF_Font *font, SDL_Color *color);
void DrawFontTexture(SDL_Renderer *r, SDL_Texture *t, int x, int y, Align hAlign, Align vAlign);

#endif /* __SDLUTIL_H__ */
