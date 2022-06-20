#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_words(string text);
int count_sentences(string text);
int count_letters(string text);

int main(void)
{
    // prompt user for text
    string text = get_string("Text: ");
    
    // count words, letters and sentences
    int words = count_words(text); 
    int letters = count_letters(text);   
    int sentences = count_sentences(text); 

    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    
    // calculating using the formula given
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    //grading: more than 16 -> 16+ 
    //         less than 1 -> before grade 1
    //         between 1 and 16 -> approximate the number (if it's .5 or more adds one and takes the int form of the float)
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        if ((index - (int)index) * 10 >= 5)
        {
            index ++;
        }
        printf("Grade %i\n", (int)index);
    }
}

int count_words(string text)
{
    int counter = 0;
    
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        //adds one word when sees a space
        if (text[i] == ' ')
        {
            counter++;
        }
    }
    
    return counter + 1;
}

int count_sentences(string text)
{
    int counter = 0;
    
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        // adds one sentences when sees a '.' '!' '?'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    
    return counter;
}

int count_letters(string text)
{
    int counter = 0;
    
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        // adds one letter if they are between a and z OR A and Z (all letters lower and upper case)
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            counter++;
        }
    }
    
    return counter;
}
