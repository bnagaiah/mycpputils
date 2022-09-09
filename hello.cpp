#include <iostream>
#include <string>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

#include <cstdlib>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include <vector>
#include <algorithm>

#include "list.h"

using namespace std;


typedef struct {

}sWeather_T;


int printname()
{
  int innum;
  cout << "enter int: ";

  cin >> innum;

  cout << "Enter name: ";
  string inname;
  cin >> inname;

  cout << inname << " entered a num " << innum << endl;
  return 0;
}

int vectorfn() {
  vector<int> v1 = {1,2,3,4};
  cout << "size: " << v1.size() << " capacity: " << v1.capacity() << endl;
  v1.push_back(10);
  v1.push_back(11);
  cout << "size: " << v1.size() << " capacity: " << v1.capacity() << endl;
  v1.shrink_to_fit();
  cout << "size: " << v1.size() << " capacity: " << v1.capacity() << endl;

  return 0;
}

int lambda_fn()
{
   int d=3;
 // [cc](p){fd};
   vector<int> v{2,4,7,11,15,12,6};
   for_each(v.begin(), v.end(), [=](int x) {
      if(x%d==0)
         cout << x << " is divisible by " << d << endl;
      else
         cout << x << " is not divisible by " << d << endl;
   });
   cout << "Sorting 1: " ;
   sort(v.begin(), v.end());
   for (auto x : v) {
      cout << x << ", ";
   }
   cout << endl;
   cout << "Sorting 2: " ;
   sort(v.begin(), v.end(), greater<int>());
   for (auto x : v) {
      cout << x << ", ";
   }
   cout << endl;
  return 0;
}

class Human
{
  private:
    int age;
    string name;
    bool isFemale=0;
  public:
#if 0
    Human(string humansname = "Adam", int humansage = 25)
    {
	name = humansname;
	age = humansage;
	cout << name << " of age " << age << endl;
    }
#endif
    Human(string humansname = "Ava", int humansage = 25, bool HumanisFemale = 0)
    {
	name = humansname;
	age = humansage;
	isFemale = HumanisFemale;
	cout << "Constructor: " << name << " of age " << age << " is a " << isFemale << endl;
    }

    void printHum(){
	cout << "Print: " << name << " of age " << age << " is a " << isFemale << endl;
	if(isFemale)
	    cout << "Voila its a Mermaid" << endl;
    }

    void editHum(string humansname = "Ava", int humansage = 25, bool HumanisFemale = 0)
    {
	name = humansname;
	age = humansage;
	isFemale = HumanisFemale;
	cout << "Edit: " << name << " of age " << age << " is a " << isFemale << endl;
    }


    Human(const Human& CopyHuman)
    {
	name = CopyHuman.name;
	age = CopyHuman.age + 1;
	cout << name << " copy of age " << age << endl;
    }

    ~Human()
    {
	cout << "Invoking destructor ....Human: " << name << endl;
	//delete [] &name;
    }
};

#include <set>
int classes_fn() {
   //Human adam;
   //std::set<Human<std::string, int>, comp> set = {
   //set<Human<string, int>> set = {
   vector<Human> vH = {
     {"Apple", 50},
     {"Orange", 50},
     {"Grape", 50},
     {"Banana", 50},
     {"Guava", 50}
   };
  cout << "size: " << vH.size() << " capacity: " << vH.capacity() << endl;
  //vH.emplace_back("Tomato", 60);
  //vH.push_back("onion", 60);
  //cout << "size: " << vH.size() << " capacity: " << vH.capacity() << endl;
  //vH.shrink_to_fit();
  //cout << "size: " << vH.size() << " capacity: " << vH.capacity() << endl;
   Human eve("Eva", 18);  
   Human adams("Bala", 40);  
   Human adamc(adams);  
   Human evec(eve);  
   //adams.editHum();
   //Human::printHum();
   return 0;
}


class Fish {
   protected:
     bool isFreshWateriFish;
     bool count = 1;
   private:
     int weight=0;
   public:
     void swim() {
	 if (isFreshWateriFish) {
	    cout << "Yes, from lake" << endl;
	    weight = 10;
	 }
	 else {
	    cout << "No, from ocean" << endl;
	    weight = 20;
	 }
     }

     void prop() {
        cout << "weight is " << weight << ", count is " << count << endl;
     }
};

class Tuna: public Fish {
   public:
     Tuna (){
        isFreshWateriFish = false;
     }
};

class Carp: public Fish {
   public:
     Carp (){
        isFreshWateriFish = true;
     }
};

class Mermaid: public Fish, public Human {
   public:
     Mermaid (){
        isFreshWateriFish = true;
	//editHum("Atulya", 25, true);
     }

     ~Mermaid (){
	//cout << "Invoking ....Destructor" << printHum() << endl;
	cout << "Invoking ....Destructor....Mermaid"  << endl;
     }
};


int inheritance_fn () {
   Carp MyLunch;
   Tuna MyDinner;
   Mermaid MyFriend;

   //MyLunch.prop();
   MyLunch.swim();
   MyLunch.prop();

   MyDinner.swim();
   MyDinner.prop();
   MyLunch.prop();

   MyFriend.swim();
   MyFriend.prop();
   MyFriend.editHum("Atulya", 25, true);
   MyFriend.printHum();

   return 0;
}

void Make_poly(Fish& inputfish) {
   inputfish.swim();
   inputfish.prop();
}

int polymorh_fn(){
   Tuna MyDinner;
   Carp MyLunch;
   
   Make_poly(MyDinner);
   Make_poly(MyLunch);

   return 0;
}

int main()
{
  std::cout << "Helloooo World" << std::endl;
  cout << "Hello World once again" << endl;
  //printname();
  print_lst();
  vectorfn();
  lambda_fn();
  classes_fn();
  //inheritance_fn();
  //polymorh_fn();
  Human eves("Poojaa", 18);  
  //string url = "www.example.com";
  string url = "https://api.openweathermap.org/data/2.5/weather?q=Austin,us&appid=ee62a6da139f3ec355563665665e21c8&units=metric";

  try {
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    // Setting the URL to retrive.
    request.setOpt(new curlpp::options::Url(url));

    //std::cout << request << std::endl;

    // Even easier version. It does the same thing
    // but if you need to download only an url,
    // this is the easiest way to do it.
    std::cout << "OUT: " << curlpp::options::Url(url) << std::endl;

    return EXIT_SUCCESS;
  }
  catch ( curlpp::LogicError & e ) {
    std::cout << e.what() << std::endl;
  }
  catch ( curlpp::RuntimeError & e ) {
    std::cout << e.what() << std::endl;
  }

  return EXIT_FAILURE;
}
