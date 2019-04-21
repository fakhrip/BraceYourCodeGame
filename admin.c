#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
	/* UNIX-style OS. ------------------------------------------- */
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <ctype.h>
#endif

#if defined(_WIN64) || defined(_WIN32)
	/* Microsoft Windows. ------------------------------ */
  #include <windows.h>
  #include <stdio.h>
  #include <string.h>
  #include <ctype.h>
#endif

int input, i, dataFound = 0, pos;
char editNim[101];

struct s_userAll {
  char nim[101];
  int key;
}userAll[48], userAllOne;

struct s_userKey {
  int key;
  char pass[101];
}userKey[48], userKeyOne;

struct s_userCode {
  char pass[101];
  char *code;
}userCode[48], userCodeOne;

struct s_status {
  char nim[101];
  int isPassed;
}status[48], statusOne;

FILE *userAllFile, *userKeyFile, *userCodeFile, *userStatusFile;

void clearScreen(){
  #if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
    /* Unix OS*/
    system("clear");
  #endif

  #if defined(_WIN64) || defined(_WIN32)
  	/* Microsoft Windows*/
    system("cls");
  #endif
}

char *encrypt(char *text, int s /*input this as 26-n to decrypt*/)
{
    char result[strlen(text)+1];

    // traverse text
    for (size_t i=0; i<strlen(text); i++)
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

char *xorencrypt(char * message, char * key) {
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

void main() {
  init();

  printf("\nMenu :\n");
  printf("1. Input data\n");
  printf("2. Show data\n");
  printf("3. Edit data\n");
  printf("PIlihan => ");
  scanf("%d", &input); getchar();

  init();
  switch (input) {
    case 1:
      userAllFile = fopen("userAllFile.dat", "ab");
      userKeyFile = fopen("userKeyFile.dat", "ab");
      userCodeFile = fopen("userCodeFile.dat", "ab");
      userStatusFile = fopen("userStatusFile.dat", "ab");
      printf("\n");
      for(size_t i=0; i<48; i++){
        printf("%d --------------\n",i+1);
        printf("| Masukkan NIM  : ");
        fgets(userAll[i].nim, 100, stdin);
        strcpy(status[i].nim, userAll[i].nim);
        printf("| Masukkan KEY  : ");
        scanf("%d", &userAll[i].key); getchar();
        userKey[i].key = userAll[i].key;
        printf("| Masukkan PASS : ");
        fgets(userCode[i].pass, 100, stdin);
        printf("| Lulus ? (1/0) : ");
        scanf("%d", &status[i].isPassed); getchar();
        strcpy(userKey[i].pass, encrypt(userCode[i].pass, userKey[i].key));
        userCode[i].code = xorencrypt(userAll[i].nim, "braceyourcode");
      }
      fwrite(status, sizeof(status), 1, userStatusFile);
      fwrite(userAll, sizeof(userAll), 1, userAllFile);
      fwrite(userKey, sizeof(userKey), 1, userKeyFile);
      fwrite(userCode, sizeof(userCode), 1, userCodeFile);

      fclose(userStatusFile);
      fclose(userAllFile);
      fclose(userKeyFile);
      fclose(userCodeFile);

      main();
      break;

    case 2:
      userAllFile = fopen("userAllFile.dat", "rb");
      userKeyFile = fopen("userKeyFile.dat", "rb");
      userCodeFile = fopen("userCodeFile.dat", "rb");
      userStatusFile = fopen("userStatusFile.dat", "rb");
      fread(status, sizeof(status), 1, userStatusFile);
      fread(userAll, sizeof(userAll), 1, userAllFile);
      fread(userKey, sizeof(userKey), 1, userKeyFile);
      fread(userCode, sizeof(userCode), 1, userCodeFile);
      printf("\n");
      for(size_t i=0; i<48; i++){
        printf("%d --------\n",i+1);
        printf("| Nim    : %s", userAll[i].nim);
        printf("| Key    : %d\n", userAll[i].key);
        printf("| Pass   : %s", userCode[i].pass);
        // printf("| Code   : %s\n", userCode[i].code);
        printf("| Status : ");
        if(status[i].isPassed == 1) printf("LULUS\n");
        else printf("TIDAK LULUS\n");
      }

      fclose(userStatusFile);
      fclose(userAllFile);
      fclose(userKeyFile);
      fclose(userCodeFile);

      getchar();
      main();
      break;

    case 3:
      dataFound = 0;
      printf("\nMasukkan nim yang ingin diedit : ");
      fgets(editNim, 100, stdin);
      userAllFile = fopen("userAllFile.dat", "rb+");
      userKeyFile = fopen("userKeyFile.dat", "rb+");
      userCodeFile = fopen("userCodeFile.dat", "rb+");
      userStatusFile = fopen("userStatusFile.dat", "rb+");
      fread(userAll, sizeof(userAll), 1, userAllFile);
      fread(userKey, sizeof(userKey), 1, userKeyFile);
      fread(userCode, sizeof(userCode), 1, userCodeFile);
      fread(status, sizeof(status), 1, userStatusFile);
      for(size_t i=0; i<48; i++){
        if(strcmp(userAll[i].nim,editNim)==0){
          dataFound = 1;
          pos = i;
          printf("-----------------\n");
          printf("| Masukkan NIM  : ");
          fgets(userAllOne.nim, 100, stdin);
          strcpy(statusOne.nim, userAllOne.nim);
          printf("| Masukkan KEY  : ");
          scanf("%d", &userAllOne.key); getchar();
          userKeyOne.key = userAllOne.key;
          printf("| Masukkan PASS : ");
          fgets(userCodeOne.pass, 100, stdin);

          ASKLULUS:
            printf("| Lulus ? (1/0) : ");
            scanf("%d", &statusOne.isPassed); getchar();
            if(statusOne.isPassed!=0 && statusOne.isPassed!=1)
              goto ASKLULUS;

          printf("-----------------\n");
          strcpy(userKeyOne.pass, encrypt(userCodeOne.pass, userKeyOne.key));
          userCodeOne.code = xorencrypt(userAllOne.nim, "braceyourcode");
        }
      }
      fseek(userAllFile, pos*sizeof(userAllOne), SEEK_SET);
      fseek(userKeyFile, pos*sizeof(userKeyOne), SEEK_SET);
      fseek(userCodeFile, pos*sizeof(userCodeOne), SEEK_SET);
      fseek(userStatusFile, pos*sizeof(statusOne), SEEK_SET);

      fwrite(&userAllOne, sizeof(userAllOne), 1, userAllFile);
      fwrite(&userKeyOne, sizeof(userKeyOne), 1, userKeyFile);
      fwrite(&userCodeOne, sizeof(userCodeOne), 1, userCodeFile);
      fwrite(&statusOne, sizeof(statusOne), 1, userStatusFile);

      if(dataFound == 0){
        printf("Data tidak ditemukan\n");
      } else {
        printf("Data berhasil diubah\n");
      }

      fclose(userStatusFile);
      fclose(userAllFile);
      fclose(userKeyFile);
      fclose(userCodeFile);

      getchar();
      main();
      break;

    default:
      main();
  }
}
