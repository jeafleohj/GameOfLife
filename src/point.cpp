#include "point.h"
#include <GL/glew.h>
template<typename T>
Point<T>::Point(){
	x=y=z=0;
}

template<typename T>
Point<T>::Point(T _x,T _y,T _z)
	:x(_x),y(_y),z(_z)
{};

template<typename T>
void Point<T>::setX(T _x){x=_x;}

template<typename T>
void Point<T>::setY(T _y){y=_y;}

template<typename T>
void Point<T>::setZ(T _z){z=_z;}

template<typename T>
void Point<T>::setPoint(T x,T y,T z){
	setX(x);
	setY(y);
	setZ(z);
}

template<typename T>
T Point<T>::getX(){return x;}

template<typename T>
T Point<T>::getY(){return y;}

template<typename T>
T Point<T>::getZ(){return z;}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& b)const{
	Point<T> r(x+b.x,y+b.y,z+b.z);
	return r;
}
template<typename T>
Point<T> Point<T>::operator-(const Point<T>& b)const{
	Point<T> r(x-b.x,y-b.y,z-b.z);
	return r;
}
template class Point<GLfloat>;
