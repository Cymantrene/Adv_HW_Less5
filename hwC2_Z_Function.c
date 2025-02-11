#include <stdio.h>
#include <string.h>

void z_function(char *S, int *Z, int n)
{
    int i, l, r;
    Z[0] = n;
    l = r = 0;
    for (i = 1; i < n; i++)
    {
        if (i >= r)
        {
            l = r = i;
            while (r < n && S[r-l] == S[r]) r++;
            Z[i] = r-l;
        }
        else
        {
            if (Z[i-l] < r-i)
            {
                Z[i] = Z[i-l];
            }
            else
            {
                l = i;
                while (r < n && S[r-l] == S[r]) r++;
                Z[i] = r-l;
            }
        }
    }
}

int main()
{
    char str1[105], str2[105];

    scanf("%s",str1);
    scanf("%s",str2);


    str1[strlen(str1)] = '\0';
    str2[strlen(str2)] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int MaxPrefSuf = 0;
    int MaxSufPref = 0;


    char concat1[210];
    sprintf(concat1, "%s#%s", str2, str1);
    int z1[210];
    z_function(concat1, z1, strlen(concat1));


    for (int i = len2 ; i < len2 + len1 ; i++)
    {
        if (z1[i] > MaxPrefSuf)
        {
           MaxPrefSuf = z1[i];
        }
    }


    char concat2[210];
    sprintf(concat2, "%s#%s", str1, str2);
    int z2[210];
    z_function(concat2, z2, strlen(concat2));



    for (int i = len1 ; i < len1 + len2 ; i++)
    {
        if (z2[i] > MaxSufPref)
        {
            MaxSufPref = z2[i];
        }
    }


    printf("%d %d\n", MaxSufPref, MaxPrefSuf);

    return 0;
}
