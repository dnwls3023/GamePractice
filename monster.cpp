#include <iostream>
#include "player.cpp"
using namespace std;


class Monster{
private:
  int _hp;
  int _mp;
  int _exp;
  int _def;
  int _atk;
  string _MobName; 
public:
  // 디폴트 생성자(설정해준게 없을 시 모두 0으로 설정)
  Monster()
    :_hp(0),_mp(0),_exp(0),_def(0),_atk(0)
  {}
  Monster(int hp,int mp, int exp,int def,int atk,string MobName)
    :_hp(hp),_mp(mp),_exp(exp),_def(def),_atk(atk),_MobName(MobName)
  { }

  int GetHp(){
    return _hp;
  }

  void PrintStatus(){
    cout<<_MobName<<"'s Stats"<<endl;
    cout<<"HP : "<<_hp<<endl;
    cout<<"MP : "<<_mp<<endl;
    cout<<"EXP : "<<_exp<<endl;
    cout<<"DEF : "<<_def<<endl;
    cout<<"ATK : "<<_atk<<endl;
  }

  void SetHp(int hp){
    // hp가 음수값이면 0으로 보정
    if(hp<0) hp = 0;
    _hp = hp;
  }

  bool IsGameOver(){
    if(_hp < 0){
      _hp = 0;
      return true;
    }
    else{
      return false;
    }
  }

  void BeAttacked(Player* p){
    int ResultDmg = p->GetDmg() - _def;
    if(ResultDmg <= 0) 
      ResultDmg=1;
    
    _hp-=ResultDmg;
  }
};

// 제일 단순하게 슬라임만 만들 예정.
class Slime : public Monster{
public:
  Slime()
    : Monster(50,10,5,3,5,"슬라임")
  {}
};