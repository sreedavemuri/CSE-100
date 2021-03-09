#include <iostream>
#include <string>

using namespace std;

int square(int a){
  a * a;
}

int main() {
  int n;
  cin >> n;
  
  int answer = square(n);
  
  cout << answer << endl;
 
}