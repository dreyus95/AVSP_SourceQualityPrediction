#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<iostream>
#include<fstream>
#include<climits>
#include<set>
#include<map>
#include<deque>
#include<list>
#include<string>
#include<utility>
#include<numeric>
#include<iterator>
#include<cctype>
#include<ctime>

using namespace std;


#define fr(i,a,b) for(i=a;i<=b;i++)
#define rfr(i,a,b) for(i=a;i>=b;i--)
#define SI(a) scanf("%d",&a)
#define SLL(a) scanf("%lld",&a)
#define SL(a) scanf("%ld",&a)
#define SF(a) scanf("%f",&a)
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

#define all(c)  c.begin(), c.end()
#define tr(c, it)   for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define pb push_back
#define mp  make_pair

#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c)   ((MIN((a), (b)) > (c)) ? (c) : (MIN((a), (b))
#define inf INT_MAX
#define minf INT_MIN


 
 
//fast input
 
int scan_d()    {int ip=getchar(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar())if(ip=='-'){flag=-1;ip=getchar();break;}for(;ip>='0'&&ip<='9';ip=getchar())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=getchar(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar())if(ip=='-'){flag=-1;ip=getchar();break;}for(;ip>='0'&&ip<='9';ip=getchar())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {int ip=getchar(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar())if(ip=='-'){flag=-1;ip=getchar();break;}for(;ip>='0'&&ip<='9';ip=getchar())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {int ip=getchar();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar());for(;ip>='0'&&ip<='9';ip=getchar())ret=ret*10+ip-'0';return ret;}
 
//end of fast input
 
//fast output
 
//no line break
void print_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
 
//new line
void println_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
 
//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
 
//end of fast output

template<class T>
T mymax(T a,T b)
{
    return a>b?a:b;
}
template<class T>
T mymin(T a,T b)
{
    return a<b?a:b;
}



int main()
{
	freopen("lot_input.txt","r",stdin);
	freopen("lot_output.txt","w",stdout);
	int T;int A,B,K;                 int i,j;
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		cin>>A>>B>>K;
		int res=0;
		fr(i,0,A-1){
			fr(j,0,B-1){
				int c=i&j;
				//cout<<i<<" "<<j<<" "<<c<<"\n";
				if(c<K){
					res++;
					//cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<"Case #"<<cas<<": ";
		cout<<res<<"\n";
	}

    return 0;
}

