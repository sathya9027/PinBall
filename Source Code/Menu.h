#pragma once
class Menu
{
private:
	Sprite title;
	Sprite start;
	Sprite exit;
	Sprite gameOver;
	Sprite playAgain;
	Sprite levelCompleted;
public:
	Menu();
	~Menu();
	void InitSprite();
	void StartMenu(Shader shader);
	void EndMenu(Shader shader);
	void WinMenu(Shader shader);
};

