all: WordTree

WordTree: TreeNode.o	
	g++ TreeNode -o a.out
	
debug: TreeNode.o
	g++ -ggdb3 -O0 TreeNode.o -o a.out
	
TreeNode.o: TreeNode.cpp TreeNode.h
	g++ -ggdb3 -O0 -c TreeNode.cpp
	
clean:
	rm *o 