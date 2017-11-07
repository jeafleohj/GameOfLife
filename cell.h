#ifndef CELL_H
#define CELL_H
class Cell{
 private:
	bool life;
	int neighbours;
 public:
	Cell();
	Cell(bool);
	int getNeighbours();
	bool getLife();
	void setNeighbours(int);
	void updateState();
	void setLife(bool);
	//	void drawCell();
};
#endif
