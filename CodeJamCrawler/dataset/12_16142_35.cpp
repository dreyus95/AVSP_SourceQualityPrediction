#include <stdio.h>
#include <string.h>


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i)
	{
		int N, S, P;
		int num, avg;
		int ans = 0;
		scanf("%d%d%d", &N, &S, &P);
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &num);
			avg = num / 3;

			if (num % 3 == 0)
			{
				if (avg >= P)
				{
					ans++;
				}
				else if (avg == P-1 && S > 0 && avg != 0)
				{
					ans++;
					S--;
				}
			}
			else if (num % 3 == 1)
			{
				if (avg + 1 >= P)
				{
					ans++;
				}
			}
			else
			{
				if (avg + 1 >= P)
				{
					ans++;
				}
				else if (avg + 2 == P && S > 0)
				{
					ans++;
					S--;
				}
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}