#include "Common.h"
Bricks::Bricks() {

}
Bricks::~Bricks() {

}
void Bricks::InitSprite(int type) {
	brick.CreateBuffers(384 * 0.35, 128 * 0.35);
	switch (type)
	{
	case 0:
		brick.LoadTexture("Assets\\13-Breakout-Tiles.png");
		break;
	case 1:
		brick.LoadTexture("Assets\\01-Breakout-Tiles.png");
		break;
	case 2:
		brick.LoadTexture("Assets\\03-Breakout-Tiles.png");
		break;
	case 3:
		brick.LoadTexture("Assets\\07-Breakout-Tiles.png");
		break;
	case 4:
		brick.LoadTexture("Assets\\09-Breakout-Tiles.png");
		break;
	}
}
Sprite Bricks::getBrick(int rand) {
	InitSprite(rand);
	return brick;
}
