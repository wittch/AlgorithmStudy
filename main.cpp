#include"13549.h"

//문제마다 branch로 관리하기 위해 branch 설정 후 commit
int main()
{

	Algorithm algo;
	int n = 0;
	int k = 0;
	cin >> n >> k;
	
	cout << algo.bfs(n, k);

	return 0;
}