#pragma once

#include "TreeNode.h"

#include <queue>
#include <stack>

template<typename T>
class Tree
{
public:

	Tree(TreeNode<T>* node);

	void preOrder() const;

	void preOrder_iter() const;

	void inOrder() const;

	void inOrder_iter() const;

	void postOrder() const;

	void postOrder_iter() const;

	void zigzagOrder() const;

	void levelOrder() const;

	size_t leafCount() const;

	size_t width() const;

	size_t height() const;

	bool find(const T& value) const;

	bool strongBT() const;

private:

	static void preOrder(TreeNode<T>* node);

	static void preOrder_iter(TreeNode<T>* node);

	static void inOrder(TreeNode<T>* node);

	static void inOrder_iter(TreeNode<T>* node);

	static void postOrder(TreeNode<T>* node);

	static void postOrder_iter(TreeNode<T>* node);

	static void levelOrder(TreeNode<T>* node);

	static void zigzagOrder(TreeNode<T>* node);

	static size_t leafCount(TreeNode<T>* node);
	
	static size_t width(TreeNode<T>* node);

	static size_t height(TreeNode<T>* node);

	static bool find(TreeNode<T>* node, const T& value);

	static bool strongBT(TreeNode<T>* node);

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
inline void Tree<T>::preOrder_iter() const
{

}

template<typename T>
inline void Tree<T>::postOrder_iter() const
{
	std::cout << "\nPostorder_Iter" << std::endl;

	if (nullptr == m_root)
	{
		return;
	}

	return postOrder_iter(m_root);
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
inline void Tree<T>::inOrder_iter() const
{
	if (nullptr == m_root)
	{
		return;
	}

	return inOrder_iter(m_root);
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
inline void Tree<T>::zigzagOrder() const
{
	if (nullptr == m_root)
	{
		return;
	}

	zigzagOrder(m_root);
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
inline void Tree<T>::preOrder_iter(TreeNode<T>* node)
{
	std::stack<TreeNode<T>*> s;

	auto tmp = node;

	while (true)
	{
		while (nullptr != tmp)
		{
			std::cout << tmp->data << " ";
			s.push(tmp);

			tmp = tmp->left;
		}

		if (s.empty())
		{
			break;
		}

		tmp = s.top()->right;
		s.pop();
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
inline void Tree<T>::inOrder_iter(TreeNode<T>* node)
{
	std::stack<TreeNode<T>*> s;

	auto tmp = node;

	while (true)
	{
		while (nullptr != tmp)
		{
			s.push(tmp);

			tmp = tmp->left;
		}

		if (s.empty())
		{
			break;
		}

		tmp = s.top();
		std::cout << tmp->data << " ";
		tmp = tmp->right;
		s.pop();
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
inline void Tree<T>::postOrder_iter(TreeNode<T>* node)
{
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
inline size_t Tree<T>::width(TreeNode<T>* node)
{
	std::queue<TreeNode<T>*> q;
	q.push(node);
	
	auto max{ q.size() };

	while (!q.empty())
	{
		const auto q_size = q.size();

		max = std::max(max, q_size);
		for (auto i = 0u; i < q_size; ++i)
		{
			auto tmp = q.front();
			q.pop();

			if (nullptr != tmp->left)
			{
				q.push(tmp->left);
			}
			if (nullptr != tmp->right)
			{
				q.push(tmp->right);
			}
		}
	}

	return max;
}

template<typename T>
inline size_t Tree<T>::height(TreeNode<T>* node)
{
	if (nullptr == node)
	{
		return 0u;
	}

	return std::max(height(node->left), height(node->right)) + 1;
}

template<typename T>
inline bool Tree<T>::find(TreeNode<T>* node, const T & value)
{
	if (nullptr == node)
	{
		return false;
	}
	if (value == node->data)
	{
		return true;
	}

	return (find(node->left, value) || find(node->right, value));
}

template<typename T>
inline bool Tree<T>::strongBT(TreeNode<T>* node)
{
	if (nullptr == node->left && nullptr == node->right)
	{
		return true;
	}
	if ((nullptr == node->left && nullptr != node->right) && (nullptr != node->left && nullptr == node->right))
	{
		return false;
	}

	return strongBT(node->left) && strongBT(node->right);
}

template<typename T>
inline void Tree<T>::zigzagOrder(TreeNode<T>* node)
{
	/*auto push_left = [&q](auto node)
	{
		if (nullptr != node->left)
		{
			q.push(node->left);
		}
	};

	auto push_right = [&q](auto node)
	{
		if (nullptr != node->left)
		{
			q.push(node->left);
		}
	};

	std::queue<TreeNode<T>*> q;
	q.push(node);

	bool to_left = false;

	while (!q.empty())
	{

		to_left = !to_left;

		for (auto i = 0u; i < q_size; ++i)
		{
			auto tmp = q.front();
			q.pop();

			std::cout << node->data << " ";

			if (to_left)
			{
				q.push(tmp->left);
				q.push(tmp->right);
			}
			if (!to_left)
			{
				q.push(tmp->right);
				q.push(tmp->left);
			}
		}

	}	*/
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

template<typename T>
inline size_t Tree<T>::width() const
{
	if (m_root == nullptr)
	{
		return 0u;
	}

	return width(m_root);
}

template<typename T>
inline size_t Tree<T>::height() const
{
	if (nullptr == m_root)
	{
		return 0u;
	}

	return height(m_root);
}

template<typename T>
inline bool Tree<T>::find(const T& value) const
{
	if (nullptr == m_root)
	{
		return false;
	}

	return find(m_root, value);
}

template<typename T>
inline bool Tree<T>::strongBT() const
{
	if (nullptr == m_root)
	{
		return false;
	}

	return strongBT(m_root);
}
