class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If the lengths are different, they can't be isomorphic
        if (s.length() != t.length()) return false;
        
        // Two hash maps to store character mappings
        unordered_map<char, char> mapST, mapTS;
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // Check if there's already a mapping for c1 in s -> t
            if (mapST.find(c1) != mapST.end()) {
                // If the current mapping doesn't match c2, return false
                if (mapST[c1] != c2) return false;
            } else {
                // Map c1 to c2
                mapST[c1] = c2;
            }
            
            // Check if there's already a mapping for c2 in t -> s
            if (mapTS.find(c2) != mapTS.end()) {
                // If the current mapping doesn't match c1, return false
                if (mapTS[c2] != c1) return false;
            } else {
                // Map c2 to c1
                mapTS[c2] = c1;
            }
        }
        
        // If all checks passed, the strings are isomorphic
        return true;
    }
};
