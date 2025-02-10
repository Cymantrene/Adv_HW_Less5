#include <stdio.h>
#include <string.h>
#define FLAGMASSIV 1

char BuffData[101];
int MassivWithFlags[1000];

int main(void)
{
    scanf("%s", BuffData);
    int len = strlen(BuffData);
    int AllCombination = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            for (int datatmp = j + 1; datatmp < len; ++datatmp)
            {
                if (BuffData[i] == '0')
                    continue;
                int fullMassiv = (BuffData[i] - '0') * 100 + (BuffData[j] - '0') * 10 +(BuffData[datatmp] - '0');
                if (MassivWithFlags[fullMassiv] != FLAGMASSIV)
                {
                    MassivWithFlags[fullMassiv] = FLAGMASSIV;
                    AllCombination++;
                }
            }
        }
    }
    printf("%d", AllCombination);
    return 0;
}


