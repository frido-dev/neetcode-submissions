class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];

            int distance = (point[0] * point[0]) + (point[1] * point[1]);
            pq.push({distance, i});

            if (pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            pair<int, int> ans = pq.top();
            res.push_back(points[ans.second]);
            pq.pop();
        }

        return res;
    }
};
