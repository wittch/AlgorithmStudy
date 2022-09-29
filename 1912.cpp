#include"global.h"
#include"1912.h"

void Algorithm::dp(int data)
{
	int n = 0;
	n = data;
	vector<int> v(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	dp = v;
	for (int i = 1; i < n; i++)
	{
		dp[i] = (dp[i] < dp[i - 1] + v[i]) ? dp[i - 1] + v[i] : dp[i];
	}

	int mx = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (mx < dp[i])
			mx = dp[i];
	}
	cout << mx;

}