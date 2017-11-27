#ifndef WINDOW_H
#define WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "world.h"
class Window{
	GLFWwindow *ventana = nullptr;
	std::string titulo;
	World mundo;
	
public:
	Window(int, int,int,std::string);
	static void mouse_callback(GLFWwindow*, int, int, int);
	void display();
	
};
#endif
