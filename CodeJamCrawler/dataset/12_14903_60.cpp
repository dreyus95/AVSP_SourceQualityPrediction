#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>;


using namespace std;

int main(void){
 
 int T;
 cin>>T;
 for (size_t i=0;i<T;++i){
  int N,S,p;
  cin>>N>>S>>p;
  int ok = 0;
  int ok_if=0;
  for (size_t j=0;j<N;++j){
   int a;
   cin>>a;
   if (a==0) {
    if (p==0) ++ok;
   } else {
    if ((a+2)/3  >= p ) ++ok;
    else if ((a+4)/3>=p) ++ ok_if;
   }
  }
  int result = ok + min(S,ok_if);
  cout<<"Case #"<<i+1<<": "<<result<<'\n';
 }
 return 0;
}

int main0(void){
 map<char,char> RS;
 string A = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
 string B = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
 for (size_t i=0;i<A.length();++i){
  RS[A[i]]=B[i];
 }
 RS['q'] = 'z';
 RS['z'] = 'q';
 RS[' '] = ' ';

 int N;
 cin>>N;
  string s;
  getline(cin,s);
 for (size_t i=0;i<N;++i){
  getline(cin,s);
  cout<<"Case #"<<i+1<<": ";
  for (size_t j=0;j<s.length();++j) {
   cout<<RS[s[j]];
  }
  cout<<'\n';
 }
 return 0;
}