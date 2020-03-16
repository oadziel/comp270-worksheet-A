#pragma once

#include "Vector2.h"


class Bezier
{
public:
	Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3);

	Vector2 BezierCalc(float t)const;

	void draw(SDL_Renderer *renderer) const;

	const int static bezPrecision = 20;
	Vector2 bezSegments[bezPrecision + 1];
	Vector2 bezTangent[bezPrecision + 1];

private:
	Vector2 p0, p1, p2, p3;
	
};
