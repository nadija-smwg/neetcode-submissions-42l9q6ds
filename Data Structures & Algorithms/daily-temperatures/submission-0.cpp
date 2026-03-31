class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!st.empty() && t > st.top().first) {
                int num = st.top().second;
                st.pop();
                res[num] = i - num;
            }
            st.push({t, i});
        }
        return res;
    }
};