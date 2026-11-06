class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1 : Calculate frequencies
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> buckets(nums.size() + 1);

        // Step 3: Place elements into buckets
        for (auto iter : freq) buckets[iter.second].push_back(iter.first);

        // Step 4: Extract top k elements
        vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                result.push_back(buckets[i][j]);
                k--;

                if (k == 0) break;
            }
            if (k == 0) break;
        }
        return result;
    }
};
