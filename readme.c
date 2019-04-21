#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
	/* UNIX-style OS. ------------------------------------------- */
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>
#endif

#if defined(_WIN64) || defined(_WIN32)
	/* Microsoft Windows. ------------------------------ */
  #include <windows.h>
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>
#endif

int input, i, j, isLULUS, isCODEPASS, isAVAILABLE;
bool isEnglish = false, languageChosen = false;
char codeInput[101], extrovertCode[101];
char *token;

struct s_status {
  char nim[101];
  int isPassed;
}status[48];

FILE *userStatusFile;

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

const char *getLang(char *stringEN, char *stringID){
  if(isEnglish){
    return stringEN;
  } else {
    return stringID;
  }
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

void main(){
  if(!languageChosen){
    init();

    printf("\n%s :\n",getLang("Choose language", "Pilih bahasa"));
    printf("1. Indonesia\n");
    printf("2. English\n");
    printf("%s : ",getLang("Your input", "Masukkan"));
    scanf("%d", &input); getchar();
    switch (input) {
      case 1: isEnglish = false; languageChosen = true; break;
      case 2: isEnglish = true; languageChosen = true; break;
      default: printf("%s\n",getLang("Wrong input", "Inputan salah")); getchar(); main();
    }
  }

  init();
  printf("\n%s :\n",getLang("Choose menu", "Pilihan menu"));
  printf("1. %s\n",getLang("getTheCode()", "dapatkanKodenya()"));
  printf("2. %s\n",getLang("getTheStatus()", "dapatkanStatusnya()"));
  printf("%s : ",getLang("Your input", "Masukkan"));
  scanf("%d", &input); getchar();
  switch (input) {
    case 1:
      //GENERATE CAAS CODE
      MENU2:
        init();

        printf("\n%s :\n",getLang("Choose menu", "Pilihan menu"));
        printf("1. %s\n",getLang("Introvert Way (get the first code by doing some programming stuff)", "Cara Introvert (dapatkan kode pertamanya dengan melakukan hal hal programming)"));
        printf("2. %s\n",getLang("Extrovert Way (get the second code by socializing with the other)", "Cara Extrovert (dapatkan kode keduanya dengan bersosialisasi dengan yang lainnya)"));
        printf("3. %s\n",getLang("Back to main menu", "Kembali ke menu utama"));
        printf("%s : ",getLang("Your input", "Masukkan"));
        scanf("%d", &input); getchar();
        init();
        switch (input) {
          case 1:
            //INTROVERT WAY
            printf("\n%s\n",getLang("Edit the \"main.c\" in the folder you've downloaded", "Edit \"main.c\" yang ada didalam folder yang telah kamu download"));
            printf("%s :\n",getLang("And start to code by following these steps of algorithm below", "Dan mulailah membuat programnya dengan mengikuti langkah-langkah algoritma berikut"));
            printf("1. %s\n",getLang("Open userAllFile.dat (fopen)", "Buka userAllFile.dat (fopen)"));
            printf("2. %s\n",getLang("Find the NIM that you want to get the CODE (fread)", "Carilah NIM yang ingin dicari untuk mendapatkan CODE nya (fread)"));
            printf("3. %s\n",getLang("Get the KEY from the struct data", "Dapatkan KEY dari data structnya"));
            printf("4. %s\n",getLang("Use the KEY in the userKey.dat to get PASS", "Gunakan KEY dari userKeyFile.dat untuk mendapatkan PASS nya"));
            printf("   - %s\n",getLang("Open userKeyFile.dat", "Buka userKeyFile.dat"));
            printf("   - %s\n",getLang("Find the KEY matching with KEY from userAllFile.dat", "Carilah KEY yang sama dengan KEY dari userAllFile.dat"));
            printf("   - %s\n",getLang("Get the PASS from the struct data", "Dapatkan PASS dari data structnya"));
            printf("5. %s\n",getLang("Decrypt the PASS using caesar cipher encryption algorithm (encrypt function in \"main.c\")", "Dekripsi PASS nya dengan menggunakan algoritma enkripsi caesar cipher (fungsi encrypt pada \"main.c\")"));
            printf("   %s\n",getLang("and use the KEY as the algorithm parameter", "dan gunakan KEY nya sebagai parameter dari algoritma enkripsi tersebut"));
            printf("6. %s\n",getLang("Use the decrypted PASS in the userCodeFile.dat to get the CODE", "Gunakan PASS yang sudah didekripsi kedalam userCodeFile.dat untuk mendapatkan CODE nya"));
            printf("   - %s\n",getLang("Open userCodeFile.dat", "Buka userCodeFile.dat"));
            printf("   - %s\n",getLang("Find the PASS matching with the decrypted PASS from userKeyFile.dat", "Carilah PASS yang sama dengan PASS yang sudah didekripsi dari userKeyFile.dat"));
            printf("   - %s\n",getLang("Get the CODE from the struct data", "Dapatkan CODE dari data structnya"));
            printf("%s\n",getLang("Run the \"main.c\" and get the CODE from the nim you will input there", "Jalankan \"main.c\" nya dan dapatkan CODE sesuai dengan nim yang kamu input disana"));
            printf("\n(*)%s\n",getLang("Important point is that you can solve this program whatever you want", "Poin pentingnya adalah bahwa kamu bisa menyelesaikan program ini sesuai keinginanmu"));
            printf("   %s\n",getLang("This is just one of way to solve the program", "Ini hanyalah salah satu cara menyelesaikan programnya"));
            printf("(*)%s\n",getLang("The caesar cipher encryption algorithm is already premade in the \"main.c\" program", "Algoritma enkripsi caesar cipher nya sudah tersedia didalam program \"main.c\" nya"));
            getchar();
            goto MENU2;

          case 2:
            //EXTROVERT WAY
            printf("\n1. %s\n",getLang("Birthdate of candidate that won the first place of eating crackers contest HUT-RI in 2018 (only date without month and year)", "Tanggal lahir caas yang juara 1 lomba makan kerupuk HUT-RI tahun 2018 (hanya tanggalnya saja)"));
            printf("2. %s\n",getLang("Last stage that has been done (use number)", "Tahap terakhir yang telah diikuti (gunakan angka)"));
            printf("3. %s\n",getLang("Number of first stage's file requirements", "Jumlah persyaratan berkas tahap awal"));
            printf("4. %s\n",getLang("Study programs which participate the most in this recruitation (TT/TE/TF)", "Prodi terbanyak yang mengikuti rekruitasi (TT/TE/TF)"));
            printf("5. %s\n",getLang("Number of Electrical Engineer candidates that has passed until now", "Jumlah caas TE yang lolos hingga saat ini"));
            printf("6. %s\n",getLang("Number of TF-04 candidates that has passed until now", "Jumlah caas TF-04 yang lolos hingga saat ini"));
            printf("7. %s\n",getLang("Sum of 2 last digit of TT-INT candidate's nim", "Jumlah 2 digit terakhir nim caas TT-INT"));
            printf("%s\n",getLang("Input the unique password by finding all those data above", "Masukkan kata sandi unik dengan mencari data-data diatas"));
            printf("%s\n",getLang("(Example : 22-1-3-TF-1-1-54)", "(Contoh : 22-1-3-TF-1-1-54)"));
            printf("%s : ",getLang("Your input", "Masukkan"));
            fgets(extrovertCode, 100, stdin);
            if(strcmp(extrovertCode, "26-5-7-TT-10-4-47")==10){
              printf("%s => \"beFuture4ss1st4nt\"\n",getLang("Here is the second code", "Ini adalah kode keduanya"));
            } else {
              printf("%s !!!",getLang("Wrong password", "Kata sandi salah"));
            }
            getchar();
            goto MENU2;

          case 3:
            main();

          default:
            goto MENU2;
        }
      break;

    case 2:
      //GET CAAS STATUS BASED ON THE CODE
      printf("%s\n",getLang("|---------------------------------------------------|", "|-----------------------------------------------------------------------|"));
      printf("| %s :D |\n",getLang("feel free to hack this program to get the code", "sangat diperbolehkan meretas program ini untuk mendapatkan kodenya"));
      printf("%s\n",getLang("|---------------------------------------------------|", "|-----------------------------------------------------------------------|"));
      printf("%s\n",getLang("Please Input The CODE", "Mohon masukkan KODE nya"));
      printf("%s\n",getLang("(first code from introvert way + second code from extrovert way)", "(kode pertama dari cara introvert + kode kedua dari cara extrovert)"));
      printf("%s (EX: d4sk0m+r3cru1tm3nt) => ",getLang("Use \"+\" as the seperator", "Gunakan \"+\" sebagai pemisahnya"));
      fgets(codeInput, 100, stdin);

      //CODE MATCHING FOR EACH CAAS
      userStatusFile = fopen("userStatusFile.dat", "rb");
      fread(status, sizeof(status), 1, userStatusFile);

      i=0;
      token = strtok (codeInput,"+");
      while (token != NULL){
        if(i==0){
          isAVAILABLE = 0;
          for(size_t j=0; j<48; j++){
            if(strcmp(status[j].nim, xorencrypt(token, "braceyourcode"))==0){
              isLULUS = status[j].isPassed;
              isAVAILABLE = 1;
            }
          }
        } else if(i==1) {
          if(strcmp(token, "beFuture4ss1st4nt")==10) isCODEPASS = 1;
          else isCODEPASS = 0;
        }
        i++;
        token = strtok (NULL, "+");
      }

      if(isCODEPASS == 1){
        //CODERIGHT
        if (isAVAILABLE == 1) {
          if(isLULUS == 1){
            //LULUS
            printf("%s",getLang("CONGRATULATIONS YOU PASS TO THE NEXT STAGE", "SELAMAT KAMU LULUS KE TAHAP SELANJUTNYA"));
          } else {
            //TIDAK LULUS
            printf("%s",getLang("SORRY YOU FAILED TO PASS TO THE NEXT STAGE", "MAAF KAMU TIDAK LULUS KE TAHAP SELANJUTNYA"));
          }
        } else {
          printf("%s",getLang("DATA NOT FOUND (IT MAYBE WRONG)", "DATA TIDAK DITEMUKAN (KEMUNGKINAN INPUT SALAH)"));
        }
      } else {
        //WRONGCODE
        printf("%s",getLang("CODE is wrong", "KODE nya salah"));
      }

      getchar();
      main();
      break;

    default:
      main();
  }
}
