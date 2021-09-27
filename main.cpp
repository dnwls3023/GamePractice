#include <iostream>
#include "monster.cpp"
using namespace std;

// 구현 할 것
// 몬스터, 플레이어, 전투

enum{
  BATTLE = 1,
  SHOP = 2,
};

// 몬스터와 플레이어가 싸울 때 실행될 함수. 반환값은 플레이어가 이겼을 때 True를 졌을 때 False를 반환한다.
bool BattleScene();

int main() {
  int Query;
  while(true){
    cout<<"-----------------------------------"<<endl;
    cout<<"안녕하세요 허접한 MMORPG에 오신 것을 환영합니다"<<endl;
    cout<<"컨텐츠를 선택하세요 (1. 전투 2. 상점)"<<endl;
    cout<<"참고로 잘못된 입력을 하게 될 경우엔 다시 입력을 하게 될 겁니다."<<endl;
    cout<<"입력 > ";
    cin>>Query;
    if(Query == BATTLE){
      BattleScene();
    }
  }
}