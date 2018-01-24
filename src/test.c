#include <GLFW/glfw3.h>
#include "ft_printf.h"
#include "scop.h"

void _update_fps_counter(GLFWwindow* window) {
	static double previous_seconds = -1;
	static int frame_count;

	if (previous_seconds == -1)
		previous_seconds = glfwGetTime();
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	if (elapsed_seconds > 1) {
		previous_seconds = current_seconds;
		double fps = (double)frame_count / elapsed_seconds;
		char tmp[128];
		sprintf(tmp, "opengl @ fps: %.2f", fps);
		glfwSetWindowTitle(window, tmp);
		frame_count = 0;
	}
	frame_count++;
}


int main(int ac, char **av)
{
	GLFWwindow* window;

	if (ac < 2)
	{
		ft_printf("scop: not enough arguments");
		return -1;
	}
	read_obj(av[1]);

	/* Initialize the library */
	if (!glfwInit())
	{
		ft_printf("error: couldn't start GLFW");
		return -1;
	}

	ft_printf("GLFW %s started\n", glfwGetVersionString());

	// force 4.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// other hints
	glfwWindowHint(GLFW_SAMPLES, 4);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	ft_printf("OpenGL Renderer: %s\n", glGetString(GL_RENDERER));
	ft_printf("OpenGL Version:  %s\n", glGetString(GL_VERSION));

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		_update_fps_counter(window);
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		// keyboard events
		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, 1);
		}
	}

	glfwTerminate();
	return 0;
}
