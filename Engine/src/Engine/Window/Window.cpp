#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const char* title)
	: _Width(width), _Height(height), _Title(title)
{
	Init();
	CreateWindow();
}

Window::~Window()
{
	glfwDestroyWindow(_Window);
	glfwTerminate();
}

void Window::Init()
{
	int success = glfwInit();
	if (!success) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::CreateWindow()
{
	_Window = glfwCreateWindow(_Width, _Height, _Title, NULL, NULL);
	if (_Window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_Window);
	glfwSwapInterval(1);
}

bool Window::IsOpen()
{
	return !glfwWindowShouldClose(_Window);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(_Window);
	glfwPollEvents();
}