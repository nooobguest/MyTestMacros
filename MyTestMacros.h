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

#include <sstream>
#ifdef MFC
#include <afx.h>
#endif // MFC
template<class T>
void MyAssert(T a, T b, const std::string& op, const std::string& var_name, const std::string& file_name, int row_index)
{
	bool flag = true;
	if ("=" == op)
	{
		flag = b == a ? true : false;
	}
	else if (">" == op)
	{
		flag = b > a ? true : false;
	}
	else if ("<" == op)
	{
		flag = b < a ? true : false;
	}
	else if (">=" == op)
	{
		flag = b >= a ? true : false;
	}
	else if ("<=" == op)
	{
		flag = b <= a ? true : false;
	}

	if (!flag)
	{
		std::stringstream ss;
		ss << "Assert Failed!\n\nFile: " << file_name << "\n\nLine: " << row_index
			<< "\n\nVar: " << var_name << "\n\nExpected: " << a << "\n\nActual: " << b;
#ifdef MFC
		int id = MessageBoxW(0, CString(ss.str().c_str()), L"MyTestMacros", MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_TOPMOST);
		if (IDABORT == id)
		{
			PostQuitMessage(-1);
		}
		else if (IDRETRY == id)
		{
			__debugbreak();
		}
#endif // MFC
	}
}

#ifdef _DEBUG

#define VERIFY_EQUAL(a, b) MyAssert(a, b, "=", #b, __FILE__, __LINE__)
#define VERIFY_GREATER(a, b) MyAssert(a, b, ">", #b, __FILE__, __LINE__)
#define VERIFY_LESS(a, b) MyAssert(a, b, "<", #b, __FILE__, __LINE__)
#define VERIFY_GREATER_EQUAL(a, b) MyAssert(a, b, ">=", #b, __FILE__, __LINE__)
#define VERIFY_LESS_EQUAL(a, b) MyAssert(a, b, "<=", #b, __FILE__, __LINE__)

#else

#define VERIFY_EQUAL(a, b) b
#define VERIFY_GREATER(a, b) b
#define VERIFY_LESS(a, b) b
#define VERIFY_GREATER_EQUAL(a, b) b
#define VERIFY_LESS_EQUAL(a, b) b

#endif //_DEBUG
#endif //MY_TEST_MACROS_H