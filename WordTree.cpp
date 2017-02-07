#include "WordTree.h"
#include "TreeNode.h"
#include <vector>
#include <string>
#include <iostream>
#include<fstream>

using namespace std;

WordTree::WordTree(){
    m_pRoot = NULL;
    parseDict();
}

WordTree::~WordTree(){
    //add later
}

TreeNode* WordTree::getRoot(){
    return m_pRoot;
}

void WordTree::parseDict(){
    string str;
    ifstream in("dictionary.txt");
    if(in.is_open()){
        //grabs each line of the file and stores them at the current end of the vector
        while(getline(in, str)){
            str = str.substr(0, str.length() - 1);
            m_dictionary.push_back(str);
            //cout << str << endl;
        }
    }
    else{
        cout << "Unable to open file." << endl;
    }
}

vector<string> WordTree::narrowDict(int wordSize){
    vector<string> sameSize;
    for(int i = 0; i < m_dictionary.size(); i++){
        if(m_dictionary.at(i).length() == wordSize){
            sameSize.push_back(m_dictionary.at(i));
        }
    }
    return sameSize;
}

void WordTree::buildList(TreeNode* node, vector<string> &wordList, string endWord){
    int diffs = 0;
    TreeNode* currentNode = new TreeNode();
    node->setChild(currentNode);
    currentNode->setParent(node);
    TreeNode* newNode;
    for(int i = 0; i < wordList.size(); i++){
        for(int j = 0; j < node->getWord().length(); j++){
            if(node->getWord()[j] != wordList[i][j]){
                diffs++;
            }
        }
        if(diffs == 1){
            if(currentNode->getWord() == ""){
                currentNode->setWord(wordList[i]);
                wordList[i] = "";
                buildList(currentNode, wordList, endWord);
                if(currentNode->getWord() == endWord){
                printLadder(currentNode);
                return;
                }
            }
            else{
                newNode = new TreeNode(wordList[i]);
                newNode->setParent(currentNode->getParent());
                wordList[i] = "";
                currentNode->setSibling(newNode);
                currentNode = newNode;
                buildList(currentNode, wordList, endWord);
                if(currentNode->getWord() == endWord){
                printLadder(currentNode);
                return;
                }
            }
        }
        diffs = 0;
    } 
    return;
}

void WordTree::buildTree(string start, string end){
    TreeNode* root = new TreeNode(start);
    m_pRoot = root;
    TreeNode* currentNode;
    currentNode = root;
    vector<string> wordList = narrowDict(start.length());
    
    buildList(currentNode, wordList, end);
    if(currentNode->getSibling() != NULL){
        currentNode = currentNode->getSibling();
    }
}

void WordTree::printTree(TreeNode* node){
    if(node->getWord() != ""){
        cout << node->getWord() << endl;
    }
    if(node->getChild() != NULL){
        printTree(node->getChild());
    }
    if(node->getSibling() != NULL){
        printTree(node->getSibling());
    }
}

void WordTree::printLadder(TreeNode* node){
    vector<string> ladder;
    ladder.push_back(node->getWord());
    if(node->getParent() != NULL){
        printLadder(node->getParent());
    }
    for(int i = ladder.size() - 1; i >= 0; i--){
        cout << ladder[i] << endl;
    }
}