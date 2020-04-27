#include"CPI.h"


int precedence(char op) {
	switch(op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}

int convertPI(char infix[], char postfix[]) {
	stack s;
	char check;
	int i = 0, j = 0;
	while(infix[i] != '\0') {
		if(infix[i] == '(') {
			s.push(infix[i]);
		} else if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z')) {
			postfix[j] = infix[i];
			j++;
		} else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			if(!s.peek(&check))
				if(precedence(check) >= precedence(infix[i])) {
					s.pop(&check);
					postfix[j] = check;
					j++;
				}
			s.push(infix[i]);
		} else if(infix[i] == ')' ) {
			while(!s.pop(&check) && check != '(') {
				postfix[j] = check;
				j++;
			}	
		} else {
			cout << "ERROR: WRONG INPUT\n";
			return 1;
		}
		i++;	
	}
	while(!s.pop(&check)) {
		postfix[j] = check;
		j++;
	}		
	postfix[j] = '\0';
	return 0;
}

int print(char p[]) {
	int i = 0;
	while(p[i] != '\0') {
		cout << p[i];
		i++;
	}
	cout << endl;
}
