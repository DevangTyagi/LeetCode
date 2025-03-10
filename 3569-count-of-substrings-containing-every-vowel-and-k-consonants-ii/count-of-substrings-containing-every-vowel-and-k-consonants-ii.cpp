class Solution {
public:
    bool is_cons(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            return false;
        return true;
    }
    long long countOfSubstrings(string word, int k) {
        int i = 0, j = 0, count = 0;
        long long ans = 0;
        int n = word.size();
        int lastcons = n;
        unordered_map<char, int> mpp;
        vector<int> nextcons(n);
        for (int i = n - 1; i >= 0; i--) {
            nextcons[i] = lastcons;
            if (is_cons(word[i]))
                lastcons = i;
        }
        while (j < n) {
            if (is_cons(word[j]))
                count++;
            else
                mpp[word[j]]++;
            while (count > k) {
                if (is_cons(word[i]))
                    count--;
                else {
                    mpp[word[i]]--;
                    if (mpp[word[i]] == 0)
                        mpp.erase(word[i]);
                }
                i++;
            }
            while (i < n && mpp.size() == 5 && count == k) {
                ans += nextcons[j] - j;
                if (is_cons(word[i]))
                    count--;
                else {
                    mpp[word[i]]--;
                    if (mpp[word[i]] == 0)
                        mpp.erase(word[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};