/*! \mainpage SOFTWARE LABORATORY ASSIGNMENT-3
 *
 * \section problem PROBLEM STATEMENT
 *
 * Given a set S , find all possible subsets(a,b,c,d) such that a + b + c * d ​< ​ k, where​ k and the set S are to be read from user as 
 * separated values . Print the results in the form of a tuple “a,b,c,d”.
 * 
* \section intro INTRODUCTION
*
* This document contains details of logic used in implementing problem statement of assignment-3.
* The whole logic/program is written in C language. It also contains the comparisons of size of executable file 
* amd time take by program to run at various optimization levels done using gprof.
* The various softwares/packages used were Eclipse(IDE),gcc,gdb,gprof,doxygen,github,latex,astyle,dia.
*
* \section comparisons COMPARISONS
* The comparisons are were done using gprof at various optimizations levels.
* The test set used for comparison contains 20 different input values from 1 to 20
* and the value of k was set to 100.
*
* <table border="1" style="width:100%">
* <tr>
 *   <th>Optimization Level</th>
 *   <th>Running Time (in sec) for asg.c</th>		
 *   <th>Executable Size (in Kb)for asg.c</th>
 *   <th>Running Time (in sec) for asg3.c</th>		
 *   <th>Executable Size (in Kb)for asg3.c</th>
 * </tr>
* <tr>
 *   <td>O0</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 * </tr>
* <tr>
 *   <td>O1</td>
 *   <td>8.11</td>		
 *   <td>13.5</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 * </tr>
 * <tr>
 *   <td>O2</td>
 *   <td>11.37</td>		
 *   <td>13.5</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 * </tr>
 * <tr>
 *   <td>O3</td>
 *   <td>11.83</td>		
 *   <td>13.5</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 * </tr>
 * <tr>
 *   <td>Ofast</td>
 *   <td>11.84</td>		
 *   <td>15</td>
 *   <td>26.02</td>		
 *   <td>13.6</td>
 * </tr>
 * <tr>
 *   <td>Os</td>
 *   <td>9.79</td>		
 *   <td>13.5</td>
 * </tr>
 * </table>
 *
 *@file asg.c
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
void save(int *x);
void check();
/** 
 * 2-D array that stores all the combinations of input.
 */
int data_c[10000000][4];
/** 
 * 2-D array that stores all the permutations of input.
 */
int data_p[10000000][4];
/** 
 * 2-D array that stores all the final unique permutations of input.
 */
int data_o[10000000][4];
int number_c,number_p,number_o;

/** @brief Main function
 *
 *  The main function reads/takes the input as a string, tokenizes it and converts the character strings into integer values and stores them
 *  into array. It then calls the functions combination(),permutation() and check() and finally prints/saves the output.
 *
 *  @param input[] Saves/Read into the input string.
 *  @param input1[] Saves the input array after tokenization and and cnversion.
 */

int main()
{	
	char input[100],*token,*tokens[100];;
	int i,j,k,length,input1[100];
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
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
	for(j=0;j<=number_c-1;j++)       
	permutation((int*)(data_c[j]),0,3);	/* to find all permutations of input tokens */
	check();				/* to check whether a particular combination is repeated or not */
	fp2 = fopen("output.txt","w");	
	for(j=0;j<number_o;j++)
	{
		if(data_o[j][0]+data_o[j][1]+data_o[j][2]*data_o[j][3] <= k)
		{fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_o[j][0],data_o[j][1],data_o[j][2],data_o[j][3]);
		//printf("\"%d,%d,%d,%d\"\n",data_o[j][0],data_o[j][1],data_o[j][2],data_o[j][3]);
		}	
	}
	//fclose(fp2);
	return 0;
}
/** @brief combination
 *
 *  This function calculates the all the combinations of the input passed to it and saves them in array data_c.
 *
 *  @param array Pointer that points to the input passed to it.
 *  
 */
void combination(int length,int *array)
{
	int i,j,k,l;
	for(i=0;i<length-3;i++)
	{
		for(j=i+1;j<length-2;j++)
		{
			for(k=j+1;k<length-1;k++)
			{
				for(l=k+1;l<length;l++)
				{
				data_c[number_c][0] = array[i];
				data_c[number_c][1] = array[j];
				data_c[number_c][2] = array[k];
				data_c[number_c][3] = array[l];
				number_c++;	
				}
			}
		}
	}
}
/** @brief permutation
 *
 *  This function calculates the all the permutations of the input passed to it and saves them in array data_p.
 *
 *  @param a Pointer that points to the input passed to it.
 */
void permutation(int *a,int i,int n)
{
   int j;
   if (i == n)
     save(a);
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
/** @brief save
 *
 *  This function saves the permutation calculated. It is also called by permutation() function.
 *
 */
void save(int *x)
{
	static int y = 0;
	data_p[y][0] = *x;
	data_p[y][1] = *(x+1);
	data_p[y][2] = *(x+2);
	data_p[y][3] = *(x+3);
	y = y + 1;
	number_p = y;
}
/** @brief check
 *
 *  This function checks whether a particular permutation is repeated or not. If repeated it simply discards it.
 *
 */
void check()
{	int i,j,count;
	data_o[0][1] = data_p[0][1];
	data_o[0][2] = data_p[0][2];
	data_o[0][0] = data_p[0][0];
	data_o[0][3] = data_p[0][3];
	number_o = 1;
	for(i=1;i<number_p;i++)
	{	count = 0;
		for(j=0;j<i;j++)
		{
			if(data_p[i][0] != data_p[j][0]||data_p[i][1] != data_p[j][1]||data_p[i][2] != data_p[j][2]||data_p[i][3] != 				data_p[j][3])
			{
			count++;
			}
		}
		if(count == i)
		{	
			data_o[number_o][1] = data_p[i][1];
			data_o[number_o][2] = data_p[i][2];
			data_o[number_o][0] = data_p[i][0];
			data_o[number_o][3] = data_p[i][3];
			number_o++;
		}
	}
}

