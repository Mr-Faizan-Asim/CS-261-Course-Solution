#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;
// Functions
int checkingtheSymbol(char c);
int precChecking(char ch);
string postfix(string valueo);
string prefix(string valueo);
bool checkerOP(char c);
int evaPrefix(string exp);
double evaPostfix(string postfix);
// main
int main()
{
	string valueo;
	cin >> valueo;
	cout << postfix(valueo) << endl;
	cout << prefix(postfix(valueo)) << endl;
	cout << evaPostfix(postfix(valueo)) << endl;

	cout << evaPrefix(prefix(postfix(valueo))) << endl;
}
// 1st Question
// Functions body
int checkingtheSymbol(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
	{
		return 1;
	}
	else if (c == '(')
	{
		return 2;
	}

	return 0;
}
int precChecking(char ch)
{
	if (ch == '-' || ch == '+')
	{
		return 1;
	}
	else if (ch == '/' || ch == '*')
	{
		return 2;
	}
	return 0;
}

string postfix(string valueo)
{
	stack<char> oper;
	string result = "";
	for (char c : valueo)
	{
		if (!checkingtheSymbol(c) && c != ')')
		{
			result += c;
		}
		else if (checkingtheSymbol(c) == 2) //&& !checkingtheSymbol(c)
		{
			oper.push(c);
		}
		else if (c == ')')
		{

			while (oper.top() != '(' && !oper.empty()) //!= true)
			{
				result += oper.top();
				oper.pop();
			}
			oper.pop();
		}
		else if (checkingtheSymbol(c) == 1)
		{
			while (oper.empty() != true && precChecking(c) <= precChecking(oper.top()))
			{
				result += oper.top();
				oper.pop();
			}
			oper.push(c);
		}
	}
	while (!oper.empty())
	{
		result += oper.top();
		oper.pop();
	}
	return result;
}

// string prefix(string valueo) {


string prefix(string x)
{
	stack<string> opr;

	for (char c : x)
	{
		if (!(c == '+' || c == '-' || c == '*' || c == '/'))
		{
			string v = "";
			v = v + c;
			opr.push(v);
		}
		else if ((c == '+' || c == '-' || c == '*' || c == '/'))
		{
			string ope2 = opr.top();
			opr.pop();
			string ope1 = opr.top();
			opr.pop();

			string exp = c + ope1 + ope2;
			opr.push(exp);
		}
	}

	return opr.top();
}
// PART 2
bool checkerOP(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

double evaPostfix(string val)
{
	stack<double> oper;

	for (char c : val)
	{
		if (!checkerOP(c))
		{
			oper.push(c - '0'); // is ki waja sa wo number ma convert ho jata ha faizan yad kar lanaa.(sir awais wala)
		}
		else if (checkerOP(c))
		{
			double v2 = oper.top();
			oper.pop();
			double v1 = oper.top();
			oper.pop();
			if (c == '+')
				oper.push(v1 + v2);
			else if (c == '-')
				oper.push(v1 - v2);
			else if (c == '*')
				oper.push(v1 * v2);
			else if (c == '/')
				oper.push(v1 / v2);
		}
	}

	return oper.top();
}

int evaPrefix(string exp)
{
	stack<int> oper;

	for (int i = exp.length() - 1; i >= 0; i--)
	{
		char c = exp[i];

		if (!(c == '+' || c == '-' || c == '*' || c == '/'))
		{
			oper.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			int val1 = oper.top();
			oper.pop();
			int val2 = oper.top();
			oper.pop();

			int result;
			if (c == '+')
				result = val1 + val2;
			else if (c == '-')
				result = val1 - val2;
			else if (c == '*')
				result = val1 * val2;
			else if (c == '/')
				result = val1 / val2;
			
			oper.push(result);
		}
	}
	// degug krna tha (is lia)
	//cout << oper.top();
	return oper.top();
}