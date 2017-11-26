#ifndef POINT_H
#define POINT_H
template<typename T>
class Point{
	T x,y,z;
 public:
	Point();
	Point(T,T,T);
	void setX(T);
	void setY(T);
	void setZ(T);
	void setPoint(T,T,T);
	T getX() ;
	T getY() ;
	T getZ() ;
	Point<T> operator+(const Point<T>&)const;
	Point<T> operator-(const Point<T>&)const;
};
#endif
