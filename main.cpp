#include <iostream>
#include "monster.cpp"
#include "player.cpp"
using namespace std;

// 구현 할 것
// 몬스터, 플레이어, 전투

enum{
  BATTLE = 1,
  SHOP = 2,
};

// 몬스터와 플레이어가 싸울 때 실행될 함수. 반환값은 플레이어가 이겼을 때 True를 졌을 때 False를 반환한다.
bool BattleScene(Player* player);

int main() {
  Player p;
  int Query;
  while(true){
    cout<<"-----------------------------------"<<endl;
    cout<<"안녕하세요 허접한 MMORPG에 오신 것을 환영합니다"<<endl;
    cout<<"컨텐츠를 선택하세요 (1. 전투 2. 상점)"<<endl;
    cout<<"참고로 잘못된 입력을 하게 될 경우엔 다시 입력을 하게 될 겁니다."<<endl;
    cout<<"입력 > ";
    cin>>Query;
    if(Query == BATTLE){
      BattleScene(&p);
    }
  }
}

// 슬라임 스텟 : 공  
// 플레이어 스텟

bool BattleScene(Player* player){
  Slime monster;

  // 무한 루프
  while(true){
    bool IsPlayerDead = player->IsGameOver();
    
    bool IsMonsterDead = monster.IsGameOver();

    // 둘다 살아 있으면 싸우는게 가능함
    bool CanBattle = !IsPlayerDead && !IsMonsterDead;
    
    // 싸울 수 있다면
    if(CanBattle){
      // 플레이어가 몬스터를 공격하는

      // 몬스터가 플레이어를 공격하는 시뮬레이션
      int dmg = monster.GetDmg();
      player->AtkByOther(dmg);
      // 죽었으면
      if(player->IsGameOver())
    }
    else{
      // 둘중 하나가 죽었으면 누가 죽었는지를 반환값으로 전달한다.
      return;
    }
  }
}