class Solution {
public:
    bool isValidSerialization(string s) {
        stack<string> st;
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == ',') {
                i++;
                continue;
            }

            string current = "";
            while (i < n && s[i] != ',') {
                current += s[i];
                i++;
            }

            if (current == "#") {
                // Try to reduce the stack
                while (!st.empty() && st.top() == "#") {
                    st.pop();
                    if (st.empty()) return false;
                    st.pop();
                }
                st.push("#");
            } else {
                st.push(current);
            }
        }

        // The final stack must contain exactly one `"#"`
        return st.size() == 1 && st.top() == "#";
    }
};
