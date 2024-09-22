#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string name, state;
    cin>>n;
    map<string,string, greater<string>> mymap;
    while(n--)
    {
        cin>>name>>state;
        auto it = (mymap.find(name));
        if (it != mymap.end()) { //없으면 end 반환, 중복되는 것이 있다면
            mymap.erase(name);  //map에서 삭제한 후
        }
        mymap.insert({name,state}); //다시 삽입
    }
    
    for (auto& elem : mymap) {
        if (elem.second == "enter") {
            cout << elem.first << "\n";
        }
    }
    return 0;
}