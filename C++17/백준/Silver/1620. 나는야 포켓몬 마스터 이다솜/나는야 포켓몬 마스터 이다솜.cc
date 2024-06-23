#include <iostream>
using namespace std;

#include <map>
#include <string> 
#include <vector>
#include <algorithm>
#include <ctype.h>

map<string, int> M;
vector <string> V;
int main()
{ 
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr), cout.tie(nullptr); //rapid IO 
  int n, m; //포켓몬수n 문제수m 
  cin >> n >> m;
  V.resize(n + 1);
  string cmd;
  for (int i = 1; i <= n; i++)
  {
  	cin >> V[i];
  	M[V[i]] = i; 
 } 
 for (int i = 0; i < m; i++)
 { 
   cin >> cmd;
   if (isdigit(cmd[0]))
     cout << V[stoi(cmd)];
  else
     cout << M[cmd];
  cout << '\n';
} 
}