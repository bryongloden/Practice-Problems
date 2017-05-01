#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "review.h"

List *mylist;

// Problem (1/4)
/******************************************************************************
 * TODO: Return a pointer to the first occurrence of the character 'c' in the
 * string 's'. Return NULL if the character is not found.
 *
 * Parameters: s -- string
 *             c -- search for this character in the string 's'
 *
 * Return: pointer to the first occurene of the character c in the string s
 *
 * Return Type: char pointer
 *****************************************************************************/
char *strchr(const char *s, int c)
{
	// Write Your Code Here
	int count=0;
	char array1[2];
	char *newstring=malloc(strlen(s));
	newstring=strdup(s);
	array1[1]='\0';
	for (count=0; count<strlen(s); count++){
		array1[0]=s[count];
		if (array1[0]==c){
			return &newstring[count];
		}
	}
	return NULL;
}

// Problem (2/4)
/******************************************************************************
 * TODO: Return the maximum element in the array
 *
 * Parameters: array -- an integer array
 *             n -- number of elements in the array
 *
 * Return: the maximum element in the array
 *
 * Return Type: integer
 *****************************************************************************/
int max_array( int * array, int n )
{
	// Write Your Code Here
	int num = NULL;
	for (int w=0; w<n; w++){
		if (w==0){
			num = array[0];
		}
		else{
			if (array[w]>num){
				num=array[w];
			}
		}
	}
	return num;
}

// Problem (3/4)
/******************************************************************************
 * TODO: Return the 'ith' bit in 'bitmap' (either 0 or 1)
 *
 * Parameters: bitmap -- unsigned integer
 *             ith -- index of the bit to be returned
 *
 * Return: the largest element in the array
 *
 * Return Type: integer
 *****************************************************************************/
int get_bit_at( unsigned int bitmap, int ith )
{
	// Write Your Code Here
	char *bitString = malloc(sizeof(int)*8);
	unsigned int mask = 1 << (sizeof(int)*8 - 1);

	for (int i=0; i<sizeof(int)*8; i++){
		if ((bitmap & mask) == 0){
			bitString[i] = '0';
		}
		else {
			bitString[i] = '1';
		}
		mask >>= 1;
	}
	//printf("%s",bitString);
	if (bitString[31-ith] == '0'){
		return 0;
	}
	else {
		return 1;
	}
	// return bitmap[ith];
}

// Problem (4/4)
/******************************************************************************
 * TODO: Read from the file and store the entries in to a single linked list.
 * Return the list. Use the function llist_add( List * list, int value ) to
 * add entries to the list.
 *
 * The file format will be:
 * value\n
 * value\n
 * value\n
 * ...
 *
 * Parameters: filename -- the name of the file you will be reading from
 *
 * Return: a singled linked list which contains the values read from the file
 *
 * Return Type: pointer to a single linked list
 *****************************************************************************/
List * llist_read( char * filename )
{
	// Write Your Code He
	mylist = (List *) malloc(sizeof(List));
	llist_init(mylist);

	FILE *myFile;
	char line[1024];

	myFile=fopen(filename, "r");
	if (myFile != NULL){
		while (1){
			if (fgets(line, 1024, myFile) == NULL) break;
			int myValue=0;
			myValue=atoi(line);
			llist_add(mylist, myValue);
		}
		fclose(myFile);
	}

	return mylist;
}
