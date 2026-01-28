#include <iostream>
#include <string>
using namespace std;

int main() {
  string decrypted{""};

  char c;
  cin >> c;
  while (c != '$') {
    c += 48;
    decrypted.push_back(c);

    cin >> c;
  }

  cout << std::dec << "Decrypted text: " << decrypted << '\n';

  return 0;
}
