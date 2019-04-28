#include <iostream>
#include "Tree.h"


int main()
{
	TreeNode<char>* g = new TreeNode<char>('G');
	TreeNode<char>* h = new TreeNode<char>('H');
	TreeNode<char>* f = new TreeNode<char>('F', g, h);
	TreeNode<char>* e = new TreeNode<char>('E');
	TreeNode<char>* c = new TreeNode<char>('C', e, f);
	TreeNode<char>* d = new TreeNode<char>('D');
	TreeNode<char>* b = new TreeNode<char>('B', nullptr, d);
	TreeNode<char>* a = new TreeNode<char>('A', b, c);

	Tree<char> tree{ a };

	tree.preOrder();
	tree.preOrder_iter();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();

	std::cout << "\nLeafs count: " << tree.leafCount();

	std::cout << "\nWidth: " << tree.width() << std::endl;
	std::cout << "\Height: " << tree.height() << std::endl;

	std::cout << std::boolalpha << tree.find('A') << std::endl;
	std::cout << std::boolalpha << tree.find('Q') << std::endl;

	std::cout << std::boolalpha << tree.strongBT() << std::endl;
	system("pause");
	return 0;
}