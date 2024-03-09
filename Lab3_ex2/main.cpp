#include "Canvas.h"
int main()
{
	Canvas ob(50,50);
	ob.FillCircle(10, 10, 5, 'a');
	//ob.Clear();
	//ob.DrawCircle(20, 10, 10, 'a');
	//ob.DrawLine(3,3,3,12,'x');
	//ob.DrawLine(3,12,12,12,'x');
	//ob.DrawLine(12,12,12,3,'x');
	//ob.DrawLine(12,3,3,3,'x');
	ob.Print();
}