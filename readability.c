#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int count_letters(string t);
float count_words(string t);
int count_sentences(string t);
float calculate_L(int w, int l);
float calculate_S(int s, int w);




int main(void)
{
    string text = get_string("enter you text: ");

    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text) ;

    // printf("%i \n %i \n %i \n", letters, words, sentences);

    float L = calculate_L(words, letters);
    float S = calculate_S(sentences, words);
    // printf("%f \n %f",L ,S);

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}



int count_letters(string t)
{
    
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        t[i] = tolower(t[i]);
        for (int j = 0; j < 26; j++)
        {
            if (t[i] == alphabet[j])
            {
                count += 1;
            }
        }

    }
    return count;
}

float count_words(string t)
{
    float count = 1.0;
    for (int i = 0; i < strlen(t); i++)
    {
        
        if (t[i] == ' ')
        {
            count += 1;
        }

    }
    //count -= sentences;
    return count;
}

int count_sentences(string t)
{
    int count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        
        if (t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            count += 1;
        }
        
    }
    return count;
}

float calculate_L(int w, int l)
{
    float L = (l * 100) / (float)w;
    //round((l * 100) / w);
    return L;
}

float calculate_S(int s, int w)
{
    float S = (s * 100) / (float)w;
    //round((s * 100) / w);
    return S;
}