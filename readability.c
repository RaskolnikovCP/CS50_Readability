#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

float count_letters(string s1);

float count_words(string s2);

float count_sentences(string s3);

int calculate_grade(float letter, float word, float sentence);

int main(void)
{
    string s = get_string("Text:");

    //printf("%c\n", s[0]);

    float letter_no = count_letters(s);

    float word_no = count_words(s);

    float sentence_no = count_sentences(s);

    int index = calculate_grade(letter_no, word_no, sentence_no);

    //printf("letter_no: %f\n word_no: %f\n sentence_no: %f\n", letter_no, word_no, sentence_no);

    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

float count_letters(string s1)
{
    float count_letters = 0;

    int size = strlen(s1);

    for(int i = 0; i < size; i++)
    {
        if(isalpha(s1[i]) != 0)
        {
            count_letters++;
        }
    }

    return count_letters;

}

float count_words(string s2)
{
    float count_words = 0;

    int size = strlen(s2);

    for(int i = 0; i < size; i++)
    {
        if(i==0 && isalpha(s2[i]) != 0)
        {
            count_words++;
        }

        if(isspace(s2[i]) != 0 && isalpha(s2[i+1]) != 0)
        {
            count_words++;
        }

    }

    return count_words;
}

float count_sentences(string s3)
{
    float count_sentences = 0;

    int size = strlen(s3);

    for(int i = 0; i < size; i++)
    {
        if(isalpha(s3[i]) != 0){
            if(s3[i+1] == '.' || s3[i+1] == '!' || s3[i+1] == '?')
            {
                count_sentences++;
            }
        }
    }

    return count_sentences;
}

int calculate_grade(float letter, float word, float sentence)
{
    float L = ((100 * letter) / word);

    float S = ((100 * sentence) / word);

    float formula = ((0.0588 * L) - (0.296 * S) - (15.8));

    int index = round(formula);

    return index;
}
