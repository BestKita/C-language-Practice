#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // 检查命令行参数
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // 检查密钥是否为纯数字
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Key must be a non-negative integer.\n");
            return 1;
        }
    }

    // 将命令行参数转换为整数作为加密密钥
    int k = atoi(key);

    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext; // 初始化密文字符串与明文相同

    // 对每个字符进行加密
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];

        // 检查字母是否为大写字母
        if (isupper(letter))
        {
            // 将字母转换为在A-Z范围内的索引（A=0，B=1，...，Z=25）
            int index = letter - 'A';

            // 使用加密密钥进行移位，确保在0-25的范围内
            ciphertext[i] = (index + k) % 26 + 'A';
        }
        // 如果是小写字母
        else if (islower(letter))
        {
            // 将字母转换为在a-z范围内的索引（a=0，b=1，...，z=25）
            int index = letter - 'a';

            // 使用加密密钥进行移位，确保在0-25的范围内
            ciphertext[i] = (index + k) % 26 + 'a';
        }
        // 如果不是字母，则保持不变
    }

    // 输出密文字符串
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

