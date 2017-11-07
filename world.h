#include"cell.h"
#include<vector>
#ifndef WORLD_H
#define WORLD_H
class World{
 private:
	std::vector<std::vector<Cell>> world;
	void update();
	void draw();
 public:
	World(int);
	void start();

};
#endif
