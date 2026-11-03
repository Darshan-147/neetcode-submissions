class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++) {
            int j = i;
            if (s[i] != t[j]) return false;
        }
        return true;
    }
};
