class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> pair_sum(n - 1, 0);
        long long min_sum = 0, max_sum = 0;
        for (int i = 0; i < n - 1; i++)
            pair_sum[i] = weights[i] + weights[i + 1];
        sort(pair_sum.begin(), pair_sum.end());
        for (int i = 0; i < k - 1; i++) {
            min_sum += pair_sum[i];
            max_sum += pair_sum[n - 2 - i];
        }
        return max_sum - min_sum;
    }
};