#ifndef CUBE_H
#define CUBE_H
#include "point.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Cube{
	Point<GLfloat> p[8];
	//Crear un color para cubito
	//Verifica si los puntos hacen un cubo, si es no se crea el cubo vacio con
	//un error
	bool checkCube(Point<GLfloat> [8]);
 public:
	Cube();//Cubo degenerado, un punto en el origen
	Cube(Point<GLfloat> [8]);
	Cube(Point<GLfloat>, GLfloat);//Centro del cubo y su ancho mitad
	Cube(GLfloat,GLfloat,GLfloat, GLfloat);//Centro del cubo y su ancho mitad
	Point<GLfloat>* getCaras();
	void draw();
};
#endif
