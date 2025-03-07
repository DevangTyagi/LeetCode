class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> prime(n + 1, 1);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2; i * j <= n; j++) {
                    prime[i * j] = false;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isprime = sieve(right);
        vector<int> Primes;
        vector<int> ans = {-1, -1};
        for (int i = left; i <= right; i++) {
            if (isprime[i])
                Primes.push_back(i);
        }
        int mindiff = INT_MAX;
        for (int i = 1; i < Primes.size(); i++) {
            if (Primes[i] - Primes[i - 1] < mindiff) {
                mindiff = Primes[i] - Primes[i - 1];
                ans = {Primes[i - 1], Primes[i]};
            }
        }
        return ans;
    }
};