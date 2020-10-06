#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


	
//FILE 
/* Open a file to read it */
FILE * open_file_r(char filename[])
{
  FILE * file;

  file = fopen(filename, "r");
  if ( file == NULL ) {
    printf("FATAL: Error opening file %s. Aborting program.\n", filename);
    exit(1);
  }

  return file;
}
//open a file to write to it 
FILE * open_file_w(char filename[])
{
  FILE * file;

  file = fopen(filename, "w+");
  if ( file == NULL ) {
    printf("FATAL: Error opening file  write %s. Aborting program.\n", filename);
    exit(1);
  }

  return file;
}

//Read in file and put in char array input
void read_in (char filename[], char input[], int max_line) //(char a[], int size, char filename[])
{
  
  FILE * file;
  file = open_file_r(filename); // open file 
  fgets(input, max_line, file); // reads line from specified and puts it in line
  printf("\nFor the equation: %s\n", input); //print to terminal 
  fclose(file);//close file
  
}
//write to file 
void write_out(char filename[], char input[])
{
 FILE * file;
 file = open_file_w(filename);
 fputs(input, file);//overwrites file 
 fclose(file);//closes file
}

//LIST STUFF	
struct listnode {

    double data;
    struct listnode *next;

};


struct list {

    struct listnode *head;

};


struct list *new_empty_list() {

    struct list *result;
    result = malloc(sizeof(struct list));
    result -> head = NULL;
    return result;

};

//push and pop
void push(struct list *this, double data) {

    struct listnode *tempNode = malloc(sizeof(struct listnode));
    tempNode->data=data;
    tempNode->next = this->head;
    this->head=tempNode;
}
double pop(struct list *this)
{
	struct listnode *tempNode = this->head;
	this->head=tempNode->next;
	double data = tempNode->data;
	free(tempNode);
	return data;
}





//COMPUTATIONS
//computing value of expression 
double compute_expression(char input[])
{
	struct list *stack = new_empty_list();
	double temp = 0.00;
	double computationResult=0.00;
	int size_of_array = strlen(input) -1; //size in bytes
	char token;
		for (int i=0; i< size_of_array; i++){
			token = input [i] ; 
			if (token >=48.00 && token <=57.00) //is a number
			{ 
				if(input[i+1] ==32.00)
				{ //next char is a space ascii value
					if(temp!=0) push(stack, (temp+ (token-48.00))); //add it to list and it is a multi digit number
					else push(stack, token-48.00);//add it to list and single digit number
					temp = 0.00;
				}
				else
				{
					temp=(token - 48.00)*10.00;
				}
			}
			else if(token=='+' || token == '-' || token=='X' || token=='/' || token=='^')  //token is a operand
			{
				double item1=pop(stack);
				double item2=pop(stack);
				double result=0.00;
				if (token =='+') result= item1 + item2;
				else if(token =='-') result= item1-item2;
				else if(token =='X') result= item1 * item2;
				else if(token == '^')result= pow(item1, item2);
				else if (token =='/') result = item1 / item2;
				push(stack,result);
			}
			//else printf("%s\n", "space");
		}
		computationResult=pop(stack);
				
				
				
				
	printf(" \nThe Result is: %.2lf \n", computationResult);
	return computationResult; //returns double result to main line		
}

//find precedence
int find_precedence(char token)
{ 
	int returnValue=0;
	if(token =='+'|| token == '-') returnValue=3;
	else if(token =='X' || token =='/') returnValue=4;
	else if (token == '^') returnValue = 5;
	else if(token =='(' || token ==')') returnValue=1;
	return returnValue;
}
//convert to rpn 
 void convert_to_rpn(char input[])
{
	struct list *stack = new_empty_list();
	
	int array_size = strlen(input) -1;
	int j =0;
	char tempArray [100];
	for (int i =0; i <array_size ; i++){
		char token = input[i];
		if (token >= 48 && token <= 57){
			tempArray[j] = token;
			j++;
		}
		else if (token == '('){
			push(stack, (double)token);
			printf("Pushing%c\n", token);
		}
		else if(token=='+' || token=='-' || token=='X' || token=='/' || token=='^'){
			if(stack->head != NULL){
				int tokenPrecedence = find_precedence(token);
				struct listnode *tempNode = malloc(sizeof(struct listnode));
				tempNode= stack->head;
				char stackOperator = tempNode->data;
				int stackPrecedence = find_precedence(stackOperator);
				while(stackPrecedence > tokenPrecedence){
					double tempPop = pop(stack);
					printf("Popping:%c\n", (char)tempPop);
					tempArray[j] = (char)tempPop;
					j++;
					tempNode=stack->head;
					stackPrecedence = find_precedence(tempNode->data);
				
				}
				printf("Pushing%c\n", token);
				push(stack, (double)token);
			}
			else {
				printf("Pushing%c\n", token);
				push(stack, (double)token);
			}
		}
		else if(token ==')'){
			struct listnode *tempNode= malloc(sizeof(struct listnode));
			tempNode = stack->head;
			printf("when x needs to come off%c\n", (char)tempNode->data);
			while(tempNode->data !='('){
				double tempPop = pop(stack);
				printf("Popping:%c\n", (char)tempPop);
				tempArray[j] = (char)tempPop;
				j++;
				tempNode=stack->head;	
			}
			printf("Popping:%s\n", "rightbracket");
			pop(stack);
		}
		else if(token == 32){
			tempArray[j] = token;
			j++;
		}
	}
	//printf("Temp before ++:%s", tempArray);
	struct listnode *tempHead = malloc(sizeof(struct listnode));
	tempHead=stack->head;
	while(tempHead){
		double tempPop= pop(stack);
		tempArray[j] = (char)tempPop;
		j++;
		//tempArray[j] = ' ' ;
		//j++;
		tempHead=tempHead->next;
	}
	
	for (int i =0; i< array_size; i++) //update input array for conputation
	{
		if(tempArray[i] !=NULL) input[i]=tempArray[i];
		else input[i] = '$';
	}

 
}
			

			



//mainline to run program
int main()
{
	
	const int max_line = 100;
  	char input[max_line];
	char filename []= "expression.txt";
	read_in("expression.txt", input, max_line);// read in file and make input string
	//printf("%s", "Testing");
	//printf("In preFix form: %s\n", input)
	convert_to_rpn(input);
	printf("In Post Fix Form: %s\n", input);
	double result = compute_expression(input);

	
	return 0;
}














