#include<stdio.h>
#include<ctype.h>
#include<conio.h>

#define WORD 4
#define VERBOSE 1 // 0
#define YES 'Y'
#define NO 'N'

void rightShift(char reg[], char bit) //Function toh shift right by 1 bit
{
 short i;
 for (i = WORD - 1; i > 0; i--)
  reg[i] = reg[i - 1];
 reg[0] = bit;
}
//End of rightshift()

void addition(char A[], char M[], char *c) //Function for binary addition
{
 short i;
 for (i = WORD - 1; i >= 0; i--)
 {
  if(A[i] == '0' && M[i] == '0')
  {
   A[i] = *c;
   *c = '0';
  }
  else
  {
   if ((A[i] == '1' && M[i] == '0') || (A[i] == '0' && M[i] == '1'))
   {
    if (*c == '0')
    {
     A[i] = '1';
    }
    else
    {
     A[i] = '0';
    }
   }
   else
   {
    if (A[i] == '1' && M[i] == '1')
    {
     A[i] = *c;
     *c = '1';
    }
   }
  }
 }
}
//End of addition

char* UnsignedIntegersMultiplication(char M[], char Q[]) //Function to regulate the algorithm
{
 char C = '0';
 char *A = ( char* ) malloc( sizeof(char) * (2 * WORD + 1) );
 char processedQ[WORD + 1];
 int i;
 strcpy(processedQ, Q);
 strcpy(A, "0000");
 if (VERBOSE)
 {
  puts(  "\nC         A         Q         M");
  printf("\n%c       %s      %s      %s		Initial values", C, A, Q, M);
  puts("\n--------------------------------------------------------------------");
 }
 for (i = WORD - 1; i >= 0; i --)
 {
  if (Q[i] == '1')
  {
   addition(A, M, &C);
   if (VERBOSE)
    printf("\n%c       %s      %s      %s		Add	Cycle %d", C, A, processedQ, M, WORD - i);
  }
  rightShift(processedQ, A[WORD - 1]);
  rightShift(A, C);
  C = '0';
  if (VERBOSE)
  {
   printf("\n%c       %s      %s      %s		Shift", C, A, processedQ, M);
   if (Q[i] == '0')
   {
    printf("	Cycle %d", WORD - i);
   }
  }
  if (VERBOSE)
  {
   puts("\n--------------------------------------------------------------------");
	//		getch();
  }
 }
 strcat(A, processedQ);
 return A;
}
//End of UnsignedIntegersMultiplication()

short verifyWord(char* word)
{
 short i;
 for (i = 0; i < WORD && (word[i] == '0' || word[i] == '1' ); i ++);
 return i == WORD;
}
//End of verifyWord()

void main()
{
 char M[WORD + 1];
 char Q[WORD + 1];
 char *result, c;
 do
 {
  clrscr();
  //Main Menu
  printf("\t\tUnsigned Integers Multiplication\n");
  printf("\t\t********************************");
  do
  {
   printf("\n\n\nEnter M (%d bits): ", WORD);
   gets(M);
   printf("Enter Q (%d bits): ", WORD);
   gets(Q);
   puts("\n");
  } while (strlen(M) > WORD || strlen(M) > WORD || strlen(M) < WORD || strlen(M) < WORD || !verifyWord(M) || !verifyWord(Q));
  result = UnsignedIntegersMultiplication(M, Q);
  printf("\n\n\n\nM * Q = %s * %s = %s\n\n\n\n", M, Q, result);
  printf("Continue? (Y/N): ");
  do
  {
   c = toupper(getch());
  } while ( c != YES && c != NO );
  putchar(c);
 } while ( c == YES );
 puts("\n");
}
//End of main()