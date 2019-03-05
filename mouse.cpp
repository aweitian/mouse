// mouse.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include<iostream>
#include<windows.h>
#include<winuser.h>
using namespace std;

void help()
{
	cout << "mouse move control version 1.0.1 / 2019-03-05" << endl;
	cout << "Usage:" << endl;
	cout << "  mouse move x y" << endl;
	cout << "  mouse click x y" << endl;
	cout << "  mouse dbclick x y" << endl;
	cout << "  mouse rgtclick x y" << endl;
	cout << "        source (https://github.com/aweitian/mouse)" << endl;
}

int main(int argc, char *argv[])
{
	POINT p;
	int x,y;
	if(argc == 4)
	{
		if(strcmp("move",argv[1]) == 0)
		{
			x = atoi(argv[2]);
			y = atoi(argv[3]);
			SetCursorPos(x,y);
			return 0;
		}
		else if(strcmp("click",argv[1]) == 0)
		{
			GetCursorPos(&p);
			x = atoi(argv[2]);
			y = atoi(argv[3]);
			SetCursorPos(x,y);
			mouse_event(MOUSEEVENTF_LEFTDOWN,x,y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,x,y,0,0);
			SetCursorPos(p.x,p.y);
			return 0;
		}
		else if(strcmp("dbclick",argv[1]) == 0)
		{
			GetCursorPos(&p);
			x = atoi(argv[2]);
			y = atoi(argv[3]);
			SetCursorPos(x,y);
			mouse_event(MOUSEEVENTF_LEFTDOWN,x,y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,x,y,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,x,y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,x,y,0,0);
			SetCursorPos(p.x,p.y);
			return 0;
		}
		else if(strcmp("rgtclick",argv[1]) == 0)
		{
			GetCursorPos(&p);
			x = atoi(argv[2]);
			y = atoi(argv[3]);
			SetCursorPos(x,y);
			mouse_event(MOUSEEVENTF_RIGHTDOWN,x,y,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,x,y,0,0);
			SetCursorPos(p.x,p.y);
			return 0;
		}
	} 
	help();
	return 0;
}

