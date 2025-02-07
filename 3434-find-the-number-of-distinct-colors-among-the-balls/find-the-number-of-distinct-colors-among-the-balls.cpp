class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;
        int uniqueColors = 0;
        vector<int> result;
        
        for (auto &q : queries) {
            int ball = q[0], color = q[1];
            int prevColor = ballColor[ball];

            if (prevColor != 0) {
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) uniqueColors--;
            }

            ballColor[ball] = color;
            if (++colorCount[color] == 1) uniqueColors++;

            result.push_back(uniqueColors);
        }
        
        return result;
    }
};
