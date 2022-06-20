#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string key[])
{
    // if the arguments arent 2 (command and key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        
        return 1;
    }
    else
    {
        // making a frequency array to count how many time the letters are found and is intialized by 0
        int duplicates[26] = {0};
        for (int i = 0, n = strlen(key[1]); i < n; i++)
        {
            // each letter is represented from 0-26 by removing a in case of lowercase or A in case of uppercase
            // and in case of symbols now cont is added 
            
            if ((key[1][i] >= 'a' && key[1][i] <= 'z') || (key[1][i] >= 'A' && key[1][i] <= 'Z'))
            {
                if (islower(key[1][i]))
                {
                    duplicates[(key[1][i] - 'a')]++;
                }
                else
                {
                    duplicates[(key[1][i] - 'A')]++;
                }
            }
            
        }
        for (int i = 0 ; i < 26 ; i++)
        {
            // if the count of any letter is 0 (symbols) or more than 1 (duplicates) 
            // then terminate the project and return 1 
            
            if (duplicates[i] != 1)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
        
        
        //prompt user for entering the plain text
        string plaintext = get_string("plaintext: ");
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // in case lower case letters 
            // test if the letter at the index of the key is also lower
            // if it is upper then change to lower else remain lower and assign to the plain text its new value from the key
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                int index = plaintext[i] - 'a';
                if (key[1][index] >= 'A' && key[1][index] <= 'Z')
                {
                    plaintext[i] = tolower(key[1][index]);
                }
                else
                {
                    plaintext[i] = key[1][index];
                    
                }
            }
            
            // same as in case of lowercase but changed from lower to upper and do the same steps
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                int index = plaintext[i] - 'A';
                 
                if (key[1][index] >= 'a' && key[1][index] <= 'z')
                {
                    plaintext[i] = toupper(key[1][index]);
                     
                } 
                else
                {
                    plaintext[i] = key[1][index];
                }
            }
            
        }
        // printing the new, encrypted text
        printf("ciphertext: %s\n", plaintext);
    }
   
    return 0;
}