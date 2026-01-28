#include <iostream>
#include <string>
using namespace std;

int main() {
  string decrypted{""};

  int temp;
  string c;
  cin >> c;
  while (c != "q") {
    temp = stoi(c, nullptr, 16);
    decrypted.push_back((char)temp);

    cin >> c;
  }

  cout << std::dec << "Decrypted text: " << decrypted << '\n';

  return 0;
}
