//infix to postfix

#include <stdio.h>
#include <string.h>

struct stackrecord{
    int top;
    char x[100];
};

typedef struct stackrecord STACK;


STACK create(){
    STACK s;
    s.top = -1;
    return s;
}

int isempty(STACK s){
    return s.top == -1;
}

STACK push(STACK s, char y){
    s.x[++s.top] = y;
    return s;
}

STACK pop(STACK s){
    s.top--;
    return s;
}

char topelement(STACK s){
    return s.x[s.top];
}

int precedence(char a){
	if (a == '^') return 3;
	else if (a == '*' || a == '/') return 2;
	else if (a == '+' || a == '-') return 1;
	return -1;
}

void infixToPostfix(char exp[], char ans[]){
	STACK s;
	s = create();
	int p = 0, f = 0;
	for (int i = 0; i < strlen(exp); i++){
		if (exp[i] == '('){
			s = push(s,exp[i]);
			f = 1;
		}
		else if (exp[i] == ')'){
			for (int j = s.top; s.x[s.top] != '('; j++){
				ans[p++] = topelement(s);
				s = pop(s);
			}
			s = pop(s);
		}
		else if (exp[i] >= 'A' && exp[i] <= 'Z')
			ans[p++] = exp[i];
		else{
		    if (f){
    		    s = push(s,exp[i]);
    			f = 0;
		    }
			else if (precedence(exp[i]) >= precedence(topelement(s))){
				s = push(s,exp[i]);
			}
			else{
				while(!(isempty(s) || s.x[s.top] == '(')){
					ans[p++] = topelement(s);
					s = pop(s);
				}
				s = push(s, exp[i]);
			}
		}
	}
	while(!(isempty(s))){
	    ans[p++] = topelement(s);
		s = pop(s);
	}
}


int main(){
	char exp[100];
	scanf("%s", exp);
	char ans[100];
	infixToPostfix(exp,ans);
	printf("%s", ans);
	return 0;
}
