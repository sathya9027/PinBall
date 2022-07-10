#pragma once
class CoreGame
{
private:
	Sprite playerPaddle;
	Sprite ball;
	Bricks brick;
	vector<Sprite> bricks;
	vector<vec2> bricksPos;
	vec2 ballPos;
	vec2 playerPaddlePos;
	vec2 brickPos;
	float playerSpeed;
	float ballSpeed;
	bool isCollided;
	int dirX, dirY;
	int temp;
	int box;
	bool isgameOver;
	void PlayerMovement(Window window);
	void BallMovement(Window window);
	void RenderMech(Shader shader);
public:
	CoreGame();
	~CoreGame();
	void InitSprite();
	void InitGameMech(Window window);
	void UpdateGamePlay(Window window, Shader shader);
	void Reset(Window window);
	bool IsGameOver();
	bool IsGameWin();
};

