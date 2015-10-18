#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
#ifndef _WIN32_WINNT 
#define _WIN32_WINNT 0x0501 
#endif 
HWND hWnd = GetConsoleWindow();
HDC hDC = GetWindowDC(hWnd);
int main()
{
	void draw_line(int x0, int y0, int x1, int y1);
	void draw_circle(int x0, int y0, int r);
	draw_circle(200, 200, 100);
	draw_line(100, 100, 300, 300);
	draw_line(100, 300, 300, 100);
	draw_line(200, 50, 200, 350);
	draw_line(50, 200, 350, 200);

	ReleaseDC(hWnd, hDC);
	system("pause");
	return 0;
}
void draw_line(int x0, int y0, int x1, int y1){
    float k = (y1 - y0) / (float)(x1 - x0);
	if (k >= 1){
		int y, x = x0;
		int dx = 2 * (x1 - x0), dy = 2 * (y1 - y0);
		int dydx = dx - dy, F = dx - dy / 2;
		for (y = y0; y < y1; y++){
			SetPixel(hDC, x, y, RGB(255, 255, 255));
			if (F < 0)F += dx;
			else{ x++; F += dydx; }
		}
	}
	else if (k >= 0){
		int x, y = y0;
		int dx = 2 * (x1 - x0), dy = 2 * (y1 - y0);
		int dydx = dy - dx, F = dy - dx / 2;
		for (x = x0; x < x1; x++){
			SetPixel(hDC, x, y, RGB(255, 255, 255));
			if (F < 0)F += dy;
			else{ y++; F += dydx; }
		}
	}
	else if (k > -1){
		int x, y = y0;
		int dx = 2 * (x1 - x0), dy = 2 * (y1 - y0);
		int dydx = dy + dx, F = dy + dx / 2;
		for (x = x0; x < x1; x++){
			SetPixel(hDC, x, y, RGB(255, 255, 255));
			if (F > 0)F += dy;
			else{ y--; F += dydx; }
		}
	}
	else{
		int y, x = x0;
		int dx = 2 * (x1 - x0), dy = 2 * (y1 - y0);
		int dydx = dy + dx, F = dx + dy / 2;
		for (y = y0; y > y1; y--){
			SetPixel(hDC, x, y, RGB(255, 255, 255));
			if (F > 0)F -= dx;
			else{ x++; F -= dydx; }
		}
	}
}
void draw_circle(int x0, int y0, int r){
	int x, y, color = RGB(255, 255, 255);
	x = 0, y = r;
	int d = 1 - r;
	while (y > x){
		if (d < 0){
			d += 2 * x + 3;
		}
		else{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		SetPixel(hDC, x + x0, y + y0, color);
		SetPixel(hDC, -x + x0, y + y0, color);
		SetPixel(hDC, -x + x0, -y + y0, color);
		SetPixel(hDC, x + x0, -y + y0, color);
		SetPixel(hDC, y + x0, x + y0, color);
		SetPixel(hDC, -y + x0, x + y0, color);
		SetPixel(hDC, -y + x0, -x + y0, color);
		SetPixel(hDC, y + x0, -x + y0, color);
	}
}