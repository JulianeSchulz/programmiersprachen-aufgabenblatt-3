#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include <list>
#include <algorithm>
#include <iterator>

//Cirlce class definition
class Circle {
public:
	Circle(Vec2 const& ctr,float r,Color const& clr);
	//getter:
	float 	area() const;
	float	circumference() const;
	float 	radius() const;
	Color 	color() const;
	Vec2 	center() const;
	//setter:
	void 	color(Color const& clr);
	void 	center(Vec2 const& ctr);
	void 	radius(float r);
	//Functions:

	friend bool operator<(Circle const& a, Circle const& b);
	friend bool operator>(Circle const& a, Circle const& b);
	friend bool operator==(Circle const& a, Circle const& b);
private:
	Vec2 	center_;
	float 	radius_;
	Color 	color_;
};
#endif // CIRCLE_HPP


