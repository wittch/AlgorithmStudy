#include"global.h"
#include"14503.h"

class Algo;

int main()
{
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    int dir = 0;
    int cnt = 1;
    vector <vector<int>> map;
    cin >> n >> m;
    cin >> y >> x >> dir;
    Algo init(x, y, dir);
    Algo::coord coord = {x,y,dir};
    map = init.makeMap(n, m);
    map[y][x] = 2;
    while (1)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                if (coord.x == j && coord.y == i)
                    cout << 4 << " ";
                else
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';

        coord = init.move(coord.x, coord.y, coord.dir, map);
        if (coord.dir == -1)
            break;
        cnt++;
    }
    cout << cnt;
    return 0;
}