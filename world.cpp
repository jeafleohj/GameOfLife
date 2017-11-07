#include<random>
#include"world.h"
World::World(int n){
	std::random_device r;
	world.resize(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			world[i].emplace_back(r()%2?true:false,i,j);
		}
	}
}
void World::start(){
	
}
