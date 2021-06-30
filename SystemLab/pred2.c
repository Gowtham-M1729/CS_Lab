#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char prol[7][10] = {"S", "A", "B", "B"};
char pror[7][10] = {"AA", "bB", "aB", "@"};
char prod[7][10] = {"S->AA", "A->bB", "B->aB", "B->@"};
char first[7][10] = {"b", "b", "a", "@"};
char follow[7][10] = {"$", "b$", "b$", "b$"};
char table[5][6][10];
/* -------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------*/
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    printf("Popped %c\n", stack->array[stack->top]);
    return stack->array[stack->top--];
}
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top];
}
/* ----------------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------*/
int numr(char c)
{
    switch (c)
    {
    case 'S':
        return 0;
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'a':
        return 0;
    case 'b':
        return 1;
    case '$':
        return 2;
    }
    return (2);
}
void parse()
{
    int i, j, len;
    char str[100], ch;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%s->(%d-%d)    ", table[i][j], i, j);
        }
        printf("\n");
    }
    printf("Enter the String to be Parsed\n");
    scanf("%s", str);
    len = strlen(str);
    str[len] = '$';
    str[len + 1] = '\0';
    len = strlen(str);
    printf("String is:%s\n", str);
    printf("Length of the String is:%d\n\n", len);
    int front = 0;
    struct Stack *stack = createStack(20);
    push(stack, 'S');
    int l = 0;
    while (!isEmpty(stack))
    {
        if (str[front] == stack->array[stack->top])
        {
            pop(stack);
            front++;
        }
        else if ((int)peek(stack) > 90)
        {
            printf("######### Error:String Rejected ##########\n");
            exit(0);
        }
        else if (1)
        {
            int column = numr(str[front]) + 1;
            int row = numr(peek(stack)) + 1;
            if (table[row][column][0] == ' ')
            {
                printf("******Error:String Rejected*******\n");
                exit(0);
            }
            else
            {
                printf("------>%s\n\n", table[row][column]);
                pop(stack);
                i = strlen(table[row][column]) - 1;
                while (i >= 3)
                {

                    ch = table[row][column][i];
                    if (ch == '@')
                    { //printf("%c****%c\n",ch,peek(stack));
                        //pop(stack);
                        break;
                    }
                    else
                    {
                        push(stack, ch);
                    }
                    i--;
                }
            }
        }
        //printf("%s\n",stack->array);
    }
    if (str[front] == '$')
        printf("######## String Accepted ########\n");
    else
        printf("######### Error:String Rejected ##########\n");
}
void main()
{
    int i, j, k;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 6; j++)
            strcpy(table[i][j], " ");
    printf("\nThe following is the predictive parsing table for the following grammar:\n");
    for (i = 0; i < 4; i++)
        printf("%s\n", prod[i]);
    printf("\nPredictive parsing table is\n");
    fflush(stdin);
    for (i = 0; i < 4; i++)
    {
        k = strlen(first[i]);
        for (j = 0; j < k; j++)
        {
            if (first[i][j] != '@')
                strcpy(table[numr(prol[i][0]) + 1][numr(first[i][j]) + 1], prod[i]);
        }
    }
    for (i = 0; i < 7; i++)
    {
        if (strlen(pror[i]) == 1)
        {
            if (pror[i][0] == '@')
            {
                k = strlen(follow[i]);
                for (j = 0; j < k; j++)
                    strcpy(table[numr(prol[i][0]) + 1][numr(follow[i][j]) + 1], prod[i]);
            }
        }
    }
    strcpy(table[0][0], " ");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "b");
    strcpy(table[0][3], "$");
    strcpy(table[1][0], "S");
    strcpy(table[2][0], "A");
    strcpy(table[3][0], "B");
    printf("\n--------------------------------------------------------\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 6; j++)
        {
            printf("%-10s", table[i][j]);
            if (j == 5)
                printf("\n--------------------------------------------------------\n");
        }
    parse();
}
