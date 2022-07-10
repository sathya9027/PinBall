#include "Common.h"
Window window;
Shader shader;
Camera camera;
Menu menu;
CoreGame coreGame;
enum GameState
{
	START,
	PLAY,
	END,
	WIN
};
int gameState = GameState::START;
void Create() {
	srand(time(NULL));

	window.CreateGameWindow(806, 800, "My Game", false);

	shader.ShaderInit();
	shader.ProcessShaderFile("FragmentShader.glsl", GL_FRAGMENT_SHADER);
	shader.ProcessShaderFile("VertexShader.glsl", GL_VERTEX_SHADER);

	menu.InitSprite();

	coreGame.InitSprite();
	coreGame.InitGameMech(window);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void Render() {
	window.SetBGColor(0.5, 0, 1, 0);

	switch (gameState)
	{
	case GameState::START:
		menu.StartMenu(shader);
		if (glfwGetKey(window.gameWindow, GLFW_KEY_ENTER)) {
			gameState = GameState::PLAY;
		}
		break;
	case GameState::PLAY:
		if (coreGame.IsGameOver()) {
			gameState = GameState::END;
		}
		else if (coreGame.IsGameWin()) {
			gameState = GameState::WIN;
		}
		else {
			coreGame.UpdateGamePlay(window, shader);
		}
		break;
	case GameState::END:
		menu.EndMenu(shader);
		if (glfwGetKey(window.gameWindow, GLFW_KEY_ENTER)) {
			gameState = GameState::PLAY;
			coreGame.Reset(window);
			coreGame.InitGameMech(window);
		}
		break;
	case GameState::WIN:
		menu.WinMenu(shader);
		if (glfwGetKey(window.gameWindow, GLFW_KEY_ENTER)) {
			gameState = GameState::PLAY;
			coreGame.Reset(window);
			coreGame.InitGameMech(window);
		}
		break;
	}

	shader.ApplyShader();
	camera.Update(window, shader);
	window.UpdateWindow();
}
int main() {
	Create();
	do {
		Render();
	} while (window.IsWindowNotClosed());
	return 0;
}