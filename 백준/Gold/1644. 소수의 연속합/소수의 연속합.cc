#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int n;
bool isPrime[4000001];
vector<int> prime;

void checkPrime() {
	for (long long i = 2; i <= 4000000; i++) {
		if (!isPrime[i]) {
			prime.push_back(i);
			for (long long j = i * i; j <= 4000000; j += i) {
				isPrime[j] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	checkPrime();

	cin >> n;
	int left = 0, right = 0;
	int sum = 0;
	int answer = 0;

	while (prime[left]<=n) {
		if (sum > n) {
			sum -= prime[left++];
		}
		else {
			if (sum == n) {
				answer++;
			}
			if (right >= prime.size())break;
			sum += prime[right++];
		}
		
	}

	cout << answer;
}