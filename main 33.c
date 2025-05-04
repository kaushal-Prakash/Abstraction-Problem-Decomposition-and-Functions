/*
 * File:   main.c
 * Author: Mohith B p
 */

 #define _CRT_SECURE_NO_WARNINGS

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define MAX_LENGTH 100
 
 #define MIN 0
 #define MAX 1
 
 typedef struct LinkedList LinkedList;
 struct LinkedList
 {
	 int data;
	 LinkedList *next;
 };
 LinkedList *head;
 LinkedList *tail;
 
 // prototypes for student-implemented functions
 int getValidInteger(int lowerBound, int upperBound);
 float averageIntegerArray(int values[], int count);
 int findExtremeInIntegerArray(int minOrMax, int values[], int count);
 
 // prototypes for Dr. T functions
 void buildLinkedListFromString(char string[]);
 void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	 LinkedList *node);
 LinkedList *getNode(char string[], int spaceIndex);
 int getNumber();
 
 /*
  * Height Statisticamator Programming Assignment
  */
 int main(int argc, char** argv)
 {
	 char input[MAX_LENGTH];
	 fgets(input, MAX_LENGTH, stdin);
	 while (input[0] != 'q')
	 {
		 buildLinkedListFromString(input);
 
		 // BEGIN: Student Code
		 int numHeights = getValidInteger(1, 100);
		 int heights[100];
		 int count = 0;
 
		 while (count < numHeights)
		 {
			 int height = getValidInteger(1, 96);
			 heights[count++] = height;
		 }
 
		 float avg = averageIntegerArray(heights, count);
		 int min = findExtremeInIntegerArray(MIN, heights, count);
		 int max = findExtremeInIntegerArray(MAX, heights, count);
 
		 printf("%.2f %d %d\n", avg, min, max);
		 // END: Student Code
 
		 fgets(input, MAX_LENGTH, stdin);
	 }
 
	 return 0;
 }
 
 // Student-implemented functions
 
 int getValidInteger(int lowerBound, int upperBound)
 {
	 int value = getNumber();
	 while (value < lowerBound || value > upperBound)
	 {
		 value = getNumber();
	 }
	 return value;
 }
 
 float averageIntegerArray(int values[], int count)
 {
	 int sum = 0;
	 for (int i = 0; i < count; i++)
	 {
		 sum += values[i];
	 }
	 return (float)sum / count;
 }
 
 int findExtremeInIntegerArray(int minOrMax, int values[], int count)
 {
	 int result = values[0];
	 for (int i = 1; i < count; i++)
	 {
		 if (minOrMax == MIN && values[i] < result)
		 {
			 result = values[i];
		 }
		 else if (minOrMax == MAX && values[i] > result)
		 {
			 result = values[i];
		 }
	 }
	 return result;
 }
 
 // DO NOT MODIFY BELOW THIS LINE
 
 void buildLinkedListFromString(char string[])
 {
	 int spaceIndex = -1;
	 char *result = NULL;
	 result = strchr(string, ' ');
	 char *stringStart = &string[0];
 
	 while (result != NULL)
	 {
		 spaceIndex = result - stringStart;
 
		 LinkedList *node = getNode(stringStart, spaceIndex);
		 addNodeToList(&head, &tail, node);
 
		 string = &string[0] + spaceIndex + 1;
		 result = strchr(string, ' ');
		 stringStart = &string[0];
	 }
 
	 LinkedList *node = getNode(stringStart, strlen(stringStart));
	 addNodeToList(&head, &tail, node);
 }
 
 void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer,
	 LinkedList *node)
 {
	 if (*headPointer == NULL)
	 {
		 *headPointer = node;
	 }
	 else
	 {
		 (*tailPointer)->next = node;
	 }
	 *tailPointer = node;
 }
 
 LinkedList *getNode(char string[], int length)
 {
	 char* intString = malloc((length + 1) * sizeof(char));
	 strncpy(intString, string, length);
	 intString[length] = '\0';
	 int value = atoi(intString);
 
	 free(intString);
	 intString = NULL;
 
	 LinkedList *node;
	 node = malloc(sizeof(struct LinkedList));
	 node->data = value;
	 node->next = NULL;
	 return node;
 }
 
 int getNumber()
 {
	 int value;
	 if (head != NULL)
	 {
		 value = head->data;
 
		 LinkedList *temp = head;
		 head = head->next;
		 free(temp);
	 }
	 else
	 {
		 value = -1;
	 }
	 return value;
 }
 