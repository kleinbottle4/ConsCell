#include "ConsCell.hpp"
#include <exception>
#include <iostream>

using namespace std;

//ctors
template <class T> ConsCell<T>::ConsCell(){}
template <class T>
ConsCell<T>::ConsCell(T val)
{
	this->val = val;
	this->next = nullptr;
}

template <class T>
ConsCell<T>::ConsCell(const ConsCell<T> &rhs)
{
	this->val = rhs.val;
	ConsCell<T> *p = &rhs, *q = this;
	while (p->next != nullptr)
	{
		ConsCell<T> *n = new ConsCell<T>;
		n->val = p->val;
		n->next = nullptr;
		q->next = n;
		p = p->next;
		q = q->next;
	}

}

//deep destructor (recursive-like)
template <class T>
ConsCell<T>::~ConsCell()
{
	cout << this << " destructor...\n";
	if (next != nullptr)
	{
		cout << this << " calling " << next << " destructor...\n";
		delete next;
	}
	cout << "Deleting " << this << "...\n";
}

//assignment operator
template <class T>
ConsCell<T>& ConsCell<T>::operator= (const ConsCell<T> &rhs)
{

	this->val = rhs.val;
	ConsCell<T> *newptr = &rhs, *oldptr = this;
	while (newptr->next != nullptr)
	{
		oldptr->val = newptr->val;

		newptr = newptr->next;

		if (oldptr->next == nullptr)
		{
			ConsCell<T> *p = new ConsCell<T>();
			p->next = nullptr;
			oldptr = p;
		} else {
			oldptr = oldptr->next;
		}
	}
	if (oldptr->next != nullptr)
		delete oldptr->next;
	return *this;
}

template <class T>
ConsCell<T>* ConsCell<T>::getptr(T index)
{
	ConsCell<T> *p = this;
	for (int i = 0; i < index; i++)
	{
		if (p == nullptr)
			throw "index out of range";
		else
			p = p->next;
	}
	return p;
}
//  a . -> b . -> c . -> nullptr

template <class T>
void ConsCell<T>::insert(int index, T val)
{
	ConsCell<T> *oldpos = getptr(index);
	ConsCell<T> *newpos = new ConsCell<T>();
	newpos->val = oldpos->val;
	oldpos->val = val;
	newpos->next = oldpos->next;
	oldpos->next = newpos;
}

template <class T>
T& ConsCell<T>::operator[](int index)
{
	ConsCell<T> *p;
	try
	{
		p = this->getptr(index);
	}
	catch (const char * e)
	{
		throw e;
	}
	if (p == nullptr)
		throw "index out of range";
	else
		return p->val;
}

template <class T>
T ConsCell<T>::getval(int index)
{
	try
	{
		ConsCell<T> *p = getptr(index);
		return p->val;
	}
	catch (const char *)
	{
		throw "index out of range";
	}
}

template <class T>
void ConsCell<T>::remove(int index)
{
	if (index == 0)
	{
		ConsCell<T> *post = this->next;
		this->val = post->val;
		this->next = post->next;
		post->next = nullptr;
		delete post;
	} else {
		ConsCell<T> *pre, *bad;
		try {
			pre = getptr(index - 1);
		} catch (const char * e) {
			throw "index out of range";
		}
		if (pre == nullptr)
			throw "index out of range";
		else {
			bad = pre->next;
			if (bad == nullptr)
				throw "index out of range";
			else {
				pre->next = bad->next;
				bad->next = nullptr;
				delete bad;
			}
		}
	}
}

template <class T>
void ConsCell<T>::add(T val)
{
	ConsCell<T> *n_node = new ConsCell<T>(val);
	n_node->next = nullptr;
	ConsCell<T> *p = this;
	while (p -> next != nullptr)
	{
		p = p->next;
	}
	p->next = n_node;
}

template <class T>
void ConsCell<T>::setnode(int index, T val)
{
	ConsCell<T> *p;
	try
	{
		p = this->getptr(index);
	}
	catch (const char * err)
	{
		throw err;
	}
	p->val = val;
}

template <class T>
void ConsCell<T>::print(char mode)
{
	ConsCell<T> *p = this;
	int i = 0;
	if (mode != 'p')
		cout << '[';
	else {
		cout << "Size of ConsCell<" << typeid(T).name() << ">:\t" << sizeof(ConsCell<T>);
	}
	do {
		if (mode == 'p') {
			cout << endl
			<< "Index: " << i << "\t"
			<< "Address: " << p << "\t"
			<< "Next: " << p->next << "\t"
			<< "Value: ";
			i++;
		}
		cout << p->val;
		if (mode != 'p')
			cout << ", ";
		p = p->next;
	} while (p != nullptr);
	if (mode != 'p') {
		cout << (char) 8 << (char) 8; //2 backspaces
		cout << ']';
	}
	cout << endl;
}
