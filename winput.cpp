#include "winput.h"

int WInput::AbsW = 65536 / GetSystemMetrics(SM_CXSCREEN);
int WInput::AbsH = 65536 / GetSystemMetrics(SM_CYSCREEN);
INPUT WInput::mouInput = { 0 };
INPUT WInput::kbdInput = { 1 };