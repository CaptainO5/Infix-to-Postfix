#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
	char data;
	struct node * next;
};

class stack {
	private:
		struct node * top;
		bool isEmpty();
	public: 
		int pop(char *);
		int push(char);
		int peek(char *);
		stack();
};
