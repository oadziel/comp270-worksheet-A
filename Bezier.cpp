#include "stdafx.h"
#include "Bezier.h"

Vector2 Bezier::BezierCalc(float t)const
{
	//New Calculated Bezier parameter
	Vector2 paramB = Vector2();
	//Set to new point at every iteration
	Vector2 oldParamB = p0;

	float reducT = (1.0f - t); //reduction parameter
	float reducTPow = pow(reducT,2); //reduction param squared
	float reducTPow3 = pow(reducT, 3); //reduction param cubed
	float tPow = pow(t,2); //t squared
	float tPow3 = pow(t,3); //t cubed

	
	paramB.x = reducTPow3 * p0.x + 3 * reducTPow * t * p1.x + 3 * reducT * tPow * p2.x + tPow3 * p3.x; //Bezier Formula for x
	paramB.y = reducTPow3 * p0.y + 3 * reducTPow * t * p1.y + 3 * reducT * tPow * p2.y + tPow3 * p3.y; //Bezier Formula for y

	//Iterate one forward, next iteration starts with the end of the last
	oldParamB = paramB;
	
	return paramB;
}

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
	//iterate through and calculate bezier by 'BezierCalc'
	for (size_t i = 0; i < bezPrecision + 1; i++)
	{
		float curveParam = float(i) / 20.0f;
		bezSegments[i] = BezierCalc(curveParam);
	}
}


void Bezier::draw(SDL_Renderer *renderer) const
{
	//Iterate through and render each line
	for (size_t i = 0; i < bezPrecision; i++)
	{
		SDL_RenderDrawLineF(renderer, bezSegments[i].x, bezSegments[i].y, bezSegments[i+1].x, bezSegments[i+1].y);
	}
	
}
