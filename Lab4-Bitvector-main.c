#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//create bit vector
struct bitset{
    unsigned * bits;
    int size_in_bits;
    int size_in_words;
    int bits_per_word;
};

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size){
    struct bitset * new_bitset;
    new_bitset=malloc(sizeof(struct bitset)); //initialise bit set
    new_bitset->size_in_bits=size; //initialise size is already in bits
    int i;
    new_bitset->bits_per_word= sizeof(unsigned)*8;
    new_bitset->size_in_words = size/new_bitset->bits_per_word; //initialise size in words
    if(size % (new_bitset->bits_per_word)!=0){
        new_bitset->size_in_words++;
    }
    new_bitset->bits=malloc((sizeof(unsigned))* new_bitset->size_in_words);
    //make all zero
    for(i=0;i < new_bitset->size_in_words;i++){
        new_bitset->bits[i]=0; //00000000000
    }
    return new_bitset;
};

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this){
    int result = this->size_in_bits;
    return result;
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){
    int count=0;
    for(int i=0; i< this->size_in_words;i++){
        unsigned * temp = this->bits[i];
        for(int j=0; j< this->bits_per_word;j++){
            if(temp[j] == 1) count++;
        }
    }
    return count;
}

// check to see if an item is in the set //SEG ERROR
int bitset_lookup(struct bitset * this, int item){
        assert(item >= 0 && item < this->size_in_bits);
        int word_index = item / this->bits_per_word;
        int bit_index = item % this->bits_per_word;
        unsigned mask =1<<bit_index;
        int value = this->bits[word_index] & mask;
        return value >> bit_index;

}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
int bitset_add(struct bitset * this, int item){
    assert(item>0 && item < this->size_in_bits);
    int word_index = item / this->bits_per_word;
    int bit_index = item % this->bits_per_word;
    unsigned mask = 1<< bit_index; //make mask to add item to list
    this->bits[word_index]=this->bits[word_index] | mask;  // or mask and array of bits together to set bit to one and add
    return 1 ;
}

// remove an item with number 'item' from the set
int bitset_remove(struct bitset * this, int item){
    assert(item>0 && item < this->size_in_bits);
    int word_index = item / this->bits_per_word;
    int bit_index = item % this->bits_per_word;
    unsigned mask = ~(1<< bit_index);
    this->bits[word_index]=this->bits[word_index] & mask; //and with zero in bit_index place to delete bit and 'item'
    return 1 ;
}


// place the union of src1 and src2 into dest
void bitset_union(struct bitset * dest, struct bitset * src1, struct bitset * src2){
    printf("got in");
    //dest = malloc(sizeof(struct bitset));
    assert(src1->size_in_bits == src2->size_in_bits && src1->bits_per_word == src2->bits_per_word); //make sure src and src are compatible to union
    for(int i=0 ; i <src1->size_in_words; i++) {
        dest->bits[i] = src1->bits[i] | src2->bits[i];
    }
    dest->bits_per_word=src1->bits_per_word;
    dest->size_in_bits=src1->size_in_bits;
    dest->size_in_words=src1->size_in_words;


}

// place the intersection of src1 and src2 into dest
void bitset_intersect(struct bitset * dest, struct bitset * src1, struct bitset * src2){
    //dest = malloc(sizeof(struct bitset));
    assert(src1->size_in_bits == src2->size_in_bits && src1->bits_per_word == src2->bits_per_word); //make sure src and src are compatible to union
    for(int i=0 ; i <src1->size_in_words; i++) {
        dest->bits[i] = src1->bits[i] & src2->bits[i]; //ands together to create set with only items present in both sets
    }
    dest->bits_per_word=src1->bits_per_word;
    dest->size_in_bits=src1->size_in_bits;
    dest->size_in_words=src1->size_in_words;
}

// print the contents of the bitset
void bitset_print(struct bitset * this)
{
    int i;
    int size = bitset_size(this);
    for ( i = 0; i < size; i++ ) {
        if ( bitset_lookup(this, i) == 1 ) {
            printf("%d ", i);
        }


    }
    printf("\n");
}

// add the characters from a string to a bitset
void add_chars_to_set(struct bitset * this, char * s)
{
    int i;
    for ( i = 0; s[i] != 0; i++ ) {
        unsigned char temp = s[i];
        bitset_add(this, temp);
    }
}


//TESTING
// small routine to test a bitset
void mytest()
{
    struct bitset * a = bitset_new(256);
    struct bitset * b = bitset_new(256);
    struct bitset * c = bitset_new(256);
    char * string1 = "What can you hear";
    char * string2 = "Nothing but the rain";

    add_chars_to_set(a, string1);
    add_chars_to_set(b, string2);

    // print the contents of the sets
    bitset_print(a);
    bitset_print(b);



    // compute and print the union of sets
    bitset_union(c, a, b);
    bitset_print(c);

    // compute and print the intersection of sets
    bitset_intersect(c, a, b);
    bitset_print(c);
}
int main() {
    printf("Running Test");
    mytest();
    setvbuf (stdout, NULL, _IONBF, 0);
    printf("Finished Test");
    return 0;
}