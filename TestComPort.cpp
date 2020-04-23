#include <iostream>
#include <string>
#include <Windows.h>
#include "ComPort.h"
#include "TestComPort.h"
#pragma once

void Test()
{
	std::string ComPort2 = "COM2";
	std::string ComPort3 = "COM3";
	ComPort COM2(ComPort2);
	ComPort COM3(ComPort3);

	if (COM3.OpenPort())
	{
		std::cout << COM3.ComPortName << ": Successfully opened Serial Port" << std::endl;
	}

	if (COM3.SetDTRHigh())
	{
		std::cout << COM3.ComPortName << ": Successfully set DTR HIGH" << std::endl;

	}
	else
	{
		std::cout << COM3.ComPortName << ": Failed to set DTR HIGH" << std::endl;
	}

	if (COM2.OpenPort())
	{
		std::cout << COM2.ComPortName << ": Successfully opened Serial Port" << std::endl;
		if (COM2.IsDSRHigh())
		{
			std::cout << COM2.ComPortName << ": DSR is HIGH" << std::endl;
		}
	}

	Sleep(1000);

	if (COM3.SetDTRLow())
	{
		std::cout << "Succesfully set DTR LOW COM 3" << std::endl;
	}

	if (!COM2.IsDSRHigh())
	{
		std::cout << "DSR is low COM2" << std::endl;
	}
}