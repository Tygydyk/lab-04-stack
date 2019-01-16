// Copyright 2018 Tygydyk

#include <header.hpp>

using namespace std;

int main()
{
	Stack <int> *stack = new Stack<int>;
	stack->push(1);
	cout << stack->head() << endl;
	int a = 2;
	stack->push(a);
	cout << stack->head() << endl;
	stack->pop();
	cout << stack->head() << endl;
	stack->push_emplace(3, 4, 5);
	cout << stack->head() << endl;

	return 0;
}
