#pragma once
#include "Math.h"

class Pos
{
public:
	Pos();
	Pos(Vec2 _v);
	~Pos();

private:
	Vec2 position;
};
