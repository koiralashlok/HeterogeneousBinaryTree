gcc -c ../src/Node.c
gcc -c ../src/BinaryTree.c
gcc -c Tests.c

gcc Node.o BinaryTree.o Tests.o -o testTree

del Node.o
del BinaryTree.o
del Tests.o

.\testTree.exe

del testTree.exe