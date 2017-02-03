#include "TreeNode.h"
#include <string>
#include <vector>

TreeNode::TreeNode(string word){
    m_word = word;
    m_pParent = nullptr;
    m_pSibling = nullptr;
}

string TreeNode::getWord(){
    return m_word;
}
TreeNode* TreeNode::getParent(){
    return m_pParent;
}
void TreeNode::setParent(TreeNode* parent){
    m_pParent = parent;
}
TreeNode* TreeNode::getSibling(){
    return m_pSibling;
}
void TreeNode::setSibling(TreeNode* sibling){
    m_pSibling = sibling;
}
vector<TreeNode*> TreeNode::getChildren(){
    return m_children;
}
void TreeNode::setChildren(vector<TreeNode*> children){
    m_children = children;
}