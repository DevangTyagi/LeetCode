class Solution {
private:
    long long solve(vector<int>& candies, long long k, int max_candy) {
        long long child = 0;
        for (int i = 0; i < candies.size(); i++) {
            child += candies[i] / max_candy;
            if (child >= k)
                return child;
        }

        return child;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end()), ans = 0;
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k)
            return 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(candies, k, mid) >= k) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};