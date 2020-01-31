// Time  : 0 ms (100.00%)
// Memory: 8.9 MB (5.03%)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};
