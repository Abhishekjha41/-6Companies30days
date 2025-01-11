class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                str.append("#,");
            } else {
                str.append(to_string(curr->val) + ",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> str;
        stringstream ss(data);
        string temp;
        while (getline(ss, temp, ',')) {
            str.push_back(temp);
        }

        if (str[0] == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(str[0]));
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1;
        while (!q.empty() && idx < str.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Process left child
            if (str[idx] != "#") {
                curr->left = new TreeNode(stoi(str[idx]));
                q.push(curr->left);
            }
            idx++;

            // Process right child
            if (idx < str.size() && str[idx] != "#") {
                curr->right = new TreeNode(stoi(str[idx]));
                q.push(curr->right);
            }
            idx++;
        }
        return root;
    }
};
