#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <chrono>
using namespace std;

char inputkey, q;
void drawMaze();
void gotocoordinates(int, int);
void move();
void move2();
int mapArrayOne[17][37] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,1,1,1 },
	{ 1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
int mapArrayTwo[31][40] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

int main()
{
	drawMaze();
	move();

	return 0;
}
void drawMaze()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 37; j++)
		{
			switch (mapArrayOne[i][j])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				cout << char(219);
				break;
			case 2:
				cout << " ";
				break;

			}
		}
		cout << " " << endl;  // makes it so the maze doesnt print on a single line
	}

}
void gotocoordinates(int x, int y)
{
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
	//the coords object represents the cursor and the x and y coordinates of the cursor will be equal to the argument i gave in the function parameters
	//the last line sets cursor's position to the coordinates that i gave.

}

void move()
{
	typedef std::chrono::high_resolution_clock Clock;
	auto t1 = Clock::now();
	int x = 1;
	int y = 1;
	int xprevious = 1;
	int yprevious = 1;
	while (q != 'q')
	{
		gotocoordinates(xprevious, yprevious);
		cout << " ";
		gotocoordinates(x, y);
		cout << char(126);

		inputkey = _getch(); //from conio.h
		xprevious = x;
		yprevious = y;
		if (inputkey == 'w')
		{
			y -= 1;
		}
		else if (inputkey == 's')
		{
			y += 1;
		}
		else if (inputkey == 'a')
		{
			x -= 1;
		}
		else if (inputkey == 'd')
		{
			x += 1;
		}

		if (mapArrayOne[y][x] == 1)
		{
			x = xprevious;
			y = yprevious;
		}
		if (mapArrayOne[y][x] == 2)
		{
			auto t2 = Clock::now();
			mapArrayOne[14][30] = 1; //so that the user can't move when finished

			gotocoordinates(0, 16); // go under the maze
			cout << "Congratulations! You finished level 1 in " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " seconds." << endl;
			cout << "Type 2 if you want to proceed to level 2, type q if you want to quit." << endl;
			cin >> q;
		}

		if (q == 'q')
		{
			exit(0);
		}
		else if (q == '2')
		{
			system("cls");

			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 40; j++)
				{
					switch (mapArrayTwo[i][j])
					{
					case 0:
						cout << " ";
						break;
					case 1:
						cout << char(219);
						break;
					case 2:
						cout << " ";
						break;

					}
				}
				cout << " " << endl;
			}
			move2();
		}

	}

}
void move2()
{
	typedef std::chrono::high_resolution_clock Clock;
	auto t1 = Clock::now();
	int x = 1;
	int y = 1;
	int xprevious = 1;
	int yprevious = 1;
	while (q != 'q')
	{
		gotocoordinates(xprevious, yprevious);
		cout << " ";
		gotocoordinates(x, y);
		cout << char(126);

		inputkey = _getch(); //from conio.h
		xprevious = x;
		yprevious = y;
		if (inputkey == 'w')
		{
			y -= 1;
		}
		else if (inputkey == 's')
		{
			y += 1;
		}
		else if (inputkey == 'a')
		{
			x -= 1;
		}
		else if (inputkey == 'd')
		{
			x += 1;
		}

		if (mapArrayTwo[y][x] == 1)
		{
			x = xprevious;
			y = yprevious;
		}
		if (mapArrayTwo[y][x] == 2)
		{
			auto t2 = Clock::now();
			mapArrayTwo[28][16] = 1; //so that the user can't move when finished

			gotocoordinates(0, 30); // go under the maze
			cout << "Congratulations! You finished level 2 in " << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " seconds." << endl;
			cout << "Type in q to quit." << endl;
			cin >> q;
			if (q == 'q')
			{
				exit(0);
			}
		}
	}
}
