class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n,0);
        map<int, vector<pair<int,int>>> mp;
        for (auto it : offers) {
            mp[it[1]].push_back(make_pair(it[0], it[2]));
        }
        for (int i=0;i<n;++i) {
            if (i > 0) {
                dp[i] = dp[i-1];
            }
            for(auto it : mp[i]) {
                int st = it.first;
                int reward = it.second;
                if (st > 0) {
                    dp[i] = max(dp[i], dp[st-1] + reward);    
                } else {
                    dp[i] = max(dp[i], reward);
                }   
            }
        }
        return dp[n-1];
    }
};
