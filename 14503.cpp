#include"global.h"
#include"14503.h"

Algo::Algo(int& x, int& y, int& dir)
{
	x_ = x;
	y_ = y;
	dir_ = y;

}
vector<vector<int>> Algo::makeMap(int n, int m)
{
	vector<vector<int>> v(n);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}

	return v;
}

Algo::coord Algo::move(int x, int y, int dir, vector<vector<int>>& adj)
{
	int dx = x;
	int dy = y;
	bool Running = true;
	while (Running) {
		for (int i = 0; i < 4; i++)
		{
			int nx = dx;
			int ny = dy;
			int ndir = (dir + 3 - i) % 4;
			switch (ndir)
			{
			case 0:
				ny--;
				break;
			case 1:
				nx++;
				break;
			case 2:
				ny++;
				break;
			case 3:
				nx--;
				break;
			default:
				break;
			}
			if (adj[ny][nx] == 0)
			{
				adj[ny][nx] = 2;
				return { nx,ny,ndir };
			}
		}

		switch (dir)
		{
		case 0:
			dy++;
			break;
		case 1:
			dx--;
			break;
		case 2:
			dy--;
			break;
		case 3:
			dx++;
			break;
		default:
			break;
		}
		if (adj[dy][dx] == 1)
		{
			return { -1,-1,-1 };
		}
	}
}


