#include"13549.h"

/*일반 bfs와는 다르게 가중치가 0과 1만 주어져 있을 때 시행하는 bfs이다.
deque를 이용하여 가중치가 0인 노드는 push_front()을 이용하여 값을 넣으며 갱신하고
가중치가 1인 노드는 push_back()을 이용하여 값을 넣으며 갱신한다.
deque의 특성을 활용한 bfs이다.
*/
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
