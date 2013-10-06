#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>

using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root != NULL)
        {
            flattenHelper(root);
        }
    }
    
    TreeNode *flattenHelper(TreeNode *root)
    {
        TreeNode *rightNode = root->right;
        if(root->left == NULL && root->right == NULL)
        {
            return root;
        }
        else 
        {
        if(root->left != NULL)
        {
            root->right = root->left;
            root = flattenHelper(root->left);
        }
        
        if(rightNode != NULL)
        {
            root->right = rightNode;
            return flattenHelper(rightNode);
        }
        }
        
    }
};

int main(void)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
	Solution s;
	s.flatten(root);
    while(root != NULL)
    {
        cout << root->val << endl;
        root = root->right;
    }

	return 0;
}
