#include <iostream>
using namespace std;

// 뭘 구현할건가?
// 장비, 소비 아이템
// 장비

// 아이템 < 장비, 소비(물약)
// 아이템에는 무엇이 있을까 : 아이템 코드, 설명보기
class Item{
public:
  // 디폴트 생성자
  
  /*
    치명적 문제점 : 아이템을 데이터베이스 영역에 저장을 못함 따라서 계속  값이 날라가게됨
  Item()
  { 
    // 아이템을 생성하는 과정
    cout<<" 아이템을 생성합니다. "<<endl;
    cout<<" 도움말 : help "<<endl;
    cout<<"아이템 이름을 정해주세요 >> ";
    cin>>_Name;
    // NameCheck

    cout<<"아이템 설명 >> ";
    cin>>_Desc;
    // DescCheck

    // 만약 체크가 하나라도 올바르지 않은게 있다면 코드값 -1을 바로 때려박음
    _Code = 0; // 0은 생성이 제대로 이루어졌다는 의미
  }
  */
  Item(int Code, string Name, string Desc) :
    _Code(Code),_Name(Name),_Desc(Desc) 
  {}

  int GetCode(){return _Code;}
  void SetCode(int Code){
    // 아이템 코드 맨 앞자리로 아이템의 종류를 구별
    if(Code / 1000 == 1)

    _Code= Code;
    
  }
  string GetName(){return _Name;}
  void PrintDesc() {  
    cout<<_Desc<<endl;
  }
private:
  int _Code; // 아이템 코드
  string _Name; // 아이템 이름
  string _Desc; // 아이템 설명
};

// 장비는 맨 앞자리 1로 시작
class Equipment : public Item{
public:
  Equipment(int Code, string Name, string Desc)
  // 선처리 영역
  :Item(Code+1000, Name, Desc)
  { 
    
  }
private:
};