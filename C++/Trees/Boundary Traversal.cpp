//Problem: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
    
    bool isLeaf(Node *node)
    {
        if(!node->left and !node->right) return true;
        else return false;
    }
    
    void addRight(Node*root, vector<int>&ans)
    {
        if(!root->right) return;
        vector<int>tem;
        Node*curr=root->right;
        
        while(curr)
        {
            if(!isLeaf(curr))tem.push_back(curr->data);
            if(curr->right)
                curr=curr->right;
            else
                curr=curr->left;
        }
        for(int i=tem.size()-1; i>=0; i--)
        {
            ans.push_back(tem[i]);
        }
        
    }
    
    void addLeft(Node *root,vector<int>&ans)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))ans.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else
                curr=curr->right;
        }
    }
    void addLeaves(Node *root, vector<int>&ans)
    {
        if(!root) return;
        if(isLeaf(root)){
            ans.push_back(root->data) ;
            return;
        }
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root)return ans;

        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeft(root,ans);
        addLeaves(root,ans);
        addRight(root,ans);
        
        return ans;
    }
};
