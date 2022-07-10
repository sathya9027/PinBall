#include "Common.h"
CoreGame::CoreGame() {
	playerSpeed = 5;
	ballSpeed = 4;
	isCollided = false;
	dirX = 1, dirY = 1;
	temp = 0;
}
CoreGame::~CoreGame() {

}
void CoreGame::Reset(Window window) {
	bricks.clear();
	box = 0;
	isgameOver = false;
	bricksPos.clear();
	playerSpeed = 5;
	ballSpeed = 4;
	isCollided = false;
	dirX = 1, dirY = 1;
	temp = 0;
	ballPos = vec2((window.windowWidth / 2) - ball.getSize().x, (window.windowHeight / 2));
	playerPaddlePos = vec2((window.windowWidth / 2) - (playerPaddle.getSize().x / 2), 0);
	brickPos = vec2(0, window.windowHeight - 44.8);
}
bool CoreGame::IsGameOver(){
	return isgameOver;
}
void CoreGame::PlayerMovement(Window window) {
	if (glfwGetKey(window.gameWindow, GLFW_KEY_A)) {
		if (playerPaddlePos.x > 0) {
			playerPaddlePos.x -= playerSpeed;
		}
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_D)) {
		if (playerPaddlePos.x < (window.windowWidth - playerPaddle.getSize().x)) {
			playerPaddlePos.x += playerSpeed;
		}
	}
	playerPaddle.setPosition() = playerPaddlePos;
}
void CoreGame::RenderMech(Shader shader) {
	playerPaddle.Update(shader);
	playerPaddle.Draw(shader);

	for (int i = 0; i < bricks.size(); i++)
	{
		bricks[i].Update(shader);
		bricks[i].Draw(shader);
	}

	ball.setPosition() = ballPos;
	ball.Update(shader);
	ball.Draw(shader);
}
void CoreGame::BallMovement(Window window) {
	if (isCollided) {
		if ((ballPos.y + ball.getSize().y) >= window.windowHeight) {
			dirY = -1;
		}
		if (ballPos.x <= 0) {
			dirX = 1;
		}
		if (ballPos.y <= 0) {
			isgameOver = true;
		}
		else if ((ballPos.x + ball.getSize().x) >= window.windowWidth) {
			dirX = -1;
		}

		if (ball.RectangleCollision(playerPaddle)) {
			dirY = 1;
		}

		for (int i = 0; i < bricks.size(); i++)
		{
			if (ball.RectangleCollision(bricks[i])) {
				bricks.erase(bricks.begin() + i);
				dirY = -1;
				box++;
			}
		}

		ballPos.y += ballSpeed * dirY;
		ballPos.x += ballSpeed * dirX;
	}
	else {
		ballPos.y -= ballSpeed;
		if (ball.RectangleCollision(playerPaddle)) {
			isCollided = true;
		}
	}
}
void CoreGame::InitSprite() {

	playerPaddle.CreateBuffers(485 * 0.35, 128 * 0.35);
	playerPaddle.LoadTexture("Assets\\43-Breakout-Tiles.png");

	ball.CreateBuffers(50, 50);
	ball.LoadTexture("Assets\\58-Breakout-Tiles.png");
}
void CoreGame::InitGameMech(Window window) {

	playerPaddlePos = vec2((window.windowWidth / 2) - (playerPaddle.getSize().x / 2), 0);
	ballPos = vec2((window.windowWidth / 2) - ball.getSize().x, (window.windowHeight / 2));
	brickPos = vec2(0, window.windowHeight - 44.8);
	for (int i = 0; i < 48; i++)
	{
		bricks.push_back(brick.getBrick(int(rand() % 5)));
		bricksPos.push_back(brickPos);
		brickPos.x += 134.4;
		temp++;
		if (temp == 6) {
			brickPos.y -= 44.8;
			brickPos.x = 0;
			temp = 0;
		}
	}

	for (size_t i = 0; i < bricks.size(); i++)
	{
		bricks[i].setPosition() = bricksPos[i];
	}
}
void CoreGame::UpdateGamePlay(Window window, Shader shader) {
	PlayerMovement(window);
	BallMovement(window);
	RenderMech(shader);
}
bool CoreGame::IsGameWin() {
	return box > 30;
}
