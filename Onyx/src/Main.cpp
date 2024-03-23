#include <iostream>

#include "Core.h"
#include "ErrorHandler.h"

#include "../tests/UnitTests.h"
#include "../tests/PresetTests.h"

int main()
{
	PresetTests::RunAllTests();
	
	return 0;
}
