#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

#ifndef TEXTURE_H
#define TEXTURE_H

//Class for wrapping textures
class LTexture
{
public:

	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();   

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer* renderer);  

	#if defined(SDL_TTF_MAJOR_VERSION)
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* font, SDL_Renderer* renderer);
	#endif

	//Deallocates texture
	void free();   

	//Modulate the color
	void setColor(Uint8 red, Uint8 green, Uint8 blue); 

	//Set blend mode
	void setBlendMode(SDL_BlendMode blending); 

	//Set alpha channel
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(SDL_Renderer* renderer, SDL_Rect* dstrect, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE); 

	//Gets image dimensions
	int getWidth();
	int getHeight();  

private:

	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

};

#endif