#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    qsort(hashes, size, sizeof(char *), cmpStringAA);
    
    // TODO
    // Open the password file for reading.
    FILE *dictFile = fopen(argv[2], "r");

    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.
    int crackedCount = 0;
    char plaintext[PASS_LEN];
    while (fgets(plaintext, sizeof(plaintext), dictFile) != NULL)
    {
        // Remove the newline from the plaintext.
        plaintext[strcspn(plaintext, "\n")] = '\0';

        // Compute the MD5 hash of the plaintext password.
        char computedHash[HASH_LEN];
        // The md5 function returns a pointer to the hash string.
        strcpy(computedHash, md5(plaintext, strlen(plaintext)));

        // Use binary search (binarySearchAA from fileutil.c) to search for the computed hash.
        int index = binarySearchAA(hashes, size, computedHash);
        if (index != -1)
        {
            printf("Cracked: Hash [%s] matches password [%s]\n", hashes[index], plaintext);
            crackedCount++;
        }
    }

    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.

    fclose(dictFile);
    printf("Total hashes cracked: %d\n", crackedCount);
    freeAA(hashes, size);

    return 0;
}
