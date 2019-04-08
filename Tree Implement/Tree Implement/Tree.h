#pragma once

#include "TreeNode.h"

template<typename T>
class Tree
{
public:

	Tree(TreeNode<T>* node);

	void preOrder() const;

	void inOrder() const;

	void postOrder() const;

private:

	static void preOrder(TreeNode<T>* node);

	static void inOrder(TreeNode<T>* node);

	static void postOrder(TreeNode<T>* node);

	TreeNode<T>* m_root;
};

template<typename T>
inline Tree<T>::Tree(TreeNode<T>* node)
	: m_root{node}
{
}

template<typename T>
inline void Tree<T>::preOrder() const 
{
	if (m_root == nullptr)
	{
		return;
	}

	preOrder(m_root);
}

template<typename T>
inline void Tree<T>::inOrder() const
{
	if (m_root == nullptr)
	{
		return;
	}

	inOrder(m_root);
}

template<typename T>
inline void Tree<T>::postOrder() const
{
	if (nullptr == m_root)
	{
		return;
	}

	postOrder(m_root);
}

template<typename T>
inline void Tree<T>::preOrder(TreeNode<T>* node)
{
	std::cout << node->data << std::endl;

	if (node->left != nullptr)
	{
		preOrder(node->left);
	}

	if (node->right != nullptr)
	{
		preOrder(node->right);
	}

}

template<typename T>
inline void Tree<T>::inOrder(TreeNode<T>* node)
{

	if (node->left != nullptr)
	{
		inOrder(node->left);
	}

	std::cout << node->data << std::endl;
	
	if (node->right != nullptr)
	{
		inOrder(node->right);
	}
}

template<typename T>
inline void Tree<T>::postOrder(TreeNode<T>* node)
{
	if (node->left != nullptr)
	{
		postOrder(node->left);
	}

	if (node->right != nullptr)
	{
		postOrder(node->right);
	}
	
	std::cout << node->data << std::endl;
}
