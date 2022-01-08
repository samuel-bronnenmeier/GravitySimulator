#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

#include "Texture.h"
#include "InputField.h"
#include "Utils.h"

class Row
{

public:

    Row();

    ~Row();

    void init(int x, int y, Font font, SDL_Renderer* renderer, std::string text);

    void handleEvent(SDL_Event &e);

    void update();

    void render(SDL_Renderer* renderer);

    void destroy();

    int getValue();

private:

    //The row's position
    Point mPos;

    //The text texture
    LTexture* mTextTexture;

    //The InputField
    InputField* mField;

};