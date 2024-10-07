#include<iostream>
#include<string>
using namespace std;
int n;
int tree[65][65];
bool check(int n,int x,int y) {
	char init = tree[x][y];
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (init != tree[i][j]) return false;
		}
	}
	return true;
}
string divide(int n,int x,int y) {
	string str = "";
	if (check(n, x, y) || n==1) {
		str += tree[x][y];
	}
	else {
		str += "(";
		str+=divide(n / 2, x, y);  //1
		str+=divide(n / 2, x, y + n / 2); //2 
		str+=divide(n / 2, x + n / 2, y); //3
		str+=divide(n / 2, x + n / 2, y + n / 2); //4
		str += ")";
	}
	return str;
}
int main() {
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			tree[i][j] = temp[j];
		}
	}
	cout << divide(n, 0, 0) << "\n";
	
	return 0;
}
