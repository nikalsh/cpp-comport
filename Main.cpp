#include <Windows.h>
#include <iostream>
#include "ComPort.h";
#include "TestComPort.h"
#include "KeyboardSimulator.h"
#pragma once

int main(int argc, char* argv[])
{
	std::string arg = "COM2";
	if (argc > 1)
	{
		arg = argv[1];
	}

	std::string ComPortName = arg;
	std::cout << "Opening Serial Port: " << ComPortName << std::endl;

	ComPort COM(ComPortName);
	KeyboardSimulator keyboard;

	if (COM.OpenPort()) {
		while (true)
		{
			if (COM.IsDSRHigh())
			{
				keyboard.pressSpacebar();
				Sleep(30);
			}
			else
			{
				keyboard.releaseSpacebar();
			}
			Sleep(50);
		}
	}
	else {
		std::cout << "Could not open port" << std::endl;
	}
	return 0;
}

