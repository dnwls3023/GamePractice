class Monster{
private:
  int _hp;
  int _mp;
  int _exp;
  int _def;
  int _atk;
public:
  // 디폴트 생성자(설정해준게 없을 시 모두 0으로 설정)
  Monster()
    :_hp(0),_mp(0),_exp(0),_def(0),_atk(0)
  {}
  Monster(int hp,int mp, int exp,int def,int atk)
    :_hp(hp),_mp(mp),_exp(exp),_def(def),_atk(atk)
  { }

  int GetHp(){
    return _hp;
  }

  void SetHp(int hp){
    _hp = hp;
  }
};

// 제일 단순하게 슬라임만 만들 예정.
class Slime : public Monster{
// private:
//   int _Hp = 50;
//   int _Mp = 10;
//   int _Exp = 5;
//   int _Def = 3;
//   int _Atk = 5;
public:
  Slime()
    : Monster(50,10,5,3,5)
  {}
};