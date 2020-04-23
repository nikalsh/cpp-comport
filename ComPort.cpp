#include "ComPort.h";
#include <iostream>;
#include <Windows.h>

#pragma once

ComPort::ComPort(std::string& ComPortName)
{
	this->ComPortName = ComPortName;
}

ComPort::~ComPort()
{
	try
	{
		ClosePort();
	}
	catch (...)
	{
	}
}

bool ComPort::OpenPort()
{
	//Convert string to wide string
	int wchars_num = MultiByteToWideChar(CP_UTF8, 0, ComPortName.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, ComPortName.c_str(), -1, wstr, wchars_num);

	COM = CreateFile(wstr,				//port name
		GENERIC_READ | GENERIC_WRITE,   //Read/Write
		0,                              // No Sharing
		NULL,                           // No Security
		OPEN_EXISTING,                  // Open existing port only
		0,                              // Non Overlapped I/O
		NULL);

	delete[] wstr;
	if (COM != INVALID_HANDLE_VALUE)
	{
		std::cout << ComPortName << ": Successfully opened Serial Port" << std::endl;
	}
	return COM != INVALID_HANDLE_VALUE;
}
void ComPort::ClosePort()
{
	CloseHandle(COM);
	std::cout << ComPortName << ": Attempting to close Serial Port" << std::endl;
}

bool ComPort::SetDTRHigh()
{
	BOOL DTRStatus;
	DTRStatus = EscapeCommFunction(COM, SETDTR); //Setting the RTS line using EscapeCommFunction();
	if (DTRStatus)
	{
		std::cout << ComPortName << ": DTR set to High" << std::endl;
	}
	return DTRStatus;
}

bool ComPort::SetDTRLow()
{
	BOOL DTRStatus;
	DTRStatus = EscapeCommFunction(COM, CLRDTR);
	if (DTRStatus)
	{
		std::cout << ComPortName << ": DTR set to Low" << std::endl;
	}
	return DTRStatus;
}

bool ComPort::IsDSRHigh()
{
	DWORD dwModemStatus;
	BOOL  fCTS, fDSR, fRING, fRLSD;

	if (GetCommModemStatus(COM, &dwModemStatus))
	{
		fCTS = MS_CTS_ON & dwModemStatus;
		fDSR = MS_DSR_ON & dwModemStatus;
		fRING = MS_RING_ON & dwModemStatus;
		fRLSD = MS_RLSD_ON & dwModemStatus;
		return fDSR;
	}
	return false;
}