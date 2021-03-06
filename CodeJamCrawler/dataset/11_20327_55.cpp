#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c, d, n;
string strCombines[100];
string strOpposeds[100];
string str;
int combines[26][26];
bool opposeds[26][26];

int main()
{
	freopen("res.out", "wb", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++ tt)
	{
		memset(combines, 0, sizeof(combines));
		memset(opposeds, 0, sizeof(opposeds));
		cin >> c;
		for(int i = 0; i < c; ++ i)
		{
			cin >> strCombines[i];
			combines[strCombines[i][0] - 'A'][strCombines[i][1] - 'A'] = strCombines[i][2];
			combines[strCombines[i][1] - 'A'][strCombines[i][0] - 'A'] = strCombines[i][2];
		}
		cin >> d;
		for(int i = 0; i < d; ++ i)
		{
			cin >> strOpposeds[i];
			opposeds[strOpposeds[i][0] - 'A'][strOpposeds[i][1] - 'A'] = true;
			opposeds[strOpposeds[i][1] - 'A'][strOpposeds[i][0] - 'A'] = true;
		}
		cin >> n;
		cin >> str;
		vector<char> ans;
		for(size_t i = 0; i < str.size(); ++ i)
		{
			if(ans.empty())
			{
				ans.push_back(str[i]);
			}
			else
			{
				if(combines[ans.back() - 'A'][str[i] - 'A'] != 0)
				{
					ans.back() = (char)combines[ans.back() - 'A'][str[i] - 'A'];
				}
				else
				{
					bool flag = false;
					for(int j = ans.size() - 1; j >= 0; -- j)
					{
						if(opposeds[ans[j] - 'A'][str[i] - 'A'])
						{
							ans.clear();
							flag = true;
							break;
						}
					}
					if(!flag)
					{
						ans.push_back(str[i]);
					}
				}
			}
		}
		cout << "Case #" << tt << ": [";
		if(!ans.empty()) cout << ans[0];
		for(size_t i = 1; i < ans.size(); ++ i)
		{
			cout << ", " << ans[i];
		}
		cout << "]" << endl;
	}
	return 0;
}