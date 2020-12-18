// Author : William McLaughlin
// Course : CS11
// Date : 1 May 2017
// Instructor : Dave Harden
// File : binary.cpp
// Description : This program will have implementations
//               for binary trees, including conversion
//               from binary tree to linked list. 

#include <iostream>
#include "binarytree.h"
using namespace std;






binarytree::binarytree() {
	root = nullptr;
	mSize = 0;
}





binarytree & binarytree::operator = (const binarytree & other) {
	clone(other);
	return *this;
}






binarytree::~binarytree() {
	clear(root);
}




void binarytree::clone(const binarytree & other) {
	clone_aux(other.root);
}





void binarytree::clear() {
//	clear_aux();
}






void binarytree::print() const {
	print_aux(root);
}






void binarytree::insert(int item) {
	insert_aux(root, item);
	mSize++;
}






binarytree::size_type binarytree::size() const {
	return mSize;
}






int binarytree::find(int target, bool& found) const{
	return find_aux(root, target, found);
}






void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
	if (mSize > 0)
		mSize--;
}






binarytree::size_type binarytree::numPrimes() {
	return numPrimes_aux(root);
}






LL<int> binarytree::toLL() {
	LL <int> list;
	LL <int>::iterator itr = nullptr;
	toLL_aux(root, list, itr);
	return list;
}






void del_aux(binarytree::treenode*& root, 
		 int target,
		 bool& found) {

	if (root == nullptr) {
		found = false;
	} else if (target < root -> data) {
		del_aux(root -> left, target, found);
	} else if (target > root -> data) {
		del_aux(root -> right, target, found);
	} else if (root -> left == nullptr) {
		binarytree::treenode* tempptr = root;
		root = root -> right;
		delete tempptr;
		found = true;
	} else {
		int max;
		remove_max(root -> left, max);
		root -> data = max;
		found = true;
	}
}






void remove_max(binarytree::treenode*& root, int& max) {
	if (root -> right == nullptr) {
		max = root -> data;
		binarytree::treenode* tempptr = root;
		root = root -> left;
		delete tempptr;
	} else {
		remove_max(root -> right, max);
	}
}






int find_aux(binarytree::treenode* root, 
		 int target,
		 bool& found) {

	if (root == nullptr) {
		found = false;
		return 0;
	} else if (target == root -> data) {
		found = true;
		return root -> data;
	} else if (target < root -> data) {
		return find_aux(root -> left, target, found);
	} else {
		return find_aux(root -> right, target, found);
	}
}






void insert_aux(binarytree::treenode*& root, int item) {
	if (root == nullptr) {
		root = new binarytree::treenode;
		root -> data = item;
		root -> left = nullptr;
		root -> right = nullptr;
	} else if (item <= root -> data) {
		insert_aux(root -> left, item);
	} else {
		insert_aux(root -> right, item);
	}
}






void print_aux(binarytree::treenode* root) {
	if (root != nullptr) {
		print_aux(root -> left);
		cout << root -> data << " ";
		print_aux(root -> right);
	}
}






bool isPrime(int value) {
	for (int i = 1; i <= value; i++) {
		if (value == 1 || (value % i == 0 && i != 1 &&  i != value)) {
			return false;
		}
	}
	return true;
}






binarytree::size_type numPrimes_aux(binarytree::treenode* root) {	
	if (root != nullptr) {
		if (isPrime(root -> data))
			return numPrimes_aux(root -> left) + numPrimes_aux(root -> right) + 1;
		return numPrimes_aux(root -> left) + numPrimes_aux(root -> right);
	}
	return 0;
}






void toLL_aux(binarytree::treenode* root, LL<int> &list, LL<int>::iterator &itr) {
	if (root != nullptr) {
		
		toLL_aux(root -> left, list, itr);

		if (list.empty()) {
			list.push_front(root -> data);
			itr = list.begin();
		} else {
			list.insert_after(itr, root -> data);
		}

		toLL_aux(root -> right, list, itr);
	}	
}





void clone_aux(const binarytree::treenode* root) {
	cout << "clone called" << endl;
	if (root != nullptr) {
		clone_aux(root -> left);
		binarytree::treenode* newRoot;
		newRoot->data = root->data;
		clone_aux(root -> right);
	}
}




void clear_aux(binarytree::treenode* root) {
	cout << "clear called" << endl;
}
