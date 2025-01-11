class Solution {
public:
    void makegraph(unordered_map<int,vector<int>>& gr,int parent,TreeNode* node){
        if(node==nullptr) return;
        vector<int>& adjlist = gr[node->val];
        if(parent!=0) adjlist.push_back(parent);
        if(node->left!=nullptr) adjlist.push_back(node->left->val);
        if(node->right!=nullptr) adjlist.push_back(node->right->val);

        makegraph(gr,node->val,node->left);
        makegraph(gr,node->val,node->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> gr;
        makegraph(gr,0,root);

        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        int minute = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                for(int it: gr[node]){
                    if(vis.find(it)==vis.end()){
                        vis.insert(it);
                        q.push(it);
                    }
                }
            }
            minute++;
        }
        return minute-1;
    }
};