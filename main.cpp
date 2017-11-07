#include<iostream>
#include<vector>
#include<random>
#include<string>
#include<chrono>
#include<thread>
#include<curses.h>
#include"cell.h"
#include<utility>
using namespace std;
int M=COLS,N=LINES;
void fillMat(vector<vector<Cell>> &m);
void init(vector<vector<Cell>> &m);
void menu();
int main()
{
	menu();
	vector<vector<Cell>> world(N);
	fillMat(world);
	init(world);
    return 0;
}
void fillMat(vector<vector<Cell>> &m){
	default_random_engine generator;
	bernoulli_distribution distribution(0.075);
	//uniform_int_distribution<int> distribution(0,3);
	//default_random_engine generator;
	//uniform_int_distribution<int> distribution(0,1);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			//m[i].push_back(Cell(distribution(generator)?true:false,i,j ));
			m[i].emplace_back(distribution(generator)?true:false);
		}
	}
}
//simple test
void init(vector<vector<Cell>> &m){
	int px[8]={ 1, 1, 0,-1,-1,-1, 0, 1};
	int py[8]={ 0,-1,-1,-1, 0, 1, 1, 1};
	int ne;
	clear();
	refresh();
	int l=0;
	while(true){
		clear();
		move( 0, 0);
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				ne=0;
				for (int k=0; k<8; k++) {
					if( (0<i+py[k] && i+py[k]<N) && (0<j+px[k] && j+px[k]<M )&& m[i+py[k]][j+px[k]].getLife() ){
						ne++;
					}
				}
				m[i][j].setNeighbours( ne );
			}
		}
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if(m[i][j].getLife()){
					//cout<<"O";
					printw("%s","O");
				}else{
					//cout<<" ";
					printw("%s"," ");
				}
			}
		
		}

		l=(l+1)%N;
		this_thread::sleep_for(chrono::milliseconds(500));
		refresh();
	}
}

void menu(){
	initscr();
	string pp="AVANCE DEL PROYECTO DE POO";
	string men="Presiona enter para continuar";
	M=COLS,N=LINES;
	move( 0, (M-pp.size())/2);
	attron(A_BOLD | A_UNDERLINE);

	printw("%s",pp.c_str());
	refresh();
	move( 10, (M-men.size())/2);
	attroff(A_BOLD | A_UNDERLINE);
	printw("%s",pp.c_str());
	char test[20];

	refresh();
	getstr(test);
	//this_thread::sleep_for(chrono::milliseconds(6000));
	endwin();
}
