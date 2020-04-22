#include <Windows.h>

void pressSpacebar(INPUT& ip)
{
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
}

void releaseSpacebar(INPUT& ip)
{
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(50);
}

void holdSpacebar(INPUT& ip)
{
    pressSpacebar(ip);
    releaseSpacebar(ip);
}

int main()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = 0x20; // virtual-key code for spacebar

    //while (true) {
    //    if (comPin) {
    //        holdSpacebar(ip);
    //    }
    //}
    return 0;
}

