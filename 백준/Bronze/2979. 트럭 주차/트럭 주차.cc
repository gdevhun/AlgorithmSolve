#include <iostream>
#include <algorithm>
using namespace std;

int parkingTime[101];
int totalcost;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //트럭 3대 총 비용 출력
    //한대 1분에 1대당 A원 
    //두대 1분에 1대당 B원
    //세대 1분에 1대당 C원

    //A,B,C 주어짐 트럭 주차장에 주차된 시간 총 주차비용?
    int first, second;
    int A, B, C;
    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++) {
        cin >> first >> second;
        for (int j = first; j < second; j++) parkingTime[j]++;
    }
    for (int i = 1; i < 101; i++) {
        if (parkingTime[i] == 1) totalcost += A;
        else if (parkingTime[i] == 2) totalcost += B * 2;
        else if (parkingTime[i] == 3) totalcost += C * 3;
    }
    cout << totalcost << '\n';

}