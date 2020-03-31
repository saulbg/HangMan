#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Hang Man
You will select the word randomly from a list of words given above:
casa, arbol, geometria, celular, vaso, cuarentena, coronavirus

You will print the word with an * for each letter. If you select a correct letter, you will replace the * with the respective letter.
You have 5 lives.

Penalties: - You waste a life repeating a previously chosen letter
           - You loose a life if you choose a letter that is not in the word

Upload the link of github.
-You must print the list of words for the user
-You must provide in the execution only the word with argc and argv
example: ./a.out word
also you can use scanf for the user */

char *keyword = "arbol";

int main(void)
{
	int wposition=0, wsize, lives = 5;
	char word[20];
	int j = 0, correct, i = 0;
	char letter;
	printf("Welcome to the HangMan Game \nThis are the words that might be here: casas, vasos, celular, arbol, libro \n");
	printf("You have 5 lives, if you repeat a letter that you put before you lose a life.\nAlso if you put a letter that is not in the word you lose another life\n");
	printf("Remember to use just letters lowercase.\n");
	printf("\nThis is the word. You have %d lives \n", lives);
	wsize = strlen(&keyword[wposition]);
	for (j = 0; j < wsize; j++)
	{
		word[j] = '*';
	}
	word[wsize] = 0;
	printf("%s\n", word);
	while ((lives > 0) && (i < wsize))
	{
		correct = 0;
		printf("Enter a letter: ");
		do
		{
	    	scanf("%c", &letter);
	    	if ((letter > ' ') && ((letter < 'a') || (letter > 'z')))
			{
            	printf("Invalid character, please just write letters.\nEnter a letter: ");
         	}
      		} while ((letter < 'a') || (letter > 'z'));
      		for (j = 0; j < wsize; j++)
			{
         		if (letter == word[j])
				 {
            		printf("You have already used this letter.\n");
            		lives--;
            		printf("%i lives left.\n", lives);
            		break;
         		}
      		}
      			if (j == wsize)
				{
         			for (j = 0; j < wsize; j++)
					{
            			if (letter == keyword[j])
						{
               				word[j] = letter;
               				i++;
               				correct = 1;
            			}
         			}
         				if (correct == 0)
						{
            				lives--;
            				if (lives > 0)
					{
               				printf("Wrong, this letter is not in the word. %i lives left.\n", lives);
            				} else {
               						printf("You lose.\n");
               						return 0;
            					}
         					} else {
            						if (i < wsize)
							{
               							printf("Correct.\n");
            						} else {
               								printf("Congratulations! You win the game\n");
            							}
         						}
         						printf("You guess the word: %s\n", word);
      			}
   }
}

