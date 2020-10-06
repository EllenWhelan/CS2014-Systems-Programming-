// code for a huffman coder


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>


#include "huff.h"




// create a new huffcoder structure
struct huffcoder *  huffcoder_new()
{
	struct huffcoder* new_huff ;
	 new_huff=malloc(sizeof(struct huffcoder));
	 //int freqs[NUM_CHARS]; maybe for loop to initialise to zero 
	 // int code_lengths[NUM_CHARS];
	 // unsigned long long codes[NUM_CHARS];
	new_huff->tree=NULL;
	return new_huff;
	
};

// count the frequency of characters in a file; set chars with zero
// frequency to one
void huffcoder_count(struct huffcoder * this, char * filename) //issues here 
{
	
	  unsigned char c;  // we need the character to be
						// unsigned to use it as an index
	  FILE * file;
	  file = fopen(filename, "r");
	  assert( file != NULL );
	  
	  c = fgetc(file);	// attempt to read a byte
	  this->freqs[c]++; //EW increment freq array with char
	  while( !feof(file) ) {
		//printf("%c", c);
		c = fgetc(file);
		this->freqs[c]++; //EW increment freq array with char
	  }
	  fclose(file);
	  
	  //make chars with freq zero freq 1
	  for(int i=0; i<NUM_CHARS;i++){
		  if(this->freqs[i] ==0 ) this->freqs[i] ++;
	  }

	 
}

//simple sort alogorithm
void sort_array(struct huffchar * arr[], int size){

        int i, key, j;
        struct huffchar * temp;
        for (i = 1; i < size; i++)
        {
            temp=arr[i];
            key = arr[i]->freq;
            j = i-1;
            while (j >= 0 && arr[j]->freq > key)
            {

                    arr[j + 1] = arr[j];
                    j = j - 1;

            }
            arr[j+1] = temp;
        }

        for ( i=0; i<size-1; i++){
            temp = arr[i];
            if(arr[i]->freq == arr[i+1]->freq){
                if(arr[i]->seqno > arr[i+1]->seqno){
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
        }


}
//simple makecompund struct 
void make_compound(struct huffchar * new_compound, struct huffchar* smallest, struct huffchar* second_smallest, int seqno){


	if(smallest!=NULL && second_smallest!=NULL) new_compound->freq=(smallest->freq + second_smallest->freq);
	new_compound->is_compound=1;
	new_compound->u.compound.left=smallest;
	new_compound->u.compound.right=second_smallest;
	new_compound->seqno=seqno;
}
	
// using the character frequencies build the tree of compound
// and simple characters that are used to compute the Huffman codes
void huffcoder_build_tree(struct huffcoder * this)
{
	//make array of pointers to huffchars
	struct huffchar * char_list[NUM_CHARS];
	for (int i=0; i< NUM_CHARS; i++){
		char_list[i]=malloc(sizeof(struct huffchar));
		char_list[i]->freq=this->freqs[i];
		char_list[i]->is_compound=0;
		char_list[i]->u.c=i;
		char_list[i]->seqno=i;
	}
		
	
	
	
	
	//repeatedly remove 2 least freqs
	int size = NUM_CHARS;
	int seqno=NUM_CHARS;
	while(size>1){
		sort_array(char_list, size);
		struct huffchar * smallest =char_list[0];
		struct huffchar * second_smallest= char_list[1];
		struct huffchar * compound = malloc(sizeof(struct huffchar));
		make_compound(compound, smallest, second_smallest, seqno);
		char_list[1]=compound;
		char_list[0]=NULL;
		for(int j=0; j<size;j++) {
            char_list[j] = char_list[j + 1];

        }
        size=size-1;
		seqno++;
	}
	
	//construct tree 
	this->tree=char_list[0]; //root of tree is compund element in first positoin
	
	
		
}


// recursive function to convert the Huffman tree into a table of
// Huffman codes
//int * is a fuckign array
void tree2table_recursive(struct huffcoder * this, struct huffchar * node,
		 int * path, int depth)
{
	if(node->is_compound ==1){
		if(node->u.compound.left !=NULL){
			int * temp = malloc(sizeof(int )* depth +1);	
			int i;
			for(i=0; i<depth; i++){
				temp[i]=path[i];
				
			}
			temp[i]=0;
			tree2table_recursive(this, node->u.compound.left,temp, depth+1);
		}
		if(node->u.compound.right !=NULL){
			int * temp = malloc(sizeof(int )* depth +1);	
			int i;
			for(i=0; i<depth; i++){
				temp[i]=path[i];
				
			}
			temp[i]=1;
			tree2table_recursive(this, node->u.compound.right,temp, depth+1);
		}
	}
	else{
		unsigned long long temp_code=0;
		int i;
		for(i=0; i<depth;i++){

				if(path[i]==0) temp_code=(temp_code <<1) | 0;
				if(path[i]==1) temp_code=(temp_code <<1) | 1;
				//this->code_lengths[node->u.c]=this->code_lengths[node->u.c] +1;

		}
		this->codes[node->u.c]=temp_code;
		this->code_lengths[node->u.c]=depth;
		
	}
}

// using the Huffman tree, build a table of the Huffman codes
// with the huffcoder object
void huffcoder_tree2table(struct huffcoder * this)
{
	tree2table_recursive(this, this->tree, 0,0);
}


// print the Huffman codes for each character in order
void huffcoder_print_codes(struct huffcoder * this)
{
  int i, j;
  char buffer[NUM_CHARS];

  for ( i = 0; i < NUM_CHARS; i++ ) {
    // put the code into a string
    for ( j = this->code_lengths[i]-1; j >= 0; j--) {
     // buffer[j] = (this->codes[i] >> j) & 1 + '0';
     buffer[j]=((this->codes[i] >> (this->code_lengths[i]-j-1))&1) +'0';
    }
    // don't forget to add a zero to end of string
    buffer[this->code_lengths[i]] = '\0';

    // print the code
    printf("char: %d, freq: %d, code: %s\n", i, this->freqs[i], buffer);;
  }
}
