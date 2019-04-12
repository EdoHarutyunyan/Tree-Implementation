#include <iostream>
#include "Tree.h"


int main()
{
	TreeNode<char>* f = new TreeNode<char>('F');
	TreeNode<char>* e = new TreeNode<char>('E');
	TreeNode<char>* c = new TreeNode<char>('C', e, f);
	TreeNode<char>* d = new TreeNode<char>('D');
	TreeNode<char>* b = new TreeNode<char>('B', nullptr, d);
	TreeNode<char>* a = new TreeNode<char>('A', b, c);

	Tree<char> tree{ a };

	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();

	std::cout << "\nLeafs count: " << tree.leafCount();

	system("pause");
	return 0;
}