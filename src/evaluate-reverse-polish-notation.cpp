// evaluate-reverse-polish-notation.cpp : 定义控制台应用程序的入口点。
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are+,-,*,/. Each operand may be an integer or another expression.
// Some examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) //逆波兰表达式计算
	{
		stack<int> st;
		for(int i=0;i<tokens.size();i++)
		{
			string str = tokens[i];
			if(str.compare("+") == 0)
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a+b);
			}
			else if(str.compare("-") == 0)
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b-a);
			}
			else if(str.compare("*") == 0)
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a*b);
			}
			else if(str.compare("/") == 0)
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b/a);
			}
			else
			{
				st.push(atoi(str.c_str()));
			}
		}
	}
};
