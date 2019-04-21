// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int i;
// char *encrypt(char *text, int s /*input this as 26-n to decrypt*/)
// {
//     char result[strlen(text)+1];
//
//     // traverse text
//     for (i=0; i<strlen(text); i++)
//     {
//         // apply transformation to each character
//         // Encrypt Uppercase letters
//         if (isupper(text[i]))
//             result[i] = (text[i]+s-65)%26 +65;
//         // Encrypt Lowercase letters
//         else
//             result[i] = (text[i]+s-97)%26 +97;
//     }
//
//     // Return the resulting string
//     char *forreturn;
//     forreturn = malloc (sizeof (char) * strlen(text)+1);
//     strcpy(forreturn, result);
//     return forreturn;
// }
//
// void main(){
//   printf("%s", encrypt("abc", 1));
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * xorencrypt(char * message, char * key) {
    size_t messagelen = strlen(message);
    size_t keylen = strlen(key);

    char * encrypted = malloc(messagelen+1);

    int i;
    for(i = 0; i < messagelen; i++) {
        encrypted[i] = message[i] ^ key[i % keylen];
    }
    encrypted[messagelen] = '\0';

    return encrypted;
}

int main(int argc, char * argv[]) {
    char * message = "1101184340";
    char * key = "braceyourcode";

    char * encrypted = xorencrypt(message, key);
    printf("%s\n", xorencrypt(message, key));
    printf("%d\n", strcmp("SCQRTA[EFS", xorencrypt(message, key)));
    free(encrypted);

    // for (size_t i = 0; i < 50; i++) {
    //   /* code */
    //   printf("%d\n",i+1 );
    // }

    return 0;
}
