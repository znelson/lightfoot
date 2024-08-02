#include <iostream>
#include "app/Application.h"

int main(int inArgCount, char* inArgs[])
{
	std::cout << "Hello, World!" << std::endl;

	int returnCode = 0;

	{
		app::Application app;
		returnCode = app.Run();
	}

	return returnCode;
}
