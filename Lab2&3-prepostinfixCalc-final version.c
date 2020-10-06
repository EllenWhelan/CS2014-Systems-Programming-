#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>


	
//FILE STUFF
/* Open a file to read it */
FILE * open_file_read(char filename[])
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
FILE * open_file_write(char filename[])
{
  FILE * file;

  file = fopen(filename, "a");
  if ( file == NULL ) {
    printf("FATAL : Error opening file  write %s. Aborting program.\n", filename);
    exit(1);
  }

  return file;
}

//code is redundant now as making the code work for the autmated system resulted in the file being read in the mainline
//Read in file and put in char array input
void read_in (char filename[], char input[], int max_line) //(char a[], int size, char filename[])
{
  
  FILE * file;
  file = open_file_read(filename); // open file 
  fgets(input, max_line, file); // reads line from specified and puts it in line
  printf("\nFor the equation: %s\n", input); //print to terminal 
  fclose(file);//close file
  
}
//write to file 
void write_out(char filename[], char input[])
{
 FILE * file;
 file = open_file_write(filename);
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

//PUSH AND POP
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
	int size_of_array = strlen(input); //size in bytes
	char token;
	int i;
		for ( i=0; i< size_of_array; i++){
			
			token = input [i] ; 
			if(token !=10 || token!=32){ //not enter key or space

				if (token >=48.00 && token <=57.00) //is a number
				{ 
					if(i < size_of_array-1 && input[i+1] ==32.00)
					{ //next char is a space ascii value
						if(temp!=0) push(stack, (temp+ (token-48.00))); //add it to list and it is a multi digit number
						else push(stack, token-48.00);//add it to list and single digit number
						temp = 0.00;
					}
					else
					{
						temp=(token - 48.00)*10.00;//convert to decimal
					}
				}
				else if(token=='+' || token == '-' || token=='X' || token=='/' || token=='^')  //token is a operand
				{						
					double item1=pop(stack);
					double item2=pop(stack);
					double result=0.00;
					if (token =='+') result= item1 + item2;
					else if(token =='-') result= item2-item1;
					else if(token =='X') result= item1 * item2;
					else if(token == '^')result= pow(item2, item1);
					else if (token =='/') result = item2 / item1;
					push(stack,result);
				}
				
			}
			else{ 	//debugging
				//printf("enter key or space");
				//printf("%d\n", i);
			}
		}
	computationResult=pop(stack);//pop final result off		
	printf(" \nThe Result is: %.2lf \n", computationResult);//print result to terminal
	return computationResult; //returns double result to main line		
}


//CONVERSIONS
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

		
//convert infix to postfix	
void convert_to_postfix(char input[]){
	struct list *this =new_empty_list();
	int array_size = strlen(input)-1;
	char tempArray[100]; 
	int tempIndex = 0;
	for(int i = 0; i< array_size; i++){
		char token = input[i];
		if(token != 32 && token != '\0'){//spaces ignored
			if(token>47 && token<58){//is a number
				int j = i + 1;
				tempArray[tempIndex++] = token;
				while(input[j] != 32 && j< array_size){// not a space so is oduble digits
					char next = input[j];
					tempArray[tempIndex++] = next;
					i = j;
					j++;
				}
				tempArray[tempIndex++] = ' ';
				
			}
			else if(token == '('){
				push(this, token);
			}
			else if(token == '^' || token == 'X' || token == '/' || token == '+' || token == '-'){//operator
				if(this -> head != NULL){
					char stack_operator = pop(this);
					bool stackEmpty = false;
					bool addedToString = false;
					int tokenPrecedence = find_precedence(token);
					int stackPrecedence= find_precedence(stack_operator);
					while(stack_operator != '(' && stackPrecedence >= tokenPrecedence && !stackEmpty){
						tempArray[tempIndex++] = stack_operator;
						addedToString = true;
						if(this -> head != NULL){
							stack_operator = pop(this);
							addedToString = false;
						}
						else{
							stackEmpty = true;				
						}
					}
					if(addedToString == false){
						push(this, stack_operator);
					}
				}
				push(this, token);
			}
			else if(token == ')'){
				char stack_operator = pop(this);
				while(stack_operator != '('){
					tempArray[tempIndex++] = stack_operator;
					tempArray[tempIndex++] = ' ';
					stack_operator = pop(this);
				}
			}
		}

	}
	while(this -> head != NULL){
		char stack_operator = pop(this);
		tempArray[tempIndex++] = stack_operator;
		
	}

	tempArray[tempIndex] = '\0';//null terminating

	for(int i = 0; i<=strlen(tempArray); i++){
		if(tempArray[i] !=10)input[i] = tempArray[i];
		else input[i] =' ';	
	}

}
	
			
		

			

			


//MAINLINE
//mainline to run program
int main(int argc, char **argv)
{
	const int max_size = 1000;
	char input[max_size];
	//read in file and create output file
	char * filename;
	  if ( argc == 1 ) {
	    printf("Error: No input filename provided\n");
	    printf("Usage: %s <input filename>\n", argv[0]);
	    exit(1);
	  }
	  else if ( argc > 2 ) {
	    printf("Error: Too many command line parameters\n");
	    printf("Usage: %s <input filename>\n", argv[0]);
	    exit(1);
	  }
	  else {
	    filename = argv[1];
	    
	  }
	

	char  tempFileName[max_size];
	char result_append[]= ".results";
	char * result_file;
	strcpy(tempFileName, filename);
	result_file= strcat(tempFileName,result_append);

	FILE * file;
	file = open_file_read(filename); // open file
	//reads file line be line
	while(fgets(input, max_size, file)!=0){ 
		write_out(result_file, input) ;
		if(input[0] == 'i')convert_to_postfix(input);
		//print out to file answer
		double result=compute_expression(input);
		//write out result
		char result_output[max_size];
		sprintf(result_output,"%2.4f\n" , result);//converting double value to char array
		write_out(result_file, result_output);
		memset(input, 0, sizeof(input));
		
	}
	fclose(file);//close file
	return 0;
}














