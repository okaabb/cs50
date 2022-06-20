// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table

const unsigned int N = 2600;
int numberOfwords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *temp = table[index];
    while (temp != NULL)
    {
        if (strcasecmp(temp -> word, word) == 0)
        {
            return true;
        }
       else{ temp = temp -> next;}
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    for (int i = 0; i < sizeof(word); i++)
    {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' || word[i] <= 'Z'))
        {
            char letter = word[i];
            if (letter >= 'a' && letter <= 'z')
            {
                return (int)(letter - 'a');

            }
            else
            {
                return (int)(letter - 'A');
            }
        }
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");

    if (dic == NULL)
    {
        return false;
    }

    node *head = NULL;
    char wordy[46];
    while (fscanf(dic, "%s", wordy) != EOF)
    {
        numberOfwords++;

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
                fclose(dic);
                return false;
        }

        strcpy(n -> word, wordy);

        int index = hash(wordy);
        
        if (table[index] == NULL)
        {
            table[index] = n;
            head = table[index];
            head -> next =NULL;
        }
        else
        {
            n -> next = head -> next;
            head->next = n;
        }
        //free(n);

    }
    
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numberOfwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
   
        for (node *temp = table[i]; temp != NULL;)
        {
            node *temp2 = temp;
            temp = temp -> next;
            free(temp2);
        }

        //free(temp);
    }
    return true;
}
