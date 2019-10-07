#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	// TODO
	//SDL_RenderDrawLineF(renderer, p0.x, p0.y, p1.x, p1.y);
	//SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
	/*Vector2* points = new Vector2[100];
	for (int i = 0; i < 1; i++)
	{
		points[i].x == ((i + 1) / (i / 100));
	}*/
	/*SDL_RenderDrawPoint(renderer, p0.x, p0.y);
	SDL_RenderDrawPoint(renderer, p1.x, p1.y);
	SDL_RenderDrawPoint(renderer, p2.x, p2.y);
	SDL_RenderDrawPoint(renderer, p3.x, p3.y);*/


	Vector2* points = new Vector2[20];
	
	for (float i = 0; i < 1; i += 0.2)
	{
		int point = i * 5;
		points[point] = (pow(1 - i, 3)*p0) + (3 * pow(1 - i, 2)*(i*p1)) + (3 * (1 - i)*pow(i, 2)*p2) + pow(i, 3)*p3;
	}

	for (int p = 0; p < 100; p++)
	{
		int nP = p + 1;
		if (nP > 20)
		{
			nP = 0;
		}
		SDL_RenderDrawLineF(renderer, points[p].x, points[p].y, points[nP].x, points[nP].y);
	}
	
}
