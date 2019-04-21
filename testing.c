#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i;
char *encrypt(char *text, int s /*input this as 26-n to decrypt*/)
{
    char result[strlen(text)+1];

    // traverse text
    for (i=0; i<strlen(text); i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result[i] = (text[i]+s-65)%26 +65;
        // Encrypt Lowercase letters
        else
            result[i] = (text[i]+s-97)%26 +97;
    }

    // Return the resulting string
    char *forreturn;
    forreturn = malloc (sizeof (char) * strlen(text)+1);
    strcpy(forreturn, result);
    return forreturn;
}

void main(){
  printf("%s", encrypt("abc", 1));
}
