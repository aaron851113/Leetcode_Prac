// % g++ -std=c++11 -o 222 222.cpp
// % ./222
#include<iostream>
#include<vector>
using namespace std;

/*
若左子樹高度等於右子樹，說明左子樹一定為滿二叉樹，可得左子樹的總節點個數，然後遞歸求右子樹的節點數；
若左子樹高度大於右子樹，說明右子樹一定為滿二叉樹，可得右子樹的總節點個數，然後遞歸求左子樹的節點數。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
     //用遞迴計算子樹高度
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return height(root->left) + 1 ;
    } 

    int countNodes(TreeNode* root) {
        //如果root為null
        if(root==NULL) return 0;
        //計算左右子樹高度
        int left = height(root->left);
        int right = height(root->right);
        //依據上述解題概念，依左右子樹高度決定求哪邊子樹的node數
        if (left==right) return (1 << left) + countNodes(root->right);  //(1<<left) = 2的left次方
        else return countNodes(root->left) + (1 << right);
    }
};