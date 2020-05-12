#include "Canvas.h"
#include <stdlib.h>  
#include <iostream>
#include <stdio.h> 
#include<graphics.h>

Canvas::Canvas(int width, int height)
{
	//aloc matricea
	w = width;
	h = height;
	size = w * h;
	matrix = (char*)malloc(size);
	//am alocat matricea
	memset(matrix, ' ', size); //am pus caracterul spatiu in toata matricea
	
}
 
void Canvas::printMatrix() {
	
	
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			std::cout<< *(matrix + i * h+ j);//expresie luata de pe internet pt afisarea unei matrici alocate dinamic 
		}
		std::cout << "\n";
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	float P;
	int x, y, dx, dy;
	x = x1;
	y = y1;
	dx = x2 - x;
	dy = y2 - y;

	P = 2 * dx - dy;
	while (x <= x2) {
		putpixel(x, y);// aici am incercat sa fac cu graphics.h, insa nu sunt sigur daca asa trebuie sau daca macar ar putea functiona in VS
		x++;
		if (P < 0) {
			P = P + 2*dy;
		}
		else {
			P = P + 2 * dy - 2 * dx;
			y++;
		}

	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

	this -> x = x;
	this -> y = y;
	float pixel = 2;
	//
	for (int i = -ray; i <= ray; i++) {
		for (int j = -ray; j <= ray; j++) {
			float d = ((i*pixel) / ray)*((i*pixel) / ray) + (j / ray)*(j / ray);
			if (d > 0.95&&d < 1.08) {// valoare aproximativa 
				std::cout << ch;
			}
		}
	}

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){

}