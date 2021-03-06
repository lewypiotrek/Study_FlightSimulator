#pragma once
#include<string>
#include<iostream>
#include<time.h>
using namespace std;

class Station
{
private:
	string name;
	short x, y;
	short h, m;

public:
	friend class Simulator;
	Station(short h,short m,string name);
	Station();
	~Station();
	void SetCoords(short x, short y);
	void SetTime(short h, short m);
	void SetName(string n);

	// Je�eli parametr 'x' zwr�ci x je�eli 'y' zwr�ci y.
	short GetValue(char v);
	
	// Przecia�enie = 
	Station operator=(const Station &s2)
	{
		this->h = s2.h;
		this->m = s2.m;
		this->name = s2.name;
		this->x = s2.x;
		this->y = s2.y;
		return *this;
	}

	// Przeci��enie << dla wska�nika (dla dynamicznej listy)
	friend ostream & operator<< (ostream & out, Station const * s)
	{
		out << s->name <<" | Hour: " << s->h << ":" << s->m << " | Coordinate:(" << s->x << "," << s->y << ")\n";
		return out;
	}

	// Przeci��enie << dla referencji (dla statycznej listy)
	friend ostream & operator<< (ostream & out, Station const & s)
	{
		out << s.name << " | Hour: " << s.h << ":" << s.m << " | Coordinate:(" << s.x << "," << s.y << ")\n";
		return out;
	}

};

