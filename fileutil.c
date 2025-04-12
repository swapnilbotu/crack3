#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.

// I AM DOING THIS ONE(BELOW)
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	char **arr = NULL;
	char buffer[COLS];
	int capacity = 10;
	int count = 0;

	arr = (char**)malloc(capacity * sizeof(char*));

	// Read the file line by line.
	while (fgets(buffer, COLS, in) != NULL) {
		//	 Trim newline
        char *nl = strchr(buffer, '\n');
        if (nl) *nl = '\0';

		//   Expand array if necessary (realloc).
        if (count >= capacity) {
            capacity *= 2;
            char **temp = (char**)realloc(arr, capacity * sizeof(char*));
            arr = temp;
        }

		//	Allocate memory for the string (str)
		char *str = malloc(strlen(buffer) + 1);

		//	Copy line into the string (use strcpy)
		strcpy(str, buffer);

		//   Attach the string to the large array (assignment =).
		arr[count++] = str;
	}

    // Close the file.
	fclose(in);
	
	// The size should be the number of entries in the array.
	*size = count;
	
	// Return pointer to the array of strings.
	return arr;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; i++){
		if (strstr(lines[i], target))
			return lines[i];
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size){
	for (int i = 0; i < size; i++){
		free(arr[i]);
	}

	free(arr);
}

void free2D(char (*arr)[COLS]){
	// empty
}

// performs a linear search for an exact match using strcmp
// Returns the index if found, or -1 otherwise
int linearSearchExactAA(char **arr, int size, const char *target)
{
    for (int i = 0; i < size; i++){
        if (strcmp(arr[i], target) == 0)
            return i;
    }
    return -1;
}

// Comperison function for qsort.
int cmpStringAA(const void *a, const void *b)
{
	const char *str1 = *(const char **) a;
	const char *str2 = *(const char **) b;
	return strcmp(str1, str2);
}

// Performs a binary search for an exact match in a sorted array
// Returns the index if found, or -1 otherwise
int binarySearchAA(char **arr, int size, const char *target)
{
	int low = 0, high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int cmp = strcmp(arr[mid], target);
		if (cmp == 0)
			return mid;
		else if (cmp < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}