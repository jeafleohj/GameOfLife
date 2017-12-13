#include "world.h"
#include <random>
#include <chrono>
#include <thread>
World::World(int n)
	:n(n)
{
	std::default_random_engine generator;
	std::bernoulli_distribution dist(0.06);
	//std::binomial_distribution<int> dist(20,.00001);
	//std::poisson_distribution<int> dist(.0004);

	p=new Cell***[n];
	const GLfloat l=3./n;
	for(int i=0;i<n;i++){
		p[i]=new Cell**[n];
		for(int j=0;j<n;j++){
			p[i][j]=new Cell*[n];
			for(int k=0;k<n;k++){
				p[i][j][k]=new Cell(- n*l/2 +  i*l , - n*l/2 +  j*l , - n*l/2 +  k*l, l, dist(generator) ? true:false );
			}
		}
	}
}
void World::drawWorld(){
	int px[]={
		1, 1, 0,-1,-1,-1, 0, 1, 0, //abajo
		1, 1, 0,-1,-1,-1, 0, 1, //medio
		1, 1, 0,-1,-1,-1, 0, 1, 0  //arriba
		
	};
	int py[]={
		0,-1,-1,-1, 0, 1, 1, 1, 0,
		0,-1,-1,-1, 0, 1, 1, 1,
		0,-1,-1,-1, 0, 1, 1, 1, 0
		
	};
	int pz[]={
		-1,-1,-1,-1,-1,-1,-1,-1,-1,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int z=0;z<n;z++){
				p[i][j][z]->drawCell();
			}
		}
	}
//	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int z=0;z<n;z++){
				int vecinos=0;
				for(int k=0;k<26;k++){
					if( (0<=i+py[k] && i+py[k]<n) && (0<=j+px[k] && j+px[k]<n )&& (0<=z+pz[k] && z+pz[k]<n )&& p[i+py[k]][j+px[k]][z+pz[k]]->getLife() ){
						vecinos++;
					}
				}
				p[i][j][z]->setNeighbours(vecinos);
			}
		}
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int z=0;z<n;z++)
				p[i][j][z]->updateState();
}
