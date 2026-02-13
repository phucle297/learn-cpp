#include <iostream>
#include <string>

using namespace std;

string formatWithCommas(string s) {
  size_t first = s.find_first_not_of('0');
  if (first == string::npos)
    return "0";
  s = s.substr(first);

  string res = "";
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (i > 0 && (n - i) % 3 == 0) {
      res += ",";
    }
    res += s[i];
  }
  return res;
}

int main() {
  cout << "Enter a number: ";
  string s;
  cin >> s;
  cout << "Formatted number with commas: " << formatWithCommas(s) << endl;
  return 0;
}
