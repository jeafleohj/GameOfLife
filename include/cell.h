#ifndef CELL_H
#define CELL_H
#include <GL/glew.h>
#include "cube.h"
class Cell{
 private:
	Cube c;
	bool life;
	int neighbours;

 public:
	Cell();
	Cell(GLfloat ,GLfloat ,GLfloat ,GLfloat ,bool);
	int getNeighbours();
	bool getLife();
	void setNeighbours(int);
	void setLife(bool);
	void updateState();
	void drawCell();
};
#endif
