
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define debug(args...) dbg(),args
struct ipair { int first; int second; ipair(int x, int y) { first = x; second = y; }};
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define S(N) scanf("%d", &N)
#define SC(N) scanf("%c", &N)
#define SL(N) scanf("%lld", &N)
#define SF(N) scanf("%lf", &N)
#define SS(N) scanf("%s", N)
#define SIZE(X) ((int)((X).size()))
#define MP(A,B) *new ipair(A,B)
#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define FORL(A,B,C) for(ll A=B;A<C;A++)
#define EFORL(A,B,C) for(ll A=B;A<=C;A++)
#define RFORL(A,B,C) for(ll A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define MAX(A,B) (A > B) ? A : B
#define MIN(A,B) (A < B) ? A : B
#define DBGCHECK if (argc > 1) DBG = ((*argv[1] == '0') ? 0 : 1)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define LIM 100
#define MOD 100000007LL
#define INF  99
bool DBG;
struct dbg { template<typename T> dbg& operator , (const T& v) { if (DBG) cerr << v << " "; return *this; } ~dbg() { if (DBG) cerr << endl; } };

int a,b;
set<int> s;

int func(int n){
    int temp,len,num,div;
    len = log10(n)+1;
    s.clear();
    //debug(len,n);
    FOR(i,1,len){
        div = (int)pow(10.0,i);
        temp = n%div;
        num = (n/div) + temp*((int)pow(10.0,len-i));
        debug(div,temp,num);
        if((num > n) && num <= b)
            s.insert(num);
        }
    return s.size();
    }

int main (int argc, char *argv[])
{
    DBGCHECK;
    int t;
    S(t);
    EFOR(k,1,t){
        S(a);S(b);
        int ans = 0;
        FOR(i,a,b)
            ans += func(i);
        printf("Case #%d: %d\n",k,ans);
        }
}
