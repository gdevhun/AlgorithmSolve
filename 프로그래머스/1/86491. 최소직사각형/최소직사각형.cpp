#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;  
    int maxHeight = 0;  
    
    for(int i = 0; i < sizes.size(); i++){
        
        // 각 명함에서 더 긴 쪽과 짧은 쪽 구하기
        int longer = max(sizes[i][0], sizes[i][1]);
        int shorter = min(sizes[i][0], sizes[i][1]);
        
        // 긴 쪽들 중 최댓값, 짧은 쪽들 중 최댓값 갱신
        maxWidth = max(maxWidth, longer);
        maxHeight = max(maxHeight, shorter);
    }
    
    return maxWidth * maxHeight;
}