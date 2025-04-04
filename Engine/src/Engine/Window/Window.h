#pragma once

#include "GLFW/glfw3.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, const char* title);
	~Window();

	void Init();
	void SwapBuffers();
	void CreateWindow();
	bool IsOpen();

	inline unsigned int GetWidth() const { return _Width; }
	inline unsigned int GetHeight() const { return _Height; }
	inline GLFWwindow* GetWindow() const { return _Window; }

private:
	GLFWwindow* _Window;
	unsigned int _Width, _Height;
	const char* _Title;
};

