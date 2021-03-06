#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint5 setiosflags(ios::fixed)<<setprecision(5)

#define maxn 1005
//#define maxm 1000000
//#define MAXP 12

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
 
bool flag[maxn];
double a[maxn], b[maxn];

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		int n;
		scanf("%d",&n);
		REP(i,n)
			scanf("%lf",a+i);
		REP(i,n)
			scanf("%lf",b+i);
		sort(a,a+n);
		sort(b,b+n);
		//REP(i,n)
		//	cout<<a[i]<<" "<<b[i]<<endl;
		
		int ans=0;
		memset(flag,0,sizeof(flag));
		REP(i,n)
		{
			double minnum=2.0;
			int p=0;
			REP(j,n)
				if (!flag[j] && a[j]>b[i] && a[j]<minnum)
					minnum=a[j], p=j;
			if (minnum<2.0)
				ans++, flag[p]=true;
		}
		printf("%d ",ans);
		
		ans=0;
		memset(flag,0,sizeof(flag));
		REP(i,n)
		{
			double minnum=2.0;
			int p=0;
			REP(j,n)
				if (!flag[j] && b[j]>a[i] && b[j]<minnum)
					minnum=b[j], p=j;
			if (minnum<2.0)
				ans++, flag[p]=true;
		}
		printf("%d\n",n-ans);
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
