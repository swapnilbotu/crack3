// For the 2D array, this sets the width.
#define COLS 100

// Load the dictionary of words (or hash values) from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid entries in the array.
char ** loadFileAA(char *filename, int *size);

// Alternative: Load as a 2D array. (Not used in this assignment.)
char (*loadFile2D(char *filename, int *size))[COLS];

// Search the dictionary/array for the target string using substring matching.
// Returns the found string or NULL if not found.
char * substringSearchAA(char *target, char ** arr, int size);
char * substringSearch2D(char *target, char (*arr)[COLS], int size);

// Free the memory used by the array.
void freeAA(char ** arr, int size);
void free2D(char (*arr)[COLS]);

// New Functions

// Performs a linear search for an exact match using strcmp.
// Returns the index if found, or -1 otherwise.
int linearSearchExactAA(char **arr, int size, const char *target);

// Performs a binary search for an exact match in a sorted array.
// Returns the index if found, or -1 otherwise.
int binarySearchAA(char **arr, int size, const char *target);

int cmpStringAA(const void *a, const void *b);
