#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int sumDigits(string s) {
  int sum = 0;
  for (char c : s) {
    if (isdigit(c))
      sum += (c - '0');
  }
  return sum;
}

int main() {
  cout << "Enter a number: ";
  string s;
  cin >> s;
  cout << "Sum of digits: " << sumDigits(s) << endl;
  return 0;
}
