#pragma once

#include "TreeNode.h"

#include <queue>

template<typename T>
class Tree
{
public:

	Tree(TreeNode<T>* node);

	void preOrder() const;

	void inOrder() const;

	void postOrder() const;

	void levelOrder() const;

	size_t leafCount() const;

private:

	static void preOrder(TreeNode<T>* node);

	static void inOrder(TreeNode<T>* node);

	static void postOrder(TreeNode<T>* node);

	static void levelOrder(TreeNode<T>* node);

	static size_t leafCount(TreeNode<T>* node);

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
	std::cout << "\nPreorder" << std::endl;
	if (m_root == nullptr)
	{
		return;
	}

	preOrder(m_root);
}

template<typename T>
inline void Tree<T>::inOrder() const
{
	std::cout << "\nInorder" << std::endl;

	if (m_root == nullptr)
	{
		return;
	}

	inOrder(m_root);
}

template<typename T>
inline void Tree<T>::postOrder() const
{
	std::cout << "\nPostorder" << std::endl;

	if (nullptr == m_root)
	{
		return;
	}

	postOrder(m_root);
}

template<typename T>
inline void Tree<T>::levelOrder() const
{
	std::cout << "\nLevelorder" << std::endl;

	if (nullptr == m_root)
	{
		return;
	}

	levelOrder(m_root);
}

template<typename T>
inline void Tree<T>::preOrder(TreeNode<T>* node)
{
	std::cout << node->data << " ";

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

	std::cout << node->data << " ";
	
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
	
	std::cout << node->data << " ";
}

template<typename T>
inline void Tree<T>::levelOrder(TreeNode<T>* node)
{
	std::queue<TreeNode<T>*> q;
	q.push(node);

	while (!q.empty())
	{
		auto item = q.front();
		q.pop();
	
		std::cout << item->data << " ";

		if (nullptr != item->left)
		{
			q.push(item->left);
		}
		if (nullptr != item->right)
		{
			q.push(item->right);
		}
	}
}

template<typename T>
inline size_t Tree<T>::leafCount(TreeNode<T>* node)
{
	if (nullptr == node->left && nullptr == node->right)
	{
		return 1u;
	}

	size_t res{ 0u };

	if (nullptr != node->left)
	{
		res += leafCount(node->left);
	}
	if (nullptr != node->right)
	{
		res += leafCount(node->right);
	}
	return res;
}

template<typename T>
inline size_t Tree<T>::leafCount() const
{
	if (nullptr == m_root)
	{
		return 0;
	}

	return leafCount(m_root);
}
