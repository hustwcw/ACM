#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
   int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int csum;
        int maxsum = INT_MIN;
        maxPathSumHelper(root, csum, maxsum);
        return maxsum;

    }
    void maxPathSumHelper(TreeNode *node, int &csum, int &maxsum) {
        if (!node) {
            csum = 0;
            return;
        }
        int lsum = 0, rsum = 0;
        maxPathSumHelper(node->left, lsum, maxsum);
        maxPathSumHelper(node->right, rsum, maxsum);
        csum = max(node->val, max(node->val + lsum, node->val + rsum));
        maxsum = max(maxsum, max(csum, node->val + lsum + rsum));
    }
};


int main()
{
    TreeNode *left = new TreeNode(4);
    left->left = new TreeNode(11);
    left->left->left = new TreeNode(7);
    left->left->right = new TreeNode(2);

    TreeNode *right = new TreeNode(8);
    right->left = new TreeNode(13);
    right->right = new TreeNode(4);
    right->left->right = new TreeNode(1);

    TreeNode *root = new TreeNode(5);
    root->left = left;
    root->right = right;
    
    Solution s; 
    cout << s.maxPathSum(root) << endl;
}