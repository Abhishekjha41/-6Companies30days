class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const auto& word : words) {
            mp[word]++;
        }
        
        // Custom comparator for the priority queue
        auto comparator = [](const pair<int, string>& a, const pair<int, string>& b) {
            return (a.first > b.first) || (a.first == b.first && a.second < b.second);
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comparator)> pq(comparator);
        
        for (const auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end()); // Reverse to get the most frequent first
        return ans;
    }
};