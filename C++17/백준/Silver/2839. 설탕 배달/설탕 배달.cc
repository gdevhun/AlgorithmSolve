#include <iostream>

using namespace std;
int main(){
	int n;
	int cnt = 0;
	cin >> n;
	//봉지는 3키로, 5키로
	
	while (n % 5 !=0 && n >= 0) { 
		n -= 3;
		cnt++;
	}
	if (n < 0) {
		cout << "-1";
		return 0;
	}
	else {
		cnt += n / 5;
		cout << cnt;
	}
}