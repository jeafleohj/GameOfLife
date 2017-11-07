#include"cell.h"
#include<random>
using namespace std;
Cell::Cell(bool b){
	life=b;
}
Cell::Cell(){
	std::default_random_engine generator;
	std::bernoulli_distribution dist(0.5);
	life=dist(generator)?true:false;
}
int Cell::getNeighbours(){return neighbours;}
bool Cell::getLife(){return life;}
void Cell::setLife(bool b){life=b;}
void Cell::updateState(){
	switch(life){
		case true:
			if(neighbours<2){
				life=false;
			}else if(neighbours>3){
				life=false;			
			}
			break;
		case false:
			if(neighbours==3) life=true;
			break;
	}
}
void Cell::setNeighbours(int n){
	this->neighbours=n;
	updateState();
}
