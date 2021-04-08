#include "sdlutil.h"

SDL_Texture *TextureFromFile(const char *filename, SDL_Renderer *renderer)
{
	SDL_Texture *texture;
	SDL_Surface *surface;
	if((surface = SDL_LoadBMP(filename)) == NULL)
	{
		printf("SDL_LoadBMP: %s\n", SDL_GetError());
		return NULL;
	}

	if((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
	{
		printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture *TextureFromFont(const char *str, SDL_Renderer *renderer, TTF_Font *font, SDL_Color *color)
{
	SDL_Surface *surface_str;
	SDL_Texture *texture_str;
	if((surface_str = TTF_RenderText_Solid(font, str, *color)) == NULL)
	{
		return NULL;
	}

	texture_str = SDL_CreateTextureFromSurface(renderer, surface_str);
	SDL_FreeSurface(surface_str);
	return texture_str;
}

void DrawFontTexture(SDL_Renderer *r, SDL_Texture *t, int x, int y, Align hAlign, Align vAlign)
{
	int tW, tH;
	SDL_Rect rect;
	SDL_QueryTexture(t, NULL, NULL, &tW, &tH);
	rect.w = tW;
	rect.h = tH;

	switch(hAlign)
	{
		case Align_Center:
			rect.x = x - tW / 2;
			break;

		case Align_Right:
			rect.x = x - tW;
			break;

		default:
			break;
	}

	switch(vAlign)
	{
		case Align_Center:
			rect.y = y - tH / 2;
			break;

		case Align_Right:
			rect.y = y - tH;
			break;

		default:
			break;
	}

	SDL_RenderCopy(r, t, NULL, &rect);
}
