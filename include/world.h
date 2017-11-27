#ifndef WORLD_H
#define WORLD_H
#include "cell.h"
class World{
	int n;
	Cell ****p;
 public:
	World(int);
	void drawWorld();
	

};
#endif
