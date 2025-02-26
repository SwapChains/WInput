#include <Windows.h>
#include "winput.h"

int main()
{
	WInput::SendClickAt(POINT{1920,0});
	Sleep(3000);
	WInput::SendKeyDown(0x30, KEY_VIRTUAL);
	Sleep(3000);
	WInput::SendKeyUp(0x30, KEY_VIRTUAL);
	return 0;
}