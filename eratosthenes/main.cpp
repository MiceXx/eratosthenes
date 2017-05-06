#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)

void crossOff(vector<bool> &flags, int prime) { //Cross off numbers divisible by (prime) in list
	for (int i = prime*prime; i < flags.size(); i += prime)	flags[i] = false;
}

int getNext(vector<bool> &flags, int prime) { //Next prime number to process in list
	int next = prime + 1;
	while (next < flags.size() && !flags[next]) next++;
	return next;
}

vector<bool> sieveEratosthenes(int max) { //Finds all prime numbers up to max

	//initialize
	vector<bool> flags(max + 1);
	flags[0] = false, flags[1] = false;
	for (int i = 2; i < flags.size(); i++)	flags[i] = true;

	int prime = 2;
	while (prime < sqrt(max)) {
		crossOff(flags, prime);
		prime = getNext(flags, prime);
	}
	return flags;
}

int main() {
	int n;
	cin >> n;
	vector<bool> primes = sieveEratosthenes(n);
	FOR(i,primes.size()) if (primes[i]) cout << i << endl;
	return 0;
}