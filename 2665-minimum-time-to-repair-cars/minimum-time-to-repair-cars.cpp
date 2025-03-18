class Solution {
public:
    long long Cars_repair(vector<int>& ranks, long long avl_time) {
        long long sum = 0;
        for (int i = 0; i < ranks.size(); i++)
            sum += sqrt(avl_time / ranks[i]);
        return sum;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1,
                  r = (long long)*max_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
       long long ans = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long sum = Cars_repair(ranks,mid);
            if (sum >= cars) {
                ans = min(ans, mid);
                 r = mid - 1;
            }

            else
                l = mid + 1;
        }
        return ans;
    }
};