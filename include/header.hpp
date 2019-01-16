// Copyright 2018 Tygydyk

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
struct Node
{
	T x;
	Node <T> *head, *next;
};

template <typename T>
class Stack
{
	Node <T> *h;
public:

	void push(T &value)
	{
		Node<T> *temp = new Node<T>;
		temp->x = value;
		temp->next = h;
		h = temp;
	}

	void push(T &&value)
	{
		Node<T> *temp = new Node<T>;
		temp->next = h;
		temp->x = value;
		h = move(temp);
	}

	template <class... Args>
	void push_emplace(Args&&... value)
	{
		for (auto t : std::initializer_list<T>{ value... })
		{
			Node<T> *temp = new Node<T>;
			temp->next = h;
			temp->x = t;
			h = move(temp);
		}
	}

	void pop()
	{
		Node <T> *t = h;
		h = h->next;
		delete t;
	}

	T& head()
	{
		return h->x;
	}

};

#endif // INCLUDE_HEADER_HPP_
