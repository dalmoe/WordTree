#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using namespace std;

class TreeNode{
    public:
        TreeNode();
        TreeNode(string word);
        
        void setWord(string word);
        string getWord();
        TreeNode* getParent();
        void setParent(TreeNode* parent);
        TreeNode* getSibling();
        void setSibling(TreeNode* sibling);
        TreeNode* getChild();
        void setChild(TreeNode* child);
        
    private:
        string m_word;
        TreeNode* m_pParent;
        TreeNode* m_pSibling;
        TreeNode* m_pChild;
};

#endif