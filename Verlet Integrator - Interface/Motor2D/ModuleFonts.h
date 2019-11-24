#pragma once
#ifndef __ModuleFonts_H__
#define __ModuleFonts_H__

#include "j1Module.h"
#include "SDL\include\SDL_pixels.h"

#define MAX_FONTS 100
#define MAX_FONT_CHARS 256

struct SDL_Texture;

struct Font
{
	char table[MAX_FONT_CHARS];
	SDL_Texture* graphic = nullptr;
	uint rows, len, char_w, char_h, row_chars;
};

class ModuleFonts : public j1Module
{
public:

	ModuleFonts();
	~ModuleFonts();
	int Load(const char* texture_path, const char* characters, uint rows = 1);
	void UnLoad(int font_id);
	void BlitText(int x, int y, int font_id, const char* text) const;

private:

	Font	 fonts[MAX_FONTS];
};


#endif // __ModuleFonts_H__