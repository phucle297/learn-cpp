#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) primes.push_back(p);
    }
    return primes;
}

void factorize(int n) {
    vector<int> primes = sieve(sqrt(n));
    for (int p : primes) {
        while (n % p == 0) {
            cout << p << " ";
            n /= p;
        }
    }
    if (n > 1) cout << n;
}

int main(){
  cout << "Enter a number: ";
  int n;
  cin >> n;
  factorize(n);
}
