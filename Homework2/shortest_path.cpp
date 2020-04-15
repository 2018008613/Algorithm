#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define mk make_pair
#define INF 987654321

int main()
{
	while (1)
	{
		int n, m;
		int* dp;
		int* chk;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)
			break;
		vector<pair<int, int> > vec[30001];
		dp = (int*)malloc(sizeof(int)*(n + 1));
		chk = (int*)malloc(sizeof(int)*(n + 1));
		for (int i = 1;i <= n;i++)
		{
			dp[i] = INF;
			chk[i] = 0;
		}
		dp[1] = 0;
		for (int i = 0;i < m;i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			vec[a].push_back(mk(b, c));
			vec[b].push_back(mk(a, c));
		}
		priority_queue<pair<int, int> > q;
		q.push(mk(0, 1));
		while (!q.empty())
		{
			int d = -q.top().first;
			int n = q.top().second;
			q.pop();
			if (chk[n] == 1)
				continue;
			chk[n] = 1;
			for (int i = 0;i < vec[n].size();i++)
			{
				if (chk[vec[n][i].first] == 0 && dp[vec[n][i].first] > d + vec[n][i].second)
				{
					dp[vec[n][i].first] = d + vec[n][i].second;
					q.push(mk(-dp[vec[n][i].first], vec[n][i].first));
				}
			}
		}
		printf("%d\n", dp[n]);
		free(dp);
		free(chk);
	}
}


