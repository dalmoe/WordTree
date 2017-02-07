#ifndef WORDTREE_H
#define WORDTREE_H

#include "TreeNode.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class WordTree{
  public:
    WordTree();
    ~WordTree();
    
    TreeNode* getRoot();
    
    void buildTree(string start, string end);
    void printTree(TreeNode* node);
    
  private:
    TreeNode* m_pRoot;
    vector<string> m_dictionary;
    void parseDict();
    vector<string> narrowDict(int wordSize);
    void buildList(TreeNode* node, vector<string> &wordList, string endWord); 
    void printLadder(TreeNode* node);
};
#endif