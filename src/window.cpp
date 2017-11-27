#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "world.h"
#include <iostream>
Window::Window(int w,int h,int n,std::string t)
	: mundo(n)
{
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES, 4);
	ventana = glfwCreateWindow( w, h, t.c_str(), NULL, NULL);
	glfwMakeContextCurrent(ventana);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glfwSetMouseButtonCallback(ventana, mouse_callback);
	
}

void Window::mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if(GLFW_PRESS == action){
			// no IMPLEMENTADO
		}
        else if(GLFW_RELEASE == action){
			//no implementado
		}
    }

}


void Window::display(){
	static float alpha=30;
	while ( !glfwWindowShouldClose(ventana) ) {
		GLint w,h;
		glfwGetWindowSize(ventana, &w, &h);
		glViewport(0, 0, w, h);
		
		//glClearColor(.8, .3, 0.75, 1.0);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION_MATRIX);
		glLoadIdentity();
		gluPerspective(60, (double) w/ (double)h, 0.1, 100);

		glMatrixMode(GL_MODELVIEW_MATRIX);
		glTranslatef(0, 0, -5);
		glRotatef(alpha,2,-4,-1);
		//alpha++;
		//Debria estar el draw del cubo
		mundo.drawWorld();
		glfwSwapBuffers(ventana);
	  
		glfwPollEvents();
		//glEnableClientState(GL_VERTEX_ARRAY);
		//glVertexPointer(3, GL_FLOAT, 0, vertex);
		//glDrawArrays(GL_QUADS, 0,
	}
}
