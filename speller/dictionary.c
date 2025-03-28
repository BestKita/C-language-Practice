// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int countWord = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashNum = hash(word);
    node *cursor = table[hashNum];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (word == NULL)
    {
        return 0;
    }
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *DictionaryFile = fopen(dictionary, "r");

    if (DictionaryFile == NULL)
    {
        return false;
    }
    char str[LENGTH + 1];
    while (fscanf(DictionaryFile, "%s", str) != EOF)
    {
        node *temp = malloc(sizeof(node));

        if (temp == NULL)
        {
            return false;
        }
        strcpy(temp -> word, str);

        int hashNum = hash(str);

        if (table[hashNum] == NULL)
        {
            temp->next = NULL;
            table[hashNum] = temp;
        }
        else
        {
            temp->next = table[hashNum];
            table[hashNum] = temp;
        }
        table[hashNum] = temp;

        countWord += 1;

    }
    fclose(DictionaryFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return countWord;
}

void freenode(node *n)
{
    if (n -> next != NULL)
    {
        freenode(n -> next);
    }
    free(n);
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}

