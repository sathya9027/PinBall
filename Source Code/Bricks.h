#pragma once
class Bricks
{
private:
	Sprite brick;
public:
	Bricks();
	~Bricks();
	void InitSprite(int type);
	Sprite getBrick(int rand);
};

