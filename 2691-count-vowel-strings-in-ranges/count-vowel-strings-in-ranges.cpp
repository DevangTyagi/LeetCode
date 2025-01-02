class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>vowels;
        vector<int>ans;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int vowel_count = 0;
        for(auto &itr : words){
           char first = itr[0];
           char last = itr[itr.size()-1];
           if(st.find(first)!=st.end() && st.find(last)!=st.end()){
            vowel_count++;
           }
          vowels.push_back(vowel_count);
        }

        for(auto &itr : queries){
            int f_idx = itr[0];
            int l_idx = itr[1];
            if(f_idx == 0)
            ans.push_back(vowels[l_idx]-0);
            else
            ans.push_back(vowels[l_idx]-vowels[f_idx-1]);
        }
        return ans;
    }
};