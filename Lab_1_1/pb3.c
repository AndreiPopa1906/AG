#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int k=1;
char s[255], mat[255][255];
char *p;
char cuv[255];

int main()
{
    scanf("%[^\n]s",s);

    p = strtok(s, " ");

    while(p != NULL)
    {
       strcpy(mat[k],p);
       k++;
       p = strtok(NULL, " ");
   }
    for(int i=1 ; i<k ; i++)
    {
        for(int j=i+1 ; j<=k ; j++)
        {
            if(strlen(mat[i]) > strlen(mat[j]))
            {
                strcpy(cuv,mat[i]);
                strcpy(mat[i],mat[j]);
                strcpy(mat[j],cuv);
            }
            else if(strlen(mat[i]) == strlen(mat[j]) && strcmp(mat[i],mat[j])>0)
            {
                   strcpy(cuv,mat[i]);
                   strcpy(mat[i],mat[j]);
                   strcpy(mat[j],cuv);
            }

            }
        }

    for(int i = 0 ; i < k ; i++)
    {
     printf("%s \n",mat[i]);
    }
    return 0;
}
