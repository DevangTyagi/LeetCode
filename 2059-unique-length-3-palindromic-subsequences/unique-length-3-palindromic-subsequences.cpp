#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            int left = s.find(c);
            int right = s.rfind(c);

            if (left < right) {
                unordered_set<char> middleCharacters;

                for (int i = left + 1; i < right; ++i) {
                    middleCharacters.insert(s[i]);
                }

                result += middleCharacters.size();
            }
        }

        return result;
    }
};
