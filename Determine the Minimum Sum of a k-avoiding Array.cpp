class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> s;
        int curr = 1;
        int sum = 0;
        while(s.size() < n) {
            bool ok = true;
            for (auto it : s) {
                if ((it + curr) == k) {
                    ok = false;
                }
            }
            if (ok) {
                s.insert(curr);
                sum += curr;
            }
            curr++;
        }
        return sum;
    }
};
