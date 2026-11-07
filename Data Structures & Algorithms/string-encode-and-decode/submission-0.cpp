class Solution {
   public:
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        vector<int> sizes;
        string result;

        for (string& str : strs) sizes.push_back(str.size());

        for (int sz : sizes) {
            result.append(to_string(sz));
            result.push_back(',');
        }
        result.push_back('#');

        for (string& s : strs) result.append(s);

        return result;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> result;
        int i=0;
        while(s[i]!='#'){
            int j=i;
            while(s[j]!=',') j++;

            sizes.push_back(stoi(s.substr(i, j-i)));
            i=j+1;
        }
        i++;
        for(int sz:sizes){
            result.push_back(s.substr(i, sz));
            i+=sz;
        }
        return result;
    }
};
