#include <stdio.h>
#include <string.h>

int main(void) {

  printf("-----------HANGMAN---------------\n\n\n");

  // VARIAVEIS:

  char word[100], guessL, hint[100];
  int numOf;
  int acerto = 0, i = 0;
  int erros = 5;

  // GAME MENU:

  printf("GAME MASTER, CHOOSE THE WORD\n");
  scanf("%s", word);

  printf("GAME MASTER, CHOOSE THE HINT\n");
  scanf("%s", hint);

  system("clear");

  numOf = strlen(word);
  char guess[numOf];

  printf("-----------HANGMAN GAME----------------\n\n\n");

  printf("❤ ❤ ❤ ❤ ❤\n\n");
  // NUM OF LETTERS:
  for (int j = 0; j < numOf; j++) {
    guess[j] = '_';
  }
  
  // HINT DISPLAY:
  for (char *p = hint; *p; p++) {
    *p = toupper(*p);
  }

  printf("THE HINT IS: %s\n\n", hint);
  // GAME BODDY:
  while (i < 5) {
    printf("Choose a letter:\n");
    scanf(" %c", &guessL);

    for (int k = 0; k <= numOf; k++) {
      if (guessL == word[k]) {
        guess[k] = word[k];
      }
    }
    for (int m = 0; m < numOf; m++) {
      if (guessL == word[m]) {
        acerto++;
      }
    }

    if (acerto == 0) {
      i++;
      printf("You lost one life!\n");
      for(int i = 0; i < erros-1; i++)
        printf(" ❤ ");
      erros--;
    }
    printf("\n");
    acerto = 0;

    for (int l = 0; l < numOf; l++) {
      printf("%c ", guess[l]);
    }
    printf("\n");

    char *result = strstr(guess, word);

    if (result) {
      break;
    }
  }
  // RESULT PROMPT:
  if (erros > 0) {
    printf("YOU WON!\n");
    printf("THE WORD WAS: %s", word);
  } else {
    printf("YOU LOST!\n");
    printf("THE WORD WAS: %s", word);
  }
}
