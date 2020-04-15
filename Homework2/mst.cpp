#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
#define mk make_pair

int* p;

int find(int x)
{
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	p[x] = y;
}

int main()
{
	while (1)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)
			break;
		priority_queue < pair<int, pair<int, int> > > q;
		p = (int*)malloc(sizeof(int)*(n + 1));
		for (int i = 1;i <= n;i++)
			p[i] = i;
		for (int i = 0;i < m;i++)
		{
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			q.push(mk(-d, mk(a, b)));
		}
		int sum = 0;
		while (!q.empty())
		{
			int x = q.top().second.first, y = q.top().second.second;
			int d = -q.top().first;
			q.pop();
			if (find(x) != find(y))
			{
				sum += d;
				uni(x, y);
			}
		}
		free(p);
		printf("%d\n", sum);
	}
}


