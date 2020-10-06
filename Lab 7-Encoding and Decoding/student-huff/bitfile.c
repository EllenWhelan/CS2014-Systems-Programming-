// C code file for  a file ADT where we can read a single bit at a
// time, or write a single bit at a time

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "bitfile.h"

// open a bit file in "r" (read) mode or "w" (write) mode
struct bitfile * bitfile_open(char * filename, char * mode)
{
 struct bitfile * result;
 result= malloc(sizeof(struct bitfile));
 result->buffer=0;
 result->index=0;
 result->file = fopen(filename, mode);
 if(strcmp(mode,"r")==0) result->is_read_mode=1;
 else result->is_read_mode=0;
 result->is_EOF=0;
 return result;
}

// write a bit to a file; the file must have been opened in write mode
void bitfile_write_bit(struct bitfile * this, int bit)
{
    assert(this->is_read_mode==0);
    if(bit==1){
        this->buffer=this->buffer|(1 << (this->index));
    }
    this->index++;
    assert(this->index <=8);
    if(this->index==8){
        fputc( this->buffer, this->file);
        this->index=0;
        this->buffer=0;
    }
}

// read a bit from a file; the file must have been opened in read mode
int bitfile_read_bit(struct bitfile *this) {
    assert(this->is_read_mode == 1);
    if (this->index==8) {
        this->buffer = (unsigned char) fgetc(this->file);
        this->index=0;
    }
    int return_val=(this->buffer >> (this->index))& 1;
    this->index++;
    return return_val;
}

// close a bitfile; flush any partially-filled buffer if file is open
// in write mode
void bitfile_close(struct bitfile * this) {
    fputc(this->buffer, this->file);
    fclose(this->file);

}

// check for end of file
int bitfile_end_of_file(struct bitfile * this)
{
    if(feof(this->file)!=0){
        this->is_EOF=1;
    }
    return this->is_EOF;
}
