
#include <iostream>
#include <algorithm>
using namespace std;
int cnt[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //abcdefghijklmnopqrstuvwxyz
    //A -> 65 a->97

    //a->97  97~122
    string str;
    cin >> str;
    for (char a : str) {
        cnt[a-'a']++;
    }
    for (int i = 0; i < 26; i++) cout << cnt[i] << " ";

    
}