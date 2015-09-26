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
	int x0, y0,r;
	cout << "Enter the center of the circle:" << endl;
	cin >> x0 >> y0;
	cout << "Enter the radius of the circle:" << endl;
	cin >> r;
	int x, y, color = RGB(255,255,255);
	float e, d;
	e = 3 - 2 * r; 
	x = 0; 
	y = r;
	while (x <= y)
	{
		if (e < 0)
		{
			e = e + 4 * x + 6;
			x++;
		}
		else
		{
			e = e + 4 * (x - y) + 10;
			x++;
			y--;
		}
		SetPixel(hDC, x + x0, y + y0, color);
		SetPixel(hDC, -x + x0, y + y0, color);
		SetPixel(hDC, -x + x0, -y + y0, color);
		SetPixel(hDC, x + x0, -y + y0, color);
		SetPixel(hDC, y + x0, x + y0, color);
		SetPixel(hDC, -y + x0, x + y0, color);
		SetPixel(hDC, -y + x0, -x + y0, color);
		SetPixel(hDC, y + x0, -x + y0, color);
	}
	ReleaseDC(hWnd, hDC);
	system("pause");
	return 0;
}
