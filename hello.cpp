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

int main()
{
  std::cout << "Helloooo World" << std::endl;
  cout << "Hello World once again" << endl;
  //printname();
  vectorfn();
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
