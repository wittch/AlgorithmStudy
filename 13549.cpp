#include"13549.h"


int Algorithm::bfs(int n, int k)
{
	deque<int> dq;
	dq.push_back(n);
	vector<int> dist(100002, 999999);
	dist[n] = 0;
	while (!dq.empty())
	{
		int x = dq.front();
		dq.pop_front();
		if (x == k) return dist[k];
		if (x * 2 <= 100000 && dist[x * 2] > dist[x])
		{
			dist[x * 2] = dist[x];
			dq.push_front(x * 2);
		}

		if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1)
		{
			dq.push_back(x - 1);
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 < 100001 && dist[x + 1] > dist[x] + 1)
		{
			dq.push_back(x + 1);
			dist[x + 1] = dist[x] + 1;
		}
	}
	return -1;
}