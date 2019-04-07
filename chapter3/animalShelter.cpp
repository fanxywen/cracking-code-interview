#include <iostream>
#include <list>
#include <string>
using namesapce std;
class animal{
private:
  string type;
  int age;
public:
  animal(string _type):type(_type), age(){}
  ~animal(){}
  void setAge(int _age){
    age = _age;
  }
  string getType(){
    return type;
  }
  int getAge(){
    return age;
  }
};
class shelter{
private:
  list<animal> dogs;
  list<animal> cats;
  vector<list<animal>::iterator > ages;
public:
  shelter(){}
  ~shelter(){}
  void enqueue(animal a){
    if(a.type == "dog"){
      a.setAge(dogs.size());
      dogs.push_back(a);
      list<animal>::iterator iter = dogs.end()-1;
      ages.push_back(iter);
    }else{
      a.setAge(cats.size());
      cats.push_back(a);
      list<animal>::iterator iter = cats.end()-1;
      ages.push_back(iter);
    }
  }
  void dequeueAny(){
    list<animal>::iterator iter = ages[0];
    if(iter->type == "dog"){
      dogs.pop_front();
    }else{
      cats.pop_front();
    }
    ages.pop_front();
  }
  void dequeDog(){
    list<animal>::iterator iter = dogs.begin();
    int age = iter->getAge();
    dogs.pop_front();
    ages.erase(ages.begin()+age);
  }
  void dequeCat(){
    list<animal>::iterator iter = cats.begin();
    int age = iter->getAge();
    cats.pop_front();
    ages.erase(ages.begin()+age);
  }
};


