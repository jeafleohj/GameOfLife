#include "cell.h"
#include <random>
using namespace std;
Cell::Cell()
	:c(0,0,0,0)
{
	std::default_random_engine generator;
	std::bernoulli_distribution dist(0.5);
	life=dist(generator)?true:false;
}
Cell::Cell(GLfloat x,GLfloat y,GLfloat z, GLfloat l, bool b)
	:c(x,y,z, l),life(b)
{}
int Cell::getNeighbours(){return neighbours;}
bool Cell::getLife(){return life;}
void Cell::setLife(bool b){life=b;}
void Cell::updateState(){
#ifdef RULE1
	switch(life){
		case true:
			if(neighbours>5 || neighbours<2){
				life=false;
			}
			break;
		case false:
			if(neighbours<8 && neighbours>6) life=true;
			break;
	}
#elif defined RULE2
	switch(life){
		case true:
			if(neighbours>2 || neighbours<5){
				life=false;
			}
			break;
		case false:
			if(neighbours<7 && neighbours>2) life=true;
			break;
	}

#endif 
}
void Cell::setNeighbours(int n){
	this->neighbours=n;
}
void Cell::drawCell(){
	if(life){
		c.draw();
	}
};
