#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
#ifndef _WIN32_WINNT 
#define _WIN32_WINNT 0x0501 
#endif 

int main()
{
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetWindowDC(hWnd);
	
	void draw_line(int x0, int y0, int x1, int y1);
	int x0, x1,y0,y1;
	float k;
	cout << "Enter the x0,y0: " << endl;
	cin >> x0 >> y0;
	cout << "Enter the x1,y1: " << endl;
	cin >> x1 >> y1;
    k = (y1 - y0) / (float)(x1 - x0);
	cout << "k=" << k<<endl;
	if (k >= 1){
		cout << "k>1" << endl;
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
		cout << "0<=k<=1" << endl;
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
		cout << "-1.0<=k<=0" << endl;
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
		cout << "k<-1" << endl;
		int y, x = x0;
		int dx = 2 * (x1 - x0), dy = 2 * (y1 - y0);
		int dydx = dy + dx, F = dx + dy / 2;
		for (y = y0; y > y1; y--){
			SetPixel(hDC, x, y, RGB(255, 255, 255));
			if (F > 0)F -= dx;
			else{ x++; F -= dydx; }
		}
	}
	ReleaseDC(hWnd, hDC);
	system("pause");
	return 0;
}
