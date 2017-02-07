#include "TreeNode.h"
#include <string>
#include <vector>

TreeNode::TreeNode(){
    m_word = "";
    m_pParent = NULL;
    m_pSibling = NULL;
    m_pChild = NULL;
}
TreeNode::TreeNode(string word){
    m_word = word;
    m_pParent = NULL;
    m_pSibling = NULL;
    m_pChild = NULL;
}

void TreeNode::setWord(string word){
    m_word = word;
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
TreeNode* TreeNode::getChild(){
    return m_pChild;
}
void TreeNode::setChild(TreeNode* child){
    m_pChild = child;
}