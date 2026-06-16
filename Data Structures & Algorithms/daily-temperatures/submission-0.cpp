class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {

            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();

                ans[prevDay] = i - prevDay;
            }

            st.push(i);
        }

        return ans;
    }
};
