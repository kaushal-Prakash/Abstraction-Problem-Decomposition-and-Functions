/* 
 * File:   main.c
 * Author: Gunanidhi M S
 */

 #define _CRT_SECURE_NO_WARNINGS

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 
 #define MAX_LENGTH 100
 
 /* 
  * Junior Codebreaker Programming Assignment
  */
 int main(int argc, char** argv)
 {
	 // IMPORTANT: Only add code in the section
	 // indicated below. The code I've provided
	 // makes your solution work with the 
	 // automated grader on Coursera
	 char input[MAX_LENGTH];
	 int counts[26] = {0}; // Array to store letter counts
 
	 fgets(input, MAX_LENGTH, stdin);
	 while (input[0] != 'q')
	 {
		 // Add your code between this comment
		 // and the comment below. You can of
		 // course add more space between the
		 // comments as needed
		 
		 // Count occurrences of alphabetic characters
		 for (int i = 0; i < strlen(input); i++)
		 {
			 if (isalpha(input[i])) // Check if character is alphabetic
			 {
				 char uppercase = toupper(input[i]); // Convert to uppercase
				 counts[uppercase - 'A']++; // Increment corresponding count
			 }
		 }
 
		 // Print results in required format
		 for (int i = 0; i < 26; i++)
		 {
			 if (counts[i] > 0)
			 {
				 printf("%c%d ", 'A' + i, counts[i]);
			 }
		 }
 
		 printf("\n");  // Newline after output
		 
		 // Reset counts for next iteration
		 memset(counts, 0, sizeof(counts));
 
		 // Don't add or modify any code below
		 // this comment
		 fgets(input, MAX_LENGTH, stdin);
	 }
 
	 return 0;
 }