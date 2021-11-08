#include "source.h"
#include <chrono>
#include <string>
#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
using std::string;
bool IsDebug = false;

//codigo da janela#############
struct winsizestruct winsize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	winsizestruct returnthis;
	returnthis.Wcollumns = columns;
	returnthis.Wrows = rows;
	return returnthis;
}
//############################


//codigo do loop de detectar teclas de modo assincrono
void asynckey()
{
	while (true)
	{
		std::cout << char(_getch()) << "\n";
	}
}
//####################################
//
//codigo de renderizacao da janela
void renderwindow(int offsetup, int offsetdown, bool alt)
{
	while (true)
	{
		int Wcollumns = winsize().Wcollumns; int Wrows = winsize().Wrows;

		if (alt) {
			for (int i = 0; i <= offsetup; i++) {
				std::cout << "\n";
			}
			for (int i = 0; i < Wcollumns; i++)
			{
				std::cout << "+";
			}
			std::cout << "\n";
			for (int i = offsetdown; i < Wrows; i++)
			{
				std::cout << "+";
				for (int i = 2; i < Wcollumns; i++)
				{
					std::cout << " ";
				}
				std::cout << "+";
				std::cout << "\n";

			}
			for (int i = 0; i < Wcollumns; i++)
			{
				std::cout << "+";
			}
		}
		std::cout << std::string(offsetup, '\n') << std::endl;
		std::cout << std::string(Wcollumns, '*') << std::endl;
		for (int i = offsetdown; i < Wrows; i++) {
			std::cout << "*";
			std::cout << std::string(Wcollumns - 2, ' ');
			std::cout << "*";
		}
		std::cout << std::string(Wcollumns, '*') << std::endl;
		std::cout << " rows= " << Wrows << " columns =" << Wcollumns << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");

	}
}