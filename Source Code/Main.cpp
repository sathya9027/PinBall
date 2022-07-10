//drawing texture using external vertex and fragment shader(glew)(soil)(glm)

#include "Common.h" //it has all include syntax

//user define function
Window window;		//window class
Shader shader;		//shader class

Sprite mario;			//sprite class
Sprite luigi;			//sprite class

vec2 marioPos = vec2(0.0f, 0.0f);
vec2 luigiPos = vec2(-0.5f, 0.0f);

double xPos, yPos;

//main functiona
int main() {

	window.CreateGameWindow(800, 800, "Game Window", false);

	shader.ShaderInit();
	shader.ProcessShaderFile("FragmentShader.glsl", GL_FRAGMENT_SHADER);
	shader.ProcessShaderFile("VertexShader.glsl", GL_VERTEX_SHADER);

	mario.CreateBuffers(0.5f, 0.5f);
	mario.LoadTexture("mario.png");

	luigi.CreateBuffers(0.3f, 0.3f);
	luigi.LoadTexture("luigi.png");

	do {
		window.SetBGColor(0, 0, 0, 0);

		if (glfwGetKey(window.gameWindow, GLFW_KEY_D) == GLFW_PRESS) {
			marioPos.x += 0.005f;
		}
		if (glfwGetKey(window.gameWindow, GLFW_KEY_A) == GLFW_PRESS) {
			marioPos.x -= 0.005f;
		}
		if (glfwGetKey(window.gameWindow, GLFW_KEY_W) == GLFW_PRESS) {
			marioPos.y += 0.005f;
		}
		if (glfwGetKey(window.gameWindow, GLFW_KEY_S) == GLFW_PRESS) {
			marioPos.y -= 0.005f;
		}

		cout << marioPos.x << marioPos.y << endl;

		mario.setPosition() = marioPos;
		luigi.setPosition() = luigiPos;

		mario.Update(shader);
		mario.Draw(shader);

		luigi.Update(shader);
		luigi.Draw(shader);

		shader.ApplyShader();

		window.UpdateWindow();
	} while (window.IsWindowNotClosed());
	return 0;
}