/*
** Made by arch-term. Sorry for my english!! :)
** This program was created with purpose to learn.

- IPN (Reverse Poslish Notation)

The Program:
	1 - Initialize the variables;
	2 - Get the expression input from user;
	3 - Split the expression in all spaces;
	4 - For each token in the expression:
	4.1 - If it is a number, add to stack;
	4.2 - Else if it's not a number, but it's a operator, get the lastes numbers of stack and operate with it before add to stack;
	5 - Show the result for user;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 30
#define MAX_STACK_SIZE 20

int main()
{
	//Initialize the varibles
	int result, stackTop = 0;
	int stack[MAX_STACK_SIZE];
	char expr[MAX_INPUT_SIZE];

	//Get the user input
	printf("Write an expression: ");
	scanf("%[^\n]", &expr);

	//Split the expression
	char *token = strtok(expr, " ");
	while(token != NULL)
	{
		//Verify if the token is a number
		int isnumber = 1;
		for (int i=0;i<strlen(token);i++)
		{
			if (!isdigit(token[i]))
			{
				isnumber = 0;
				break;
			}
		}

		if (isnumber)
		{
			stack[stackTop++] = atoi(token); // Add token top of stack
		}
		else
		{
			// Verify if token is an operator.
			int isoperator = 1;
			int tmpStackTop = stackTop;

			int a = stack[--tmpStackTop];
			int b = stack[--tmpStackTop];

			if (strcmp(token, "+") == 0)
			{
				stack[tmpStackTop] = a + b;
			}
			else if (strcmp(token, "-") == 0)
			{
				stack[tmpStackTop] = a - b;
			}
			else if (strcmp(token, "*") == 0)
			{
				stack[tmpStackTop] = a * b;
			}
			else if (strcmp(token, "/") == 0)
			{
				stack[tmpStackTop] = a / b;
			}
			else isoperator = 0;

			if (isoperator == 1) stackTop = ++tmpStackTop;
		}

		token = strtok(NULL, " ");
	}

	printf("Result of expression is: %d\n", stack[0]); // Show result
	return 0;
}
