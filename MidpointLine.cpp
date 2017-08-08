#include "Application.h"
#include <iostream>

#define PI  3.1516
void Application::update()
{
	
}

void Application::draw()
{
	int x = 0, y = 0, x0 = 250, y0 = 250; // Corregir luego.
	int alpha;
	for (alpha = 0; alpha < 360; ++alpha) 
	{
		x = (100 * (float)cos(alpha * PI / 180))+ x0;
		y = (100 * (float)sin(alpha * PI / 180))+ y0;
		if (alpha <= 45 && alpha >= 0) //octante 1
			linea(x0,y0,x, y,1);
		else if (alpha <= 90 && alpha > 45)//octante 2 CorregirTodo :)
			linea(y0, x0, y, x, 2);
		else if (alpha > 90 && alpha <= 135)//octante  3
			linea(y0, x0, y, x, 3);
		else if (alpha > 135 && alpha <= 180)//octante 4
			linea(x0, y0, x, y, 4);
		else if (alpha > 180 && alpha <= 225)// octante 5
			linea(x0, y0, x, y, 5);
		else if (alpha > 225 && alpha <= 270)//octante 6
			linea(y0, x0, y, x, 6);
		else if (alpha > 270 && alpha <= 315)//octante 7
			linea(x0, y0, x, y, 7);
		else if (alpha > 315 && alpha <= 360)
			linea(x0, y0, x, y, 8);
	}


	

	
}

void Application::linea(int x0, int y0,int x, int y, int cuadrante)
{
	int dy = (y - x0), dx = (x - y0), E = 2 * dy, NE = 2 * (dy - dx);
	int d = (2 * dy) - dx;
	//putPixel(0, 0, 255, 255, 0, 255);
	putPixel(x0, y0, 255, 255, 0, 255);
	int w = x0 + 1, z = y0;
	while (w <= x)
	{
		if (d > 0)
		{
			++z;
			d += NE;
		}
		else
		{
			d += E;
		}

		// w = x  z = y

		switch (cuadrante)
		{
		case 1:
			putPixel(w, z, 255, 255, 0, 255);
		case 2:
			putPixel(z, w, 255, 255, 0, 255);
		case 3:
			putPixel(-z, w, 255, 255, 0, 255);
		case 4:
			putPixel(-w, z, 255, 255, 0, 255);
		/*case 5:
			putPixel(w, z, 255, 255, 0, 255);
		case 6:
			putPixel(-z, -w, 255, 255, 0, 255);
		case 7:
			putPixel(-z, w, 255, 255, 0, 255);
		case 8:
			putPixel(w, -z, 255, 255, 0, 255);*/
		default: break;
			break;
		}
		
		++w;
	}
}
