//Infix to Prefix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
#define MAX 50

char* memory(){
    return (char*) malloc(sizeof(char)*MAX);
}

void push(char* stack, char to_push, int *tos){
    (*tos)++;
    stack[*tos] = to_push;
}

void pop(char* stack, int *tos){
    (*tos)--;
}


void see_all(char* stack, int *tos){
    int i;
    for(i = 0; i < *tos; i++)    {
        printf("%c", stack[i]);
    }
}

char* reverse_string(char* input){
    int length = strlen(input);
    int i;

    char* outputs = memory();

    for(i = length-1; i >= 0; i--)
        outputs[length - i - 1] = input[i];

    return outputs;
}

bool is_operator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
        return true;
    else return false;
}

int precedence(char a){
    if (a == '^')
        return 4;
    else if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    return 0;
}

char* assoc(char a){
    if (a == '^')
        return "rtl";
    else
        return "ltr";
    return "";
}

int evaluate(char* output){
    int len = strlen(output);
    char* answer = memory();
    int i,tos=-1;
    
    for(i=len-1; i>=0; i--){
        char a = output[i];
        if(output[i]<='9' && output[i]>='0')
            push(answer, output[i]-'0', &tos);
        else{
            int b1 = answer[tos];
            int b2 = answer[tos-1];
            pop(answer,&tos);
            pop(answer,&tos);
            
            switch(a){
                case '+': push(answer,b1+b2, &tos);break;
                case '-': push(answer,b1-b2, &tos);break;
                case '*': push(answer,b1*b2, &tos);break;
                case '/': push(answer,b1/b2, &tos);break;
                case '^': push(answer,pow(b1,b2), &tos);break;
            } 
        }
            
    }
    return answer[tos];
}

int main()
{
    // 2 stacks: stack and output
    char* stack = memory();
    int tos = -1;
    char* output = memory();
    int too = -1;
    
    int i;
    
    char input[100];
    // Get Input from user
    printf("Input Expression = ");
    // gets(input);
    scanf("%[^\n]%*c", input);

    // Step 1: Reverse the input string
    char* reversed_string = reverse_string(input);

    // Iterate through each character in string.
    int len = strlen(input);
    // printf("Len of string: %d \n",len);
    
    for(i = 0; i < len; i++){
        char a = reversed_string[i];
        if (a == ')')
            push(stack, a, &tos);
        else if (a == '('){
            while(stack[tos] != ')'){
                push(output, stack[tos], &too);
                pop(stack, &tos);
            }
            pop(stack, &tos);
        }
        else if (is_operator(a)){
            if(precedence(a) > precedence(stack[tos]))
                push(stack, a, &tos);
            else if (precedence(a) < precedence(stack[tos])){
                while(precedence(stack[tos]) > precedence(a) && tos != -1){
                    push(output, stack[tos], &too);
                    pop(stack, &tos);
                }
                push(stack, a, &tos);
            }
            else{
                if (assoc(stack[tos]) == "ltr")
                    push(stack, a, &tos);
                else if(assoc(stack[tos]) == "rtl"){
                    while(precedence(stack[tos]) > precedence(a) && tos != -1 && assoc(stack[tos]) == "rtl"){
                    push(output, stack[tos], &too);
                    pop(stack, &tos);
                }
                push(stack, a, &tos);
            }    
        }
            
    }
        else if (a == ' ')
            continue;
        else
            push(output, a, &too);
    }
    
    // Append remaining operators to the output
    for(i = 0; i < strlen(stack); i++){
        if(is_operator(stack[i])){
            push(output, stack[tos], &too);
            pop(stack, &tos);
        }
    }
    
    printf("Prefix Expression = %s", reverse_string(output));
    
    int answer = evaluate(reverse_string(output));
    printf("\n%d",answer);

}


