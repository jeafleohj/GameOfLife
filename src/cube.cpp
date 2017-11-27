#include "cube.h"
#include "point.h"
#include <GL/glew.h>
#include <iostream>
using namespace std;
bool Cube::checkCube(Point<GLfloat> _p[8]){
	
}
Cube::Cube(){
	//Something
}
Cube::Cube(Point<GLfloat> _p[8]){
	//Si los puntos no forman un cubo, se inicializa como un cubo degenerado
	if( checkCube( _p ) ){
	}
	
}
//Centro de cubo, con el ancho
Cube::Cube(Point<GLfloat> pt,GLfloat l)
//	: p[0](l,-l,l),p[1](l,l,l),p[2](l,l,-l),p[3](l,-l,-l),p[4](-l,l,l),p[5](-l,l,l),p[6](-l,l,-l),p[7](-l,-l,-l)
{
	p[0].setPoint( l/2 , -l/2 , l/2 );
	p[1].setPoint( l/2 , l/2 , l/2 );
	p[2].setPoint( l/2 , l/2 , -l/2 );
	p[3].setPoint( l/2 , -l/2 , -l/2 );

	p[4].setPoint( -l/2 , -l/2 , l/2 );
 	p[5].setPoint( -l/2 , l/2 , l/2 );
	p[6].setPoint( -l/2 , l/2 , -l/2 );
	p[7].setPoint( -l/2 , -l/2 , -l/2 );
	for(int i=0;i<8;i++){
		p[i]=p[i]+pt;
	}
}
Cube::Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat l){
	p[0].setPoint( l/2 , -l/2 , l/2 );
	p[1].setPoint( l/2 , l/2 , l/2 );
	p[2].setPoint( l/2 , l/2 , -l/2 );
	p[3].setPoint( l/2 , -l/2 , -l/2 );

	p[4].setPoint( -l/2 , -l/2 , l/2 );
 	p[5].setPoint( -l/2 , l/2 , l/2 );
	p[6].setPoint( -l/2 , l/2 , -l/2 );
	p[7].setPoint( -l/2 , -l/2 , -l/2 );
	Point<GLfloat> pt(x,y,z);
	for(int i=0;i<8;i++){
		p[i]=p[i]+pt;
	}
}
Point<GLfloat>* Cube::getCaras(){
	Point<GLfloat> c[]={
		p[0], p[1], p[2], p[3],
		p[4], p[5], p[6], p[7],
		p[0], p[1], p[5], p[4],
		p[3], p[2], p[6], p[7],
		p[0], p[4], p[7], p[3],
		p[1], p[5], p[6], p[2]
	};
	Point<GLfloat> *m=new Point<GLfloat>[24];
	for(int i=0;i<24;i++){
		m[i]=c[i];
	}
	return m;
}

void Cube::draw(){

	Point<GLfloat> *m=getCaras();
	GLfloat colores[]={
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3,GL_FLOAT, 0, m);
	glColorPointer(3,GL_FLOAT, 0, colores);
	glDrawArrays(GL_QUADS,0,24);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	delete[] m;

}	
