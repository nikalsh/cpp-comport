#include <Windows.h>
#include <iostream>
#include "KeyboardSimulator.h"




KeyboardSimulator::KeyboardSimulator()
{
	input->type = INPUT_KEYBOARD;
	input->ki.wScan = 0;
	input->ki.time = 0;
	input->ki.dwExtraInfo = 0;
	input->ki.wVk = 0x20;
		//0x20; // virtual-key code for spacebar
}


void KeyboardSimulator::pressSpacebar()
{
	input->ki.dwFlags = 0;
	SendInput(1, input, sizeof(INPUT));
}


void KeyboardSimulator::releaseSpacebar()
{
	input->ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, input, sizeof(INPUT));
}

void KeyboardSimulator::holdSpacebar()
{
	pressSpacebar();
	releaseSpacebar();
}