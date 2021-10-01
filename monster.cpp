#include <iostream>
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

  int GetDmg(){
    return _atk;
  }

  bool IsGameOver(){
    if(_hp == 0){
      return true;
    }
    else{
      return false;
    }
  }

  string GetName(){
    return _MobName;
  }

  bool AtkByOther(int Dmg){
    int TrueDmg = Dmg - _def;
    // trueDmg가 0이하이면 1로 값을 보정한다. 값을 0으로 보정할 경우 영원히 게임이 끝나지 않는 경우가 생김
    if(TrueDmg <= 0 ) TrueDmg = 1;
    _hp-=TrueDmg;
    // _Hp 가 음수일 경우 논리에 모순되므로 0으로 값을 보정
    if(_hp < 0 ) _hp = 0;

    // 싸우는 장면 텍스트로 연출
    cout<<"플레이어의 턴!!"<<endl;
    cout<<"플레이어에게 "<<TrueDmg<<"만큼의 피해를 받았습니다"<<endl;
    cout<<_MobName<<"의 남은 체력 : "<<_hp<<endl;
    if(_hp == 0) return true;
    else return false;
  }
};

// 제일 단순하게 슬라임만 만들 예정.
class Slime : public Monster{
public:
  Slime()
    : Monster(50,10,5,3,5,"슬라임")
  {}
};