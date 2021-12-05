//Infix to Postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 50

char* memory_max()
{
    return (char*) malloc(sizeof(char)*MAX);
}

void push(char* stack, char to_push, int *tos)
{
    (*tos)++;
    stack[*tos] = to_push;
}

void pop(char* stack, int *tos)
{
    (*tos)--;
}


void see_all(char* stack, int *tos)
{
    for(int i = 0; i < *tos; i++)
    {
        printf("%c", stack[i]);
    }
}

char* reverse_string(char* input)
{
    int length = strlen(input);

    char* outputs = memory_max();

    for(int i = length-1; i >= 0; i--)
        outputs[length - i - 1] = input[i];

    return outputs;
}

bool is_operator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
    {
        return true;
    }
    else return false;
}

int precedence(char a)
{
    if (a == '^')
    {
        return 4;
    }
    else if (a == '*' || a == '/')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
    {
        return 2;
    }
    return 0;
}

char* assoc(char a)
{
    if (a == '^')
    {
        return "rtl";
    }
    else
    {
        return "ltr";
    }
    return "";
}

int main()
{
    // 2 stacks: stack and output
    char* stack = memory_max();
    int tos = -1;
    char* output = memory_max();
    int too = -1;
    
    
    // Get Input from user
    char input[100];
    
    printf("Input Expression = ");
    // gets(input);
    scanf("%[^\n]%*c", input);

    // Iterate through each character in string.
    int len = strlen(input);
    printf("Len of string: %d \n",len);
    
    for(int i = 0; i < len; i++){
        char a = input[i];
        if (a == '('){
            push(stack, a, &tos);
        }
        else if(isalpha(a)){
            push(output, a, &too);
        }
        else if (is_operator(a)){
            if(precedence(a) > precedence(stack[tos]) || a == '^')
                push(stack, a, &tos);
                
            else if (precedence(a) <= precedence(stack[tos])){
                while(precedence(stack[tos]) >= precedence(a) && tos != -1){
                    push(output, stack[tos], &too);
                    pop(stack, &tos);
                }
                push(stack, a, &tos);
            }
        }
        else if (a == ')'){
            while(stack[tos] != '('){
                push(output, stack[tos], &too);
                pop(stack, &tos);
            }
            pop(stack, &tos);
        }
        else if (a == ' ')
            continue;
    }
    
    // Append remaining operators to the output
    for(int i = 0; i < strlen(stack); i++){
        if(is_operator(stack[i])){
            push(output, stack[tos], &too);
            pop(stack, &tos);
        }
    }
    
    printf("Postfix = %s", output);

}
