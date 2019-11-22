#include "Globals.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "ModuleFonts.h"


#include<string.h>

ModuleFonts::ModuleFonts() : j1Module()
{}
ModuleFonts::~ModuleFonts()
{}
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if (texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->tex->Load(texture_path);

	if (tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for (; id < MAX_FONTS; ++id)
		if (fonts[id].graphic == nullptr)
			break;

	if (id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	fonts[id].graphic = tex; // graphic: pointer to the texture
	fonts[id].rows = rows; // rows: rows of characters in the texture


	uint width_char = 0;
	uint height_char = 0;

	SDL_QueryTexture((SDL_Texture*)tex, NULL, NULL, (int*)&width_char, (int*)&height_char);

	fonts[id].len = strlen(characters);// len: lenght of the table

	strcpy_s(fonts[id].table, characters);// table: array of chars to have the list of characters

	fonts[id].row_chars = strlen(characters) / rows;// row_chars: amount of chars per row of the texture
	fonts[id].char_w = width_char / fonts[id].row_chars;// char_w: width of each character
	fonts[id].char_h = height_char / rows;// char_h: height of each character

	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if (font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->tex->UnLoad(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bitmap font
void ModuleFonts::BlitText(int x, int y, int font_id, const char* text) const
{
	if (text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	for (uint i = 0; i < len; ++i)
	{

		for (uint j = 0; j <= font->len; j++) {
			if (font->table[j] == text[i]) {
				rect.x = (j % font->row_chars)* font->char_w;
				rect.y = (j / font->row_chars)*font->char_h;

			}

		}
		App->render->Blit(font->graphic, x + (i*font->char_w), y, &rect, 1.0f, false);
	}
}