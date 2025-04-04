#include "Engine/Window/Window.h"

int main() {
	Window window(800, 600, "OpenGL Window");
	
	while (window.IsOpen()) {
		window.SwapBuffers();
	}
	return 0;
}