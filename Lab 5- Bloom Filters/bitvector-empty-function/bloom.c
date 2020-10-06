#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "bloom.h"

const int BLOOM_HASH1 = 17; //seeds
const int BLOOM_HASH2 = 29;

// compute a hash of a string using a seed value, where the result
// falls between zero and range-1
int hash_string(char * string, int seed, int range)
{
  int i;
  int hash = 0;

  // simple loop for mixing the input string
  for ( i = 0; string[i] != '\0'; i++ ) {
    hash = hash * seed + string[i];
  }
  // check for unlikely case that hash is negative
  if ( hash < 0 ) {
    hash = -hash;
  }
  // bring the hash within the range 0..range-1
  hash = hash % range;
  
  return hash;
}

// create a new, empty Bloom filter with 'size' slots
struct bloom * bloom_new(int size)
{
  struct bloom * new_bloom;
  new_bloom=malloc(sizeof(struct bitset)); //initialise bit set
  new_bloom->bit_vector->size_in_bits=size; //initialise size is already in bits
  int i;
  new_bloom->bit_vector->bits_per_word= sizeof(unsigned)*8;
  new_bloom->bit_vector->size_in_words = size/new_bloom->bit_vector->bits_per_word; //initialise size in words
  if(size % (new_bloom->bit_vector->bits_per_word)!=0){
    new_bloom->bit_vector->size_in_words++;
  }
  new_bloom->bit_vector->bits=malloc((sizeof(unsigned))* new_bloom->bit_vector->size_in_words);
  //make all zero
  for(i=0;i < new_bloom->bit_vector->size_in_words;i++){
    new_bloom->bit_vector->bits[i]=0; //00000000000
  }
  return new_bloom;
}

// check to see if a string is in the set
int bloom_lookup(struct bloom * this, char * item) //hash item first
{
  int hash1 = hash_string(item, BLOOM_HASH1, this->size);
  int hash2=hash_string(item, BLOOM_HASH2, this->size);
  return ((bitset_lookup(this->bit_vector, hash1)) && (bitset_lookup(this->bit_vector, hash2)));

}

// add a string to the set has no effect if the item is already in the
// set; note that you cannot safely remove items from a Bloom filter
void bloom_add(struct bloom * this, char * item)
{
  int hash1 = hash_string(item, BLOOM_HASH1, this->size);
  int hash2=hash_string(item, BLOOM_HASH2, this->size);
  bitset_add(this->bit_vector, hash1);
  bitset_add(this->bit_vector, hash2);

}

// place the union of src1 and src2 into dest
void bloom_union(struct bloom * dest, struct bloom * src1,
		  struct bloom * src2)
{
  printf("got in");
  //dest = malloc(sizeof(struct bitset));
  assert(src1->bit_vector->size_in_bits == src2->bit_vector->size_in_bits && src1->bit_vector->bits_per_word == src2->bit_vector->bits_per_word); //make sure src and src are compatible to union
  for(int i=0 ; i <src1->bit_vector->size_in_words; i++) {
    dest->bit_vector->bits[i] = src1->bit_vector->bits[i] | src2->bit_vector->bits[i];
  }
  dest->bit_vector->bits_per_word=src1->bit_vector->bits_per_word;
  dest->bit_vector->size_in_bits=src1->bit_vector->size_in_bits;
  dest->bit_vector->size_in_words=src1->bit_vector->size_in_words;
}

// place the intersection of src1 and src2 into dest
void bloom_intersect(struct bloom * dest, struct bloom * src1,
                  struct bloom * src2)
{
  //dest = malloc(sizeof(struct bitset));
  assert(src1->bit_vector->size_in_bits == src2->bit_vector->size_in_bits && src1->bit_vector->bits_per_word == src2->bit_vector->bits_per_word); //make sure src and src are compatible to union
  for(int i=0 ; i <src1->bit_vector->size_in_words; i++) {
    dest->bit_vector->bits[i] = src1->bit_vector->bits[i] & src2->bit_vector->bits[i]; //ands together to create set with only items present in both sets
  }
  dest->bit_vector->bits_per_word=src1->bit_vector->bits_per_word;
  dest->bit_vector->size_in_bits=src1->bit_vector->size_in_bits;
  dest->bit_vector->size_in_words=src1->bit_vector->size_in_words;
}

// print out the bits that are 1 in the bit vector of
// a bloom filter
void bloom_print(struct bloom * this)
{
  bitset_print(this->bit_vector);
}
