#include <iostream>
#include <string>

using namespace std;

int countDigits(string s) {
  size_t first = s.find_first_not_of('0');
  if (first == string::npos)
    return 1;
  return s.length() - first;
}

int main() {
  cout << "Enter a number: ";
  string s;
  cin >> s;
  cout << "Number of digits (excluding leading zeros): " << countDigits(s)
       << endl;
  return 0;
}
