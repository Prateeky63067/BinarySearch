
class Solution {
public:
    int count=0;
   
    int findLeftHeight(TreeNode* root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->left;
        }
        return count;
    }
    int findRightHeight(TreeNode*root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
      int lh=findLeftHeight(root);
      int rh=findRightHeight(root);
      if(lh==rh)return pow(2,lh)-1;

      return 1+countNodes(root->left)+countNodes(root->right);
    }
};