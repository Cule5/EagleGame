#include<exception>
#include<iostream>
#include"Game.h"
#include<Windows.h>
int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	try
	{
		Game game;
		game.Run();
	}
	catch (const std::exception&exception)
	{
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		std::cout << exception.what();
		system("pause");
	}
	return 0;
}