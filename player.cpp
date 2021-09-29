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
};