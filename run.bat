gcc -c src/Node.c
gcc -c src/BinaryTree.c
gcc -c Main.c

gcc Node.o BinaryTree.o Main.o -o testTree

del Node.o
del BinaryTree.o
del Main.o

.\testTree.exe

del testTree.exe