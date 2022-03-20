#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<*Node>> leaves = level(root);
        for(int i = 0;i<leaves.size();i++)
            for(int j = 0;j<leaves[i].size();i++)
            {   if(leaves[i][j+1])
                   leaves[i][j]->next =leaves[i][j+1];
                else
                    leaves[i][j]->next = NULL;
            }
        
        return root;
    }
    vector<vector<*Node>> level(Node* root)
    {   vector<vector<*Node>> ans;
        if(!root)
            return ans;
        Node *temp;
        queue<*Node> q;
     q.push(root);
     while(!q.empty())
     {   vector<*Node> v;
         int size  = q.size();
         for(int i = 0;i<size;i++)
         {
             temp = q.front();
             q.pop();
             v.push_back(temp);
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
         }
        ans.push_back(v);
     }
     return ans;
     
    }
};