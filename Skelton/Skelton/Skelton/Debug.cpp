#include "Debug.h"
#include <DxLib.h>


void Debug::Output(const char* str)
{
	OutputDebugStringA(str);

}
