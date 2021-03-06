#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 400010
#define N 450
//#define ll long long
#define inf 0x3f3f3f3f
const double eps = 1e-8;
double solve( double C, double F, double X )
{
	double ans = X / 2;
	double pro = 2;
	double t = 0;
	while( 1 ){
		double t1 = C / pro;
		t += t1;
		pro += F;
		double tmp = t + X / pro;
		if( tmp < ans ) ans = tmp;
		else if( tmp > ans + eps ) break;
	}
	return ans;
}
int main()
{
	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	int T;
	int x, y, cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		double a, b, c;
		scanf( "%lf%lf%lf", &a, &b, &c );
		double ans = solve( a, b, c );
		printf( "Case #%d: ", ++cas );
		printf( "%.7lf\n", ans );
	}
		
}

/*
#define mod 1000000007
int vv[M], nxt[M], cap[M], cc[M], h[N], e;
void add( int u, int v, int f, int c )
{
	vv[e] = v, nxt[e] = h[u], cap[e] = f, cc[e] = c, h[u] = e++;
	vv[e] = u, nxt[e] = h[v], cap[e] = 0, cc[e] = -c, h[v] = e++;
}
int dis[N], pre[N], vis[N];
int spfa( int s, int t )
{
	memset( dis, 0x3f, sizeof(dis) );
	memset( vis, 0, sizeof(vis) );
	queue<int> q;
	q.push( s );
	dis[s] = 0;
	int u, v;
	while( !q.empty() ){
		u = q.front(), q.pop();
		vis[u] = 0;
		for( int i = h[u]; i+1; i = nxt[i] ) if( cap[i] > 0 ) {
			v = vv[i];
			if( dis[v] > dis[u] + cc[i] ){
				dis[v] = dis[u] + cc[i];
				pre[v] = i;
				if( !vis[v] )
					vis[v] = 1, q.push( v );
			}
		}
	}
	return dis[t] != inf;
}

int solve( int s, int t )
{
	int ans = 0;
	int v, mins;
	while( spfa( s, t ) ){
		v = t;
		mins = inf;
		while( v - s ){
			v = pre[v];
			mins = min( mins, cap[v] );
			v = vv[v^1];
		}
		ans += mins * dis[t];
		v = t;
		while( v - s ){
			v = pre[v];
			cap[v] -= mins;
			cap[v^1] += mins;
			v = vv[v^1];
		}
	}
	return ans;
}
int a[110][110];
int dp[1011][1011];

int main()
{
	int T;
	int n, v, m;
	int cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		cin>>n>>m;
		memset( h, -1, sizeof(h) ), e = 0;
		for( int i = 1; i <= n; ++i ){
			for( int j = 1; j <= m; ++j ){
				scanf( "%d", &v );
				a[i][j] = v;
				add( i, j+n, 1, v );
			}
		}
		int s = n + n + m + m + 1, t = s + 1;
		for( int i = 1; i <= n; ++i ){
			add( s, i, 1, -100000 );
			add( s, i+n+m, n, 0 );
			for( int j = 1; j <= m; ++j )
				add( i+n+m, j+n, 1, a[i][j] );
		}
		for( int j = 1; j <= m; ++j ){
			add( n+j, t, 1, -100000 );
			add( n+n+m+j, t, 1, 0 );
			for( int i = 1; i <= n; ++i )
				add( i, j+n+n+m, 1, a[i][j] );
		}
		int ans = solve( s, t ) + 100000 * ( n + m );
		printf( "Case %d: %d\n", ++cas, ans / 2 );
	}
				
}
*/