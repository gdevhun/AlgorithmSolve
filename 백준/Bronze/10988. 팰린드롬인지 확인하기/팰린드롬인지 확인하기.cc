#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, temp;
    cin >> str;
    temp = str;

    reverse(temp.begin(), temp.end());
    temp == str ? cout << '1' : cout << '0';
}