/*
https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
*/

// Approach # 01

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> p(n);

        for(int i=0; i<n; i++) {
            p[i] = make_pair(names[i], heights[i]);
        }

        auto lambda = [](auto& p1, auto& p2) {
            return p1.second > p2.second;
        };
        
        sort(p.begin(), p.end(), lambda);

        for(int i=0; i<n; i++) {
            names[i] = p[i].first;
        }

        return names;
    }
};
