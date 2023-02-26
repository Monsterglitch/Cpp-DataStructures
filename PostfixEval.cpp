// #include<iostream>
// #include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack) return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    if(!stack->array) return NULL;
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->top == -1; //  the current top value with -1
}
char push(struct Stack* stack, char val) {
    return stack->array[++stack->top] = val; // pushing the current value
}
char pop(struct Stack* stack) {
    if(!isEmpty(stack)){
        return stack->array[stack->top--]; // popping the top value if stack is not empty
    }
    return '$';
}
int postfixeval(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    if (!stack) return -1;
    for (int i = 0; exp[i]; ++i) {
        if (isdigit(exp[i])) // isdigit() is an inbuilt function
            push(stack, exp[i] - '0');
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}
int main() {
    char exp[] = "231*+9-";
    cout<<"Postfix Evaluation: "<<postfixeval(exp);
    return 0;
}
