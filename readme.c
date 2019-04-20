#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
	/* UNIX-style OS. ------------------------------------------- */
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
#endif

#if defined(_WIN64) || defined(_WIN32)
	/* Microsoft Windows. ------------------------------ */
  #include <windows.h>
  #include <stdio.h>
  #include <string.h>
#endif

int input;
char codeInput[101], extrovertCode[101];

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
  init();

  printf("\nChoose menu: \n");
  printf("1. getTheCode()\n");
  printf("2. getTheStatus()\n");
  printf("Your input : ");
  scanf("%d", &input); getchar();
  switch (input) {
    case 1:
      //GENERATE CAAS CODE
      MENU2:
        init();

        printf("\nChoose menu: \n");
        printf("1. Introvert Way (get the first code by doing some programming stuff)\n");
        printf("2. Extrovert Way (get the second code by socializing with the other)\n");
        printf("3. Back to main menu\n");
        printf("Your input : ");
        scanf("%d", &input); getchar();
        init();
        switch (input) {
          case 1:
            //INTROVERT WAY
            printf("\nEdit the \"main.c\" in the folder you've downloaded\n");
            printf("And start to code by following these steps of algorithm below :\n");
            printf("1. Open userAll.dat\n");
            printf("2. Find the NIM that you want to get the CODE\n");
            printf("3. Get the KEY from the struct data\n");
            printf("4. Use the KEY in the userKey.dat to get PASS\n");
            printf("   - Open userKey.dat\n");
            printf("   - Find the KEY matching with KEY from userAll.dat\n");
            printf("   - Get the PASS from the struct data\n");
            printf("5. Decrypt the PASS using caesar cipher encryption algorithm\n");
            printf("   and use the KEY as the algorithm parameter\n");
            printf("6. Use the decrypted PASS in the userStatus.dat to get the CODE\n");
            printf("   - Open userStatus.dat\n");
            printf("   - Find the PASS matching with the decrypted PASS from userKey.dat\n");
            printf("   - Get the CODE from the struct data\n");
            printf("Run the \"main.c\" and get the code from the nim you will input there\n");
            getchar();
            goto MENU2;

          case 2:
            //EXTROVERT WAY
            printf("\n1. Birthdate of the only woman in TUCIL Group K (only date without month and year)\n");
            printf("2. Tahap terakhir yang telah diikuti (gunakan angka)\n");
            printf("3. Jumlah persyaratan berkas tahap awal\n");
            printf("4. Prodi terbanyak yang mengikuti rekruitasi (TT/TE/TF)\n");
            printf("5. Jumlah caas TE yang lolos hingga saat ini\n");
            printf("6. Jumlah caas TF-04 yang lolos hingga saat ini\n");
            printf("7. Jumlah tanggal lahir caas TT-INT\n");
            printf("Input the unique pass by finding all those data above\n");
            printf("(EX: 22-1-3-TF-1-1-54)\n");
            printf("Your input : ");
            fgets(extrovertCode, 100, stdin);
            if(strcmp(extrovertCode, "")==0){
              printf("Here is the second code => \"test\"\n");
            } else {
              printf("Wrong code !!!");
            }
            getchar();
            goto MENU2;

          case 3:
            main();

          default:
            printf("Wrong input\n\n");
            goto MENU2;
        }
      break;

    case 2:
      //GET CAAS STATUS BASED ON THE CODE
      printf("|---------------------------------------------------|\n");
      printf("| feel free to hack this program to get the code :D |\n");
      printf("|---------------------------------------------------|\n\n");
      printf("Please Input The CODE\n");
      printf("(first code from introvert way + second code from extrovert way)\n");
      printf("Use \"+\" as the seperator (EX: d4sk0m+r3cru1tm3nt) => \n");
      fgets(codeInput, 100, stdin);

      //CODE MATCHING FOR EACH CAAS
      break;

    default:
      main();
  }
}
