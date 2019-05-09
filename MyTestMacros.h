/*MIT License

Copyright(c) 2019 nooobguest@github.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef MY_TEST_MACROS_H
#define MY_TEST_MACROS_H

#define _AFXDLL
#include <sstream>
#include <afx.h>
template<class T>

void MyAssertEx(T a, T b, bool flag, const std::string& var_name, const std::string& file_name, int row_index)
{
	if (!flag)
	{
		std::stringstream ss;
		ss.precision(16);
		ss << "Assert Failed!\n\nFile: " << file_name << "\n\nLine: " << row_index
			<< "\n\nVar: " << var_name << "\n\nExpected: " << a << "\n\nActual: " << b;
		int id = MessageBoxW(0, CString(ss.str().c_str()), L"MyTestMacros", MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_TOPMOST);
		if (IDABORT == id)
		{
			PostQuitMessage(-1);
		}
		else if (IDRETRY == id)
		{
			__debugbreak();
		}
	}
}

void MyAssert(const std::string& var1, const std::string& var2, bool flag, const std::string& file_name, int row_index)
{
	if (!flag)
	{
		std::stringstream ss;
		ss << "Assert Failed!\n\nFile: " << file_name << "\n\nLine: " << row_index
			<< "\n\nVar: " << var2 << "\n\nExpected: " << var1;
		int id = MessageBoxW(0, CString(ss.str().c_str()), L"MyTestMacros", MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_TOPMOST);
		if (IDABORT == id)
		{
			PostQuitMessage(-1);
		}
		else if (IDRETRY == id)
		{
			__debugbreak();
		}
	}
}

#ifdef _DEBUG

#define VERIFY_EQUAL_EX(a, b) MyAssertEx(a, b, a==b, #b, __FILE__, __LINE__)
#define VERIFY_GREATER_EX(a, b) MyAssertEx(a, b, a>b, #b, __FILE__, __LINE__)
#define VERIFY_LESS_EX(a, b) MyAssertEx(a, b, a<b, #b, __FILE__, __LINE__)
#define VERIFY_GREATER_EQUAL_EX(a, b) MyAssertEx(a, b, a>=b, #b, __FILE__, __LINE__)
#define VERIFY_LESS_EQUAL_EX(a, b) MyAssertEx(a, b, a<=b, #b, __FILE__, __LINE__)

#define VERIFY_EQUAL(a, b) MyAssert(#a, #b, a==b, __FILE__, __LINE__)
#define VERIFY_GREATER(a, b) MyAssert(#a, #b, a>b, __FILE__, __LINE__)
#define VERIFY_LESS(a, b) MyAssert(#a, #b, a<b, __FILE__, __LINE__)
#define VERIFY_GREATER_EQUAL(a, b) MyAssert(#a, #b, a>=b, __FILE__, __LINE__)
#define VERIFY_LESS_EQUAL(a, b) MyAssert(#a, #b, a<=b, __FILE__, __LINE__)

#else

#define VERIFY_EQUAL(a, b) b
#define VERIFY_GREATER(a, b) b
#define VERIFY_LESS(a, b) b
#define VERIFY_GREATER_EQUAL(a, b) b
#define VERIFY_LESS_EQUAL(a, b) b

#define VERIFY_EQUAL_EX(a, b) b
#define VERIFY_GREATER_EX(a, b) b
#define VERIFY_LESS_EX(a, b) b
#define VERIFY_GREATER_EQUAL_EX(a, b) b
#define VERIFY_LESS_EQUAL_EX(a, b) b

#endif //_DEBUG
#endif //MY_TEST_MACROS_H