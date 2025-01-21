const int Q = 1e9 + 7;
class Solution {
private:
    int add(int x, int y) {
        return (x + y) % Q;
    }
    int mul(int x, int y) {
        return (1LL * x * y) % Q;
    }
    vector<vector<int>> precomputeCombinations(int n, int k) {
        vector<vector<int>> comb(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= k && j <= i; ++j) {
                comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
            }
        }
        return comb;
    }
public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> comb = precomputeCombinations(n, k);
        sort(nums.begin(), nums.end());
        int result = 0;
        int m = n - 1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j <= k - 1 && j <= m; ++j) {
                count = add(count, comb[m][j]);
            }
            result = add(result, mul(nums[i], count));
            m--;
        }

        reverse(nums.begin(), nums.end());
        m = n - 1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j <= k - 1 && j <= m; ++j) {
                count = add(count, comb[m][j]);
            }
            result = add(result, mul(nums[i], count));
            m--;
        }
        return result;
    }
};
