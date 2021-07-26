/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 *
 * [1713] 得到子序列的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < target.size(); i++) {
            mp[target[i]] = i;
        }

        vector<int> f;
        for(auto &num : arr) {
            if(mp.count(num)) {
                f.push_back(mp[num]);
            }
        }

        int len = LIS(f);
        return target.size() - len;
    }

    int LIS(vector<int> &f) {
        int len = 0, n = f.size();
        vector<int> q(n + 1);
        for(int i = 0; i < n; i++) {
            int l = 0, r = len;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(q[mid] < f[i]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            q[l + 1] = f[i];
            len = max(len, l + 1);
        }
        return len;
    }
};
// @lc code=end

