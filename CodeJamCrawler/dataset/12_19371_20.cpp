#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define PII         pair<int,int>
#define MP          make_pair
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

const int maxN = 10000;
map<PII, bool> mem;
int D, N, l[maxN], d[maxN];
bool f(int n, int lvl) {
	PII pi = MP(n,lvl);
	if(mem.count(pi)) return mem[pi];
	if(d[n]+lvl >= D) return mem[pi] = true;
	for(int i = n+1; i < N && d[i]-d[n] <= lvl; i++) {
		int nl = min(l[i], d[i]-d[n]);
		if(f(i, nl)) return mem[pi] = true;
	}
	return mem[pi] = false;
}
int main() {
	int T;
	cin >> T;
	REP(cs,T) {
		cin >> N;
		REP(i,N) cin >> d[i] >> l[i];
		cin >> D;
		mem.clear();
		cout << "Case #" << cs+1 << ": " << (f(0, min(d[0],l[0]))?"YES":"NO") << endl;
	}
	return 0;
}
