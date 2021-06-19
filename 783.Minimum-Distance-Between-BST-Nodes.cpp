#include<iostream>
#include<vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/*

Transfer BST -> InOrder 
= small -> large

*/

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int min_dis = std::numeric_limits<int>::max();
        vector<int> sorted_array;
        Inoder(root, sorted_array);
        for(int i = 0 ; i < sorted_array.size()-1 ; i++)
        {
            min_dis = min(min_dis, sorted_array[i+1]-sorted_array[i]);
        }
        return min_dis;
    }

    void Inoder(TreeNode* node, vector<int> & sorted_array)
    {
        if(!node) return; // empty
        Inoder(node->left, sorted_array);
        sorted_array.push_back(node->val);
        Inoder(node->right, sorted_array);
    }
};