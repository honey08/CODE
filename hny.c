#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void combination(int length,int *array);
void permutation(int *a,int i,int n);
void swap (int *x, int *y);
void save(int *x);
void check();

int data_c[10000000][4];
int data_p[10000000][4];
int data_o[10000000][4];
int number_c,number_p,number_o;

int main()
{	
	char input[100],*token,*tokens[100];;
	int i,j,k,length,input1[100];
	/*FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	if(fp1 == NULL)
	{
		printf("File not found");
		return 0;
	}
	
	fscanf(fp1,"%s",input);*/
	printf("Enter input\n");	
	scanf("%s",input);
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
	//fp2 = fopen("output.txt","w");	
	for(j=0;j<number_o;j++)
	{
		if(data_o[j][0]+data_o[j][1]+data_o[j][2]*data_o[j][3] <= k)
		{//fprintf(fp2,"\"%d,%d,%d,%d\"\n",data_o[j][0],data_o[j][1],data_o[j][2],data_o[j][3]);
		printf("\"%d,%d,%d,%d\"\n",data_o[j][0],data_o[j][1],data_o[j][2],data_o[j][3]);}	
	}
	//fclose(fp2);
	return 0;
}
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
void swap (int *x, int *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
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

