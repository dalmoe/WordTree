#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>

using namespace std;

class TreeNode{
    public:
        TreeNode(string word);
        
        string getWord();
        TreeNode* getParent();
        void setParent(TreeNode* parent);
        TreeNode* getSibling();
        void setSibling(TreeNode* sibling);
        vector<TreeNode*> getChildren();
        void setChildren(vector<TreeNode*> children);
        
    private:
        string m_word;
        TreeNode* m_pParent;
        TreeNode* m_pSibling;
        vector<TreeNode*> m_children;
};

#endif