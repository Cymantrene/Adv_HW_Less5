#include <stdio.h>
#include <string.h>

int counter(char* s1, char* s2)
{
    unsigned int j, i, k=0;
    int count = 0, max = 0;
    int len = strlen(s2);
    for (i = 0; i < len; i++)
    {
        if(s2[i] == s1[0])
        {
            for (j = i; j < len; j++)
            {
                if (s1[k++] != s2[j])
                {
                    count = 0;
                    k = 0;
                    break;
                }
                count++;
            }
        }
        else
        {
            continue;
        }
        if (count > max)
        {
            max = count;
        }
    }

    return max;
}
int main(void)
{
    char s1[1000]={0};
    char s2[1000]={0};
    scanf("%s", s1);
    scanf("%s", s2);
    printf("%d ", counter(s1, s2));
    printf("%d", counter(s2, s1));
    return 0;
}
