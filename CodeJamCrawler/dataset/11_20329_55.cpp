#include <iostream>
#include <algorithm>

using namespace std;

int num[1000];
int n;

int main()
{
//	cout << (426423 ^ 290860) << endl;
	freopen("res.out", "wb", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++ tt)
	{
		cin >> n;
		int b = 0; 
		int _min = 10000000;
		int _total = 0;
		for(int i = 0; i < n; ++ i)
		{
			cin >> num[i];
			b ^= num[i];
			_min = min(_min, num[i]);
			_total += num[i];
		}
		cout << "Case #" << tt << ": ";
		if(b) cout << "NO" << endl;
		else
		{
			cout << _total - _min << endl;
		}
	}
	return 0;
}