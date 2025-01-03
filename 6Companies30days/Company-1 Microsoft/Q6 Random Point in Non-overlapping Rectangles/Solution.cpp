class Solution {
public:
    vector<vector<int>> rects;
    vector<int> areas; 

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;

        for (const auto& rect : rects) {
            int area = (long long)(rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas.push_back(area + (areas.empty() ? 0 : areas.back()));
        }

        srand(time(0));
    }

    vector<int> pick() {
        int rnd_area = rand() % areas.back();
        int rectIdx = upper_bound(areas.begin(), areas.end(), rnd_area) - areas.begin();

        const auto& rect = rects[rectIdx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];

        return {x, y};
    }
};