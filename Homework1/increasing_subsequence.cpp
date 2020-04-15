#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	while (1)
	{
		string str;
		getline(cin, str);
		int len = str.length();
		int n = 0;
		if (len == 0)
			break;
		string ch = "";
		for (int i = 0;i < str.length();i++)
		{
			if (str.at(i) == ' ')
			{
				break;
			}
			else
			{
				ch += str.at(i);
				n++;
			}
		}
		int* dp = (int*)malloc(sizeof(int)*(n + 2));
		int* chk = (int*)malloc(sizeof(int)*(n + 2));
		for (int i = 0;i < n + 2;i++)
		{
			dp[i] = 0;
			chk[i] = 0;
		}
		
		int s = 0;
		for (int i = 0;i < n;i++)
		{
			int idx = lower_bound(dp, dp + s, ch.at(i)) - dp;
			if (s == idx)
				s++;
			dp[idx] = ch.at(i);
			chk[i] = idx;
		}
		stack<int> st;
		s--;
		for (int i = n - 1;i >= 0;i--)
		{
			if (s < 0)
				break;
			if (s == chk[i])
			{
				st.push(ch.at(i));
				s--;
			}
		}
		while (!st.empty())
		{
			printf("%c", st.top());
			st.pop();
		}
		printf("\n");
	}
}
