all: WordTree

WordTree: TreeNode.o WordTree.o Main.o
	g++ TreeNode.o WordTree.o Main.o -o a.out
	 
debug: TreeNode.o WordTree.o Main.o
	g++ -ggdb3 -O0 TreeNode.o WordTree.o Main.o -o a.out
	
TreeNode.o: TreeNode.cpp TreeNode.h
	g++ -ggdb3 -O0 -c TreeNode.cpp

WordTree.o: WordTree.cpp WordTree.h
	g++ -ggdb3 -O0 -c WordTree.cpp
	
Main.o: Main.cpp
	g++ -ggdb3 -O0 -c Main.cpp
	
clean:
	rm *o 