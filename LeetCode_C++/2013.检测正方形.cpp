/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 */

// @lc code=start
class DetectSquares {
    map<pair<int, int>, int> mp;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        for(const auto &[p, t] : mp) {
            auto [x1, y1] = p;
            if(x1 == x && y1 == y) continue;
            if(abs(x1 - x) == abs(y1 - y)) {
                res += t * mp[{x, y1}] * mp[{x1, y}];
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

