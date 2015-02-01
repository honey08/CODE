/*! \mainpage SOFTWARE LABORATORY ASSIGNMENT-3
 *@file asg3.c
 *@brief Assignment-3
 *  
 *
 *@author Honey sharma
 *  
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void combination(int length,int *array);
void permutation(int *a,int i,int n);
void swap (int *x, int *y);
void save_print(int *x);
int factorial(int num);
int k;
/**
 *This variable saves the all unique permutation calculated.
 *
 */
int data_p[100000000][4];
/**
* It value denotes the total number of unique permutations.
*/
int number_p;
FILE *fp2;

/** @brief Main function
 *
 *  The main function reads/takes the input as a string, tokenizes it and converts the character strings into integer values and stores them
 *  into array. It then call the function combination().
 *
 *  @param input[] Saves/Read into the input string.
 *  @param input1[] Saves the input array after tokenization and and cnversion.
 */
int main()
{	
	char input[100],*token,*tokens[100];;
	int i,j,length,input1[100],n_p;
	FILE *fp1;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output3.txt","w");
	if(fp1 == NULL)
	{
		printf("File not found");
		return 0;
	}
	fscanf(fp1,"%s",input);
	//printf("Enter input\n");	
	//scanf("%s",input);
	length = strlen(input);
	tokens[0] = strtok(input,",");    	/* tokenising the input using ',' */
	for(i=1;i<length;i++)
	{
		token = strtok(NULL,",");
		if(token != NULL)
		tokens[i] = token;
		if(token == NULL)
		break;
	}	                         	/* 'i' represents number of tokens */
		
	for(j=0;j<=i-1;j++)
	{
		input1[j] = atoi(tokens[j]);	/* string to numerical conversion */
	}
	k = input1[i-1];               		/* last token represents k */
	combination(i-1,input1);       		/* to find all combinations of input tokens */
	return 0;
}
/** @brief combination
 *
 *  This function calculates the all the combinations of the input passed to it. It calculates a combination and simultaneously calls
* permutation() to find out all the permutations
 *
 *  @param array Pointer that points to the input passed to it.
 *  
 */
void combination(int length,int *array)
{
	int localarray[4];
	int i,j,k,l;
	for(i=0;i<length-3;i++)
	{
		for(j=i+1;j<length-2;j++)
		{
			for(k=j+1;k<length-1;k++)
			{
				for(l=k+1;l<length;l++)
				{
				localarray[0] = array[i];
				localarray[1] = array[j];
				localarray[2] = array[k];
				localarray[3] = array[l];
				permutation(localarray,0,3);	
				}
			}
		}
	}
}
/** @brief permutation
 *
 *  This function calculates the all the permutations of the input passed to it. It simultaneously calls save_print() for further
 * processing.
 *  @param a Pointer that points to the input passed to it.
 *  
 */
void permutation(int *a,int i,int n)
{
   int j;
   if (i == n)
     	save_print(a);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permutation(a, i+1, n);
          swap((a+i), (a+j));
       }
   }
} 
/** @brief swap
 *
 *  This function swaps the values passed to it. It is used by permutation() function for swapping purposes.
 *
 */
void swap (int *x, int *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/** @brief save_print
 *
 *  This function saves the permutation calculated alongside discarding those that are repeated.It is also called by permutation() function.
 * It finally solves the equation for each saved permutation and prints/redirects it.
 */
void save_print(int *x)
{	
	int i,count;
	if(number_p==0)
	{
		data_p[0][0] = *x;
		data_p[0][1] = *(x+1);
		data_p[0][2] = *(x+2);
		data_p[0][3] = *(x+3);
		if((*x) + (*(x+1)) + (*(x+2)) * (*(x+3)) <= k)
		{fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_p[0][0],data_p[0][1],data_p[0][2],data_p[0][3]);
		//printf("\"%d,%d,%d,%d\"\n",data_p[0][0],data_p[0][1],data_p[0][2],data_p[0][3]);
		}
		number_p = 1;
	}
	else
	{	
		count = 0;
		for(i=0;i<number_p;i++)
		{	
			if(data_p[i][0] != *x||data_p[i][1] != *(x+1)||data_p[i][2] != *(x+2)||data_p[i][3] !=*(x+3))
			count++;
		}
		if(count == number_p)
		{	
			data_p[number_p][0] = *x;
			data_p[number_p][1] = *(x+1);
			data_p[number_p][2] = *(x+2);
			data_p[number_p][3] = *(x+3);
			if((*x) + (*(x+1)) + (*(x+2)) * (*(x+3)) <= k)
			{fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_p[number_p][0],data_p[number_p][1],data_p[number_p][2],data_p[number_p][3]);	
			//printf("\"%d,%d,%d,%d\"\n",data_p[number_p][0],data_p[number_p][1],data_p[number_p][2],data_p[number_p][3]);
			}
			number_p++;
		}
	}
}


