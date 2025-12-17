#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;
    int cnt=0;
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if(m==1){
        cout<<2*n;
        return 0;
    }
    for(int i=0; i<n; i++){

        int first=grid[i][0];
        int findElem=1;
        int prev;

        for(int j=0; j<n; j++){
            if(j==0) {
                prev=grid[i][j];
                continue;
            }
            else{
                if(prev==grid[i][j]){
                    findElem++;
                    if(findElem>=m){
                        cnt++;
                        break;
                    }
                }
                else{
                    prev=grid[i][j];
                    findElem=1;
                }
            }

        }
    }
 
     for(int i=0; i<n; i++){

        int first=grid[0][i];
        int findElem=1;
        int prev;

        for(int j=0; j<n; j++){
            if(j==0) {
                prev=grid[j][i];
                continue;
            }
            else{
                if(prev==grid[j][i]){
                    findElem++;
                    if(findElem>=m){
                        cnt++;
                        break;
                    }
                }
                else{
                    prev=grid[j][i];
                    findElem=1;
                }
            }

        }
    }

    cout<<cnt;

    return 0;
}
