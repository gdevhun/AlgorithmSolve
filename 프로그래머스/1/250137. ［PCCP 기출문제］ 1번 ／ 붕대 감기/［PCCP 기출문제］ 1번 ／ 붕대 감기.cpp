#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curHealth=health;
    int maxHealth=health;
    int healTime=bandage[0];
    int healRate=bandage[1];
    int additiveHealRate=bandage[2];
    int attackDmg;
    
    int cnt=attacks[attacks.size()-1][0];
    
    int attackIdx=0;
    int healChance=0;
    
    for(int i=1; i<=cnt; i++){
            
        if(i==attacks[attackIdx][0]){ //몬스터공격
            attackDmg=attacks[attackIdx][1];
            attackIdx++;
            
            curHealth-=attackDmg;
            if(curHealth<=0){
                curHealth=0;
                return -1;
            } 
            healChance=0;
            cout<<"공격당함"<<"\n";
        }
        //몬스터공격x 회복
        else{
            healChance++;
            if(healChance==healTime){
                healChance=0;
                curHealth+=additiveHealRate;
            }
            curHealth+=healRate;
            if(curHealth>=maxHealth) curHealth=maxHealth;
        }
        cout<<"현재 횟수: "<<i<<" "<<"현재 체력: "<<curHealth<<"\n";
    }

    return curHealth;
}