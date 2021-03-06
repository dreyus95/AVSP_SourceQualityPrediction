#include <iostream>
#include <algorithm>
using namespace std;

int x, s, r, n;
double t;
struct pass
{
	int b, e, s;
}way[3000];
struct node
{
	int b, e, speed;
}road[3000];

bool cmp(node a, node b)
{
	return a.speed < b.speed;
}

bool cmp2(pass a, pass b)
{
	return a.b < b.b;
}

int main()
{
	freopen("A-large.in", "r+", stdin);
	freopen("A-large.out", "w+", stdout);
	int ts, tt = 0;
	scanf("%d", &ts);
	while (ts--)
	{
		scanf("%d %d %d %lf %d", &x, &s, &r, &t, &n);
		int len = x;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &road[i].b, &road[i].e, &road[i].speed);
			road[i].speed += s;
			len -= road[i].e - road[i].b;
		}
		road[n].b = 0;
		road[n].e = len;
		road[n].speed = s;
		
		sort (road, road + n + 1, cmp);
		double ret = 0;
		for (int i = 0; i < n + 1; i++)
		{
			if (t > 0)
			{
				double t1 = 1.0 * (road[i].e - road[i].b) / road[i].speed;
				double t2 = 1.0 * (road[i].e - road[i].b) / (road[i].speed - s + r);
				if (t2 <= t)
				{
					t -= t2;
					ret += t2;
				}
				else
				{
					ret += t;
					double x1 = t * (road[i].speed - s + r);
					double t3 = 1.0 * (road[i].e - road[i].b - x1) / road[i].speed;
					ret += t3;
					t = 0;
				}
			}
			else if (t <= 0)
			{
				ret += 1.0 * (road[i].e - road[i].b) / road[i].speed;
			}
		}
		printf("Case #%d: %lf\n", ++tt, ret);
	}
	return 0;
}