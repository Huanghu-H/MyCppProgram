
#include<iostream>
#include<cmath>
#include<windows.h> 
#include<time.h>
using namespace std;

void press(int vk)
{
	keybd_event(vk,0,0,0);
	keybd_event(vk,0,KEYEVENTF_KEYUP,0);
}
int main()
{

	Sleep(5000);
	int i=0; 
	while(i<300) 
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		//Sleep(500); 
		press(82);
		Sleep(50);
		press(82);
		Sleep(50);
		
		cout<<i<<endl; 
		i++;
	}	
	return 0;
}

