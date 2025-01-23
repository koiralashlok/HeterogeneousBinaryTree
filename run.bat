gcc -c src/Node.c
gcc -c src/BinaryTree.c
gcc -c Main.c

gcc Node.o BinaryTree.o Main.o -o sampleTree

del Node.o
del BinaryTree.o
del Main.o

.\sampleTree.exe

del sampleTree.exe