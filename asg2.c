#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void combination(int length,int *array);
void permutation(int *a,int i,int n);
void swap (int *x, int *y);
void save_print(int *x);
int factorial(int num);
int k;
int **data_p;
int number_p;
FILE *fp2;

int main()
{	FILE *fp1;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output2.txt","w");
	if(fp1 == NULL)
	{
		printf("File not found");
		return 0;
	}
	char input[100],*token,*tokens[100];;
	int i,j,length,input1[100],n_p;
	//printf("Enter input\n");	
	//scanf("%s",input);
	//printf("%s\n",input);
	fscanf(fp1,"%s",input);
	length = strlen(input);
	//printf("%d\n",length);
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
		//printf("%s\n",tokens[j]);
		input1[j] = atoi(tokens[j]);	/* string to numerical conversion */
		//printf("%d\n",input1[j]);
	}
	k = input1[i-1];               		/* last token represents k */
	n_p = factorial(i-1)/(factorial(i-1-4));	/* number of permutations */ 
	//printf("%d\n",n_p);
	data_p = (int **)calloc(n_p,sizeof(int*));
	for(j = 0; j < n_p; j++){
  	data_p[j] = (int *)calloc(4,sizeof(int));}
	combination(i-1,input1);       		/* to find all combinations of input tokens */
	//printf("---------------------\n");	
	//for(j=0;j<=number_p-1;j++)
	//printf("%d %d %d %d\n",data_p[j][0],data_p[j][1],data_p[j][2],data_p[j][3]);
	return 0;
}
int factorial(int num)
{
	int i,fact=1;
	for(i=2;i<=num;i++)
	fact = fact*i;
	return fact;
}
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
				//printf("%d %d %d %d\n",localarray[0],localarray[1],localarray[2],localarray[3]);
				permutation(localarray,0,3);	
				}
			}
		}
	}
	//printf("%d\n",number_c);
}
void permutation(int *a,int i,int n)
{
   int j;
   if (i == n)
     	save_print(a);
	//printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
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
void swap (int *x, int *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void save_print(int *x)
{	
	int i,count;
	if(number_p==0)
	{
		data_p[0][0] = *x;
		data_p[0][1] = *(x+1);
		data_p[0][2] = *(x+2);
		data_p[0][3] = *(x+3);
		fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_p[0][0],data_p[0][1],data_p[0][2],data_p[0][3]);
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
		//printf("%d\n",count);
		if(count == number_p)
		{	
			data_p[number_p][0] = *x;
			data_p[number_p][1] = *(x+1);
			data_p[number_p][2] = *(x+2);
			data_p[number_p][3] = *(x+3);
			if((*x) + (*(x+1)) + (*(x+2)) * (*(x+3)) <= k)
			fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_p[number_p][0],data_p[number_p][1],data_p[number_p][2],data_p[number_p][3]);	
			number_p++;
		}
	}
}


