
#pragma once


class KeyboardSimulator
{
	INPUT input[1];

public:
	KeyboardSimulator();
	void pressSpacebar();
	void releaseSpacebar();
	void holdSpacebar();
};
