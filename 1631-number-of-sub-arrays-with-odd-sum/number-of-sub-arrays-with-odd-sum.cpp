class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_cnt = 0;
        int even_cnt = 1;
        int sum = 0 , ans = 0 ,mod = 1e9+7;
        for(auto &itr : arr) {
           sum += itr;
           if(sum % 2 == 0) {
            even_cnt++;
            ans = ans%mod + (odd_cnt)%mod;
           }
           else {
            odd_cnt++;
            ans = ans%mod + (even_cnt)%mod;
           }
        }
      return ans%mod;  
    }
};