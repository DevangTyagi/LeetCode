class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while (word.size() < k) {
            string temp = word;
            for (char &ch : temp) {
                ch = (ch == 'z') ? 'a' : ch + 1;
            }
            word += temp;
        }
        
        return word[k - 1];
    }
};
