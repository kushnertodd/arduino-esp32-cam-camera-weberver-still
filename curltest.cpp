// program to test return codes of curl
#include <iostream>
using namespace std;
int main() {

  int works = system("curl http://10.33.32.20/capture >z.jpg");
  int fails = system("curl foo >/dev/null");
  cout << "curl status code if works " << works << endl;
  cout << "curl status code if fails " << fails << endl;
} 
