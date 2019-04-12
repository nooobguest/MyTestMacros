#include "pch.h"

#define _AFXDLL
#define MFC
#include "MyTestMacros.h"
int main()
{
	VERIFY_EQUAL(0, 1);
	VERIFY_GREATER(0, 0);
	VERIFY_GREATER_EQUAL(0, -1);
	VERIFY_LESS(0, 0);
	VERIFY_LESS_EQUAL(0, 1);
}
