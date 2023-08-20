class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {  
        map<int,vector<int>> mp;
        int n = nums.size();
        for (int i=0;i<n;++i) {
            mp[nums[i]].push_back(i);
        }
        int ret = 0;
        for (auto it : mp) {
            vector<int> id = it.second;
            int x = id.size();
            int r = 0, del = 0;
            for (int i=0;i<x;++i) {
                while(del <= k && r<x) {
                    if (r != (x-1)) {
                        del += (id[r+1] - id[r] - 1);
                    }
                    ++r;
                }
                ret = max(ret, r-i);
                if (i<(x-1)) {
                    del -= (id[i+1] - id[i] - 1);
                }
            }
        }
        return ret;
    }
};
