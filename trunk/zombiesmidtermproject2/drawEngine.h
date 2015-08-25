/*#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H
#include <iostream>

using namespace std;



class DrawEngine
{
public:
	DrawEngine(int xSize = 30, int ySize = 20);
	~DrawEngine();

	int createSprite(int index, char c);
	void deleteSprite(int index);

	void eraseSprite(int posx, int posy);
	void drawSprite(int index, int posx, int posy);

	void createBackgroundTile(int index, char c);
	void setMap(char **);
	void drawBackground(void);

	//SDL_Surface *load_image( std::string filename );
	//void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

protected:
	char **map;
	int screenWidth, screenHeight;
	char spriteImage[16];
	char tileImage[16];
private:
	void gotoxy(int x, int y);
	void cursorVisibility(bool visibility);
};



#endif*/