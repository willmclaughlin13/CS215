#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "LL.h"

class binarytree {

	public:
		typedef std::size_t size_type;
		binarytree();
		~binarytree();
		binarytree(const binarytree & other);
		void insert(int item);
		void print() const;
		size_type size() const;
		int find(int target, bool& found) const;
		void del(int target, bool& found);
		size_type numPrimes();
		LL<int> toLL();
		void clear();
		void clone(const binarytree &other);
		binarytree & operator = (const binarytree & other);
	private:
		struct treenode {
			int data;
			treenode* left;
			treenode* right;
		};
		treenode* root;
		size_type mSize;
		friend void clear_aux(treenode* root);
		friend void clone_aux(const treenode* root);
		friend bool isPrime(int value);
		friend void toLL_aux(treenode* root, LL <int> &list, LL<int>::iterator &itr);
		friend size_type numPrimes_aux(treenode* root);
		friend void insert_aux(treenode*& root, int item);
		friend void print_aux(treenode* root);
		friend int find_aux(treenode* root, int target, bool& found);
		friend void del_aux(treenode*& root, int target, bool& found);
		friend void remove_max(treenode*& root, int& max);
};
#endif
