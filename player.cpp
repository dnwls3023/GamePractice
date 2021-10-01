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
    if(_Hp < 0){
      _Hp = 0;
      return true;
    }
    else{
      return false;
    }
  }

  int GetDmg(){
    return _AtkDmg;
  }

  // 상대방의 공격력 만큼 데미지를 입고 죽었는지 안죽었는지를 반환한다.
  bool AtkByOther(int Dmg){
    int TrueDmg = Dmg - _Def;
    // trueDmg가 0이하이면 1로 값을 보정한다. 값을 0으로 보정할 경우 영원히 게임이 끝나지 않는 경우가 생김
    if(TrueDmg <= 0 ) TrueDmg = 1;
    _Hp-=TrueDmg;
    // _Hp 가 음수일 경우 논리에 모순되므로 0으로 값을 보정
    if(_Hp < 0 ) _Hp = 0;
    if(_Hp == 0) return true;
    else return false;
  }
};