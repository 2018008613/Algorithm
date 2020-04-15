#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

int a[10001], dp[10001][10001], n, chk[10001][10001], sum[10001], back[10001][10001], le[10001], ri[10001];

int dfs(int st, int ed)
{
	if (chk[st][ed] == 1)
		return dp[st][ed];
	if (st == ed)
		return 0;
	chk[st][ed] = 1;
	int mi = dfs(st, st) + dfs(st + 1, ed);
	back[st][ed] = st;
	for (int i = st;i < ed;i++)
	{
		if (dfs(st, i) + dfs(i + 1, ed) < mi)
		{
			mi = dfs(st, i) + dfs(i + 1, ed);
			back[st][ed] = i;
		}
	}
	if (st == 0)
		mi += sum[ed];
	else
		mi += (sum[ed] - sum[st - 1]);
	return dp[st][ed] = mi;
}

void bt(int st, int ed)
{
	le[st]++;
	ri[ed]++;
	int mid = back[st][ed];
	if (st != mid)
		bt(st, mid);
	if (ed != mid + 1)
		bt(mid + 1, ed);
}

int main()
{
	while (1)
	{
		string st;
		n = 0;
		getline(cin, st);
		if (st.length() == 0)
			break;
		string strNum = "";
		for (int i = 0; i < st.length(); i++)
		{
			if (st.at(i) == ' ' || st.at(i) == '\t')
			{
				a[n] = atoi(strNum.c_str());
				n++;
				strNum = "";
			}
			else
				strNum += st.at(i);
		}
		a[n] = atoi(strNum.c_str());
		n++;
		sum[0] = a[0];
		for (int i = 1;i < n;i++)
			sum[i] = sum[i - 1] + a[i];
		printf("%d ", dfs(0, n - 1));
		if (n > 1)
		{
			bt(0, n - 1);
			for (int i = 0;i < n;i++)
			{
				while (le[i]--)
					printf("(");
				printf("%d", a[i]);
				while (ri[i]--)
					printf(")");
				if (i != n - 1)
					printf(",");
			}
		}
		printf("\n");
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
				chk[i][j] = 0;
			le[i] = 0;
			ri[i] = 0;
		}
	}
}
