#include "Common.h"
Menu::Menu() {

}
Menu::~Menu() {

}
void Menu::InitSprite() {
	title.CreateBuffers(1024 * 0.5, 140 * 0.5);
	title.LoadTexture("Assets\\title.png");

	start.CreateBuffers(1024 * 0.5, 140 * 0.5);
	start.LoadTexture("Assets\\start.png");

	playAgain.CreateBuffers(1024 * 0.5, 140 * 0.5);
	playAgain.LoadTexture("Assets\\playagain.png");

	gameOver.CreateBuffers(1024 * 0.5, 140 * 0.5);
	gameOver.LoadTexture("Assets\\gameOver.png");

	exit.CreateBuffers(1024 * 0.5, 140 * 0.5);
	exit.LoadTexture("Assets\\exit.png");

	levelCompleted.CreateBuffers(1024 * 0.5, 140 * 0.5);
	levelCompleted.LoadTexture("Assets\\levelCompleted.png");
}
void Menu::StartMenu(Shader shader) {
	title.Update(shader);
	title.Draw(shader);
	title.setPosition() = vec2(150, 700);

	start.Update(shader);
	start.Draw(shader);
	start.setPosition() = vec2(100,300);
}
void Menu::EndMenu(Shader shader) {
	title.Update(shader);
	title.Draw(shader);

	playAgain.Update(shader);
	playAgain.Draw(shader);
}
void Menu::WinMenu(Shader shader) {
	levelCompleted.Update(shader);
	levelCompleted.Draw(shader);

	playAgain.Update(shader);
	playAgain.Draw(shader);

}
