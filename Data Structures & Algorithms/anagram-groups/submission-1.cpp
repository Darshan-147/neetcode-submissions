class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string& str : strs) {
            int count[26] = {0};
            for (char ch : str) count[ch - 'a']++;

            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]);
            }
            anagramGroups[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto pair : anagramGroups) result.push_back(move(pair.second));

        return result;
    }
};
