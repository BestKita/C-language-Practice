#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // 用于四舍五入的 round 函数

// 函数原型
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // 计算 index
    float L = (float)letter_count / word_count * 100.0;
    float S = (float)sentence_count / word_count * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // 四舍五入并将浮点数转换为整数
    int grade = (int)round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    size_t length = strlen(text);

    for (size_t i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 1; // 初始化为1，因为第一个单词之前通常没有空格
    size_t length = strlen(text);

    for (size_t i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    size_t length = strlen(text);

    for (size_t i = 0; i < length; i++)
    {
        char currentchar = text[i];

        // 检查当前字符是否是句子结束标志
        if (currentchar == '.' || currentchar == '?' || currentchar == '!')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

