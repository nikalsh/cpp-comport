
#include <Windows.h>
#include <string>

#pragma once


class ComPort {

	HANDLE COM;

public:
	std::string ComPortName;
	ComPort(std::string& ComPortName);
	~ComPort();

	bool OpenPort();
	void ClosePort();
	bool SetDTRHigh();
	bool SetDTRLow();
	bool IsDSRHigh();
};
