class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);
        
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                delta[start] += 1;
                delta[end + 1] -= 1;
            } else {
                delta[start] -= 1;
                delta[end + 1] += 1;
            }
        }
        
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += delta[i];
            int shiftValue = (netShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shiftValue) % 26;
        }
        
        return s;
    }
};
