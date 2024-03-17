#include <iostream>

#include "Core.h"
#include "ErrorHandler.h"

#include "../tests/UnitTests.h"
#include "../tests/PresetTests.h"

int main()
{
	/*Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);
	Onyx::Demo();
	Onyx::Terminate();*/

	PresetTests::RunAllTests();
	
	return 0;
}
