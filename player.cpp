#include <iostream>
using namespace std;

class Player{
private:
  int _Hp;
  int _Mp;
  int _AtkDmg;
  int _Def;
  int _Exp;
public:
  Player()
    :_Hp(100), _Mp(5), _AtkDmg(10), _Exp(0), _Def(3)
  { }
  // 게임 오버인지 체크하는 함 (체력이 0이면 게임오버)
  bool IsGameOver(){
    if(_Hp == 0){
      return true;
    }
    else{
      return false;
    }
  }

  int GetDmg(){
    return _AtkDmg;
  }
  void PrintStatus(){
    cout<<"플레이어's Stats"<<endl;
    cout<<"HP : "<<_Hp<<endl;
    cout<<"MP : "<<_Mp<<endl;
    cout<<"EXP : "<<_Exp<<endl;
    cout<<"DEF : "<<_Def<<endl;
    cout<<"ATK : "<<_AtkDmg<<endl;
  }
  // 상대방의 공격력 만큼 데미지를 입고 죽었는지 안죽었는지를 반환한다.
  bool AtkByOther(int Dmg,string Name){
    int TrueDmg = Dmg - _Def;
    // trueDmg가 0이하이면 1로 값을 보정한다. 값을 0으로 보정할 경우 영원히 게임이 끝나지 않는 경우가 생김
    if(TrueDmg <= 0 ) TrueDmg = 1;
    _Hp-=TrueDmg;
    // _Hp 가 음수일 경우 논리에 모순되므로 0으로 값을 보정
    if(_Hp < 0 ) _Hp = 0;

    // 싸우는 장면 텍스트로 연출
    cout<<Name<<"의 턴!!"<<endl;
    cout<<Name<<"에게 "<<TrueDmg<<"만큼의 피해를 받았습니다"<<endl;
    cout<<"남은 체력 : "<<_Hp<<endl;

    if(_Hp == 0) return true;
    else return false;
  }
};