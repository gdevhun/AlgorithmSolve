#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    
    vector<int> blocks(w);
    
    // 블록 높이 입력
    for (int i = 0; i < w; i++)
    {
        cin >> blocks[i];
    }
    
    int totalWater = 0;
    
    // 각 위치마다 물이 고이는 양 계산
    for (int i = 1; i < w - 1; i++)  // 양 끝은 물이 고일 수 없음
    {
        // 왼쪽에서 가장 높은 블록
        int leftMax = 0;
        for (int j = 0; j < i; j++)
        {
            leftMax = max(leftMax, blocks[j]);
        }
        
        // 오른쪽에서 가장 높은 블록
        int rightMax = 0;
        for (int j = i + 1; j < w; j++)
        {
            rightMax = max(rightMax, blocks[j]);
        }
        
        // 현재 위치에 고일 수 있는 물의 높이
        int waterLevel = min(leftMax, rightMax);
        
        // 현재 블록보다 높으면 물이 고임
        if (waterLevel > blocks[i])
        {
            totalWater += waterLevel - blocks[i];
        }
    }
    
    cout << totalWater << endl;
    
    return 0;
}