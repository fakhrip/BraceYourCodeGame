///////////////////////////////////////////////////////////////////////////
/*        DO NOT CHANGE THESE LINES BELOW IF YOU DONT UNDERSTAND IT      */
/*************************************************************************/
/**/#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
/**/	/* UNIX-style OS. ------------------------------------------- */
/**/  #include <unistd.h>
/**/  #include <stdlib.h>
/**/  #include <stdio.h>
/**/  #include <string.h>
/**/  #include <ctype.h>
/**/#endif
/**/
/**/#if defined(_WIN64) || defined(_WIN32)
/**/	/* Microsoft Windows. ------------------------------ */
/**/  #include <windows.h>
/**/  #include <stdio.h>
/**/  #include <string.h>
/**/  #include <ctype.h>
/**/#endif
/**/
/**/int input, i;
/**/
/**/void clearScreen(){
/**/  #if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
/**/    /* Unix OS*/
/**/    system("clear");
/**/  #endif
/**/
/**/  #if defined(_WIN64) || defined(_WIN32)
/**/  	/* Microsoft Windows*/
/**/    system("cls");
/**/  #endif
/**/}
/**/
/**/struct s_userAll {
/**/  char nim[101];
/**/  int key;
/**/}userAll[48];
/**/
/**/struct s_userKey {
/**/  int key;
/**/  char pass[101];
/**/}userKey[48];
/**/
/**/struct s_userCode {
/**/  char pass[101];
/**/  char *code;
/**/}userCode[48];
/**/
/**/FILE *userAllFile, *userKeyFile, *userCodeFile;
/**/
/**/char *encrypt(char *text, int s /*input this as 26-n to decrypt*/)
/**/{
/**/    char result[strlen(text)+1];
/**/
/**/    // traverse text
/**/    for (size_t i=0; i<strlen(text); i++)
/**/    {
/**/        // apply transformation to each character
/**/        // Encrypt Uppercase letters
/**/        if (isupper(text[i]))
/**/            result[i] = (text[i]+s-65)%26 +65;
/**/        // Encrypt Lowercase letters
/**/        else
/**/            result[i] = (text[i]+s-97)%26 +97;
/**/    }
/**/
/**/    // Return the resulting string
/**/    char *forreturn;
/**/    forreturn = malloc (sizeof (char) * strlen(text)+1);
/**/    strcpy(forreturn, result);
/**/    return forreturn;
/**/}
void init(){
  clearScreen();
  printf("                    d8888b.  .d8b.  .d8888. db   dD  .d88b.  .88b  d88.                         \n\
                    88  `8D d8' `8b 88'  YP 88 ,8P' .8P  Y8. 88'YbdP`88                         \n\
                    88   88 88ooo88 `8bo.   88,8P   88    88 88  88  88                         \n\
                    88   88 88~~~88   `Y8b. 88`8b   88    88 88  88  88                         \n\
                    88  .8D 88   88 db   8D 88 `88. `8b  d8' 88  88  88                         \n\
                    Y8888D' YP   YP `8888Y' YP   YD  `Y88P'  YP  YP  YP                         \n\
                                                                                                \n\
d8888b. d88888b  .o88b. d8888b. db    db d888888b d888888b .88b  d88. d88888b d8b   db d888888b \n\
88  `8D 88'     d8P  Y8 88  `8D 88    88   `88'   `~~88~~' 88'YbdP`88 88'     888o  88 `~~88~~' \n\
88oobY' 88ooooo 8P      88oobY' 88    88    88       88    88  88  88 88ooooo 88V8o 88    88    \n\
88`8b   88~~~~~ 8b      88`8b   88    88    88       88    88  88  88 88~~~~~ 88 V8o88    88    \n\
88 `88. 88.     Y8b  d8 88 `88. 88b  d88   .88.      88    88  88  88 88.     88  V888    88    \n\
88   YD Y88888P  `Y88P' 88   YD ~Y8888P' Y888888P    YP    YP  YP  YP Y88888P VP   V8P    YP    \n");
}
/*************************************************************************/
/*       DO NOT CHANGE THOSE LINES ABOVE IF YOU DONT UNDERSTAND IT       */
///////////////////////////////////////////////////////////////////////////

/*************************************************************************/

///////////////////////////////////////////////////////////////////////////
/////////////  YOU CAN FREELY CHANGE THESE LINES BELOW  ///////////////////
///////////// KALIAN BEBAS MENGUBAH PROGRAM DIBAWAH INI ///////////////////
void main() {
  init();
}
