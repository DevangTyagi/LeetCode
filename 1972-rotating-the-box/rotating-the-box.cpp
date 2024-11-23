class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> rotated(col, vector<char>(row, '.'));

        for (int i = 0; i < row; i++) {
            int emptySpot = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    rotated[j][row - 1 - i] = '*';
                    emptySpot = j - 1;
                } else if (box[i][j] == '#') {
                    rotated[emptySpot][row - 1 - i] = '#';
                    emptySpot--;
                }
            }
        }

        return rotated;
    }
};
