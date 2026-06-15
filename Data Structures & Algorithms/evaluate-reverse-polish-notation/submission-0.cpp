class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res;

                if (tokens[i] == "+") {
                    res = a + b;
                } else if (tokens[i] == "-") {
                    res = b - a;
                } else if (tokens[i] == "*") {
                    res = a * b;
                } else {
                    res = b/a;
                }
                st.push(res);
            } else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }

        return st.top();
    }
};
