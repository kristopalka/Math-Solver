#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int find(char* in, char toFind, int beg, int end)
{
	for(int i=beg; i<end; i++)
	{
		if(in[i] == toFind) return i;
	}
	return -1;
}

int findRestpondingBracket(char* in, int beg, int end)
{
	int n = 0;
	for(int i=beg; i<=end; i++)
	{
		if(in[i] == '(') n++;
		else if(in[i] == ')' && n>1) n--;
		else if(in[i] == ')' && n==1) return i;
	}
	return -1;
}



void doubleToInput(char* in, int beg, int end, double num)
{
	int len = end - beg + 1;
	char nums[len+1];
	snprintf(nums, len+1, "%f", num);
	

	for(int i=0; i<len; i++)
	{
		in[i+beg] = nums[i];
	}
}

////////////////////////////////////////////////////////////////////////////////

double solve(char* in, int beg, int end)
{

	int i = find(in,'+', beg, end);
	if (i != -1) return solve(in, beg, i) + solve(in, i + 1, end);

	i = find(in,'-', beg, end);
	if (i != -1) return solve(in, beg, i) - solve(in, i + 1, end);

	i = find(in,'*', beg, end);
	if (i != -1) return solve(in, beg, i) * solve(in, i + 1, end);

	i = find(in,'/', beg, end);
    if (i != -1) return solve(in, beg, i) / solve(in, i + 1, end);

    i = find(in,'^', beg, end);
    if (i != -1) return pow(solve(in, beg, i), solve(in, i + 1, end));

	char *eptr = in + end;;
	return strtod(in + beg, &eptr);
}

double bracketsSolver(char* in, int len)
{

	int i = find(in, '(', 0, len);
	int j = findRestpondingBracket(in, i, len);
	//printf("%s ", in);
	//printf("%d ", i);
	//printf("%d\n", j);
	
	while(i != -1)
	{
    	if(j != -1)
		{
			int len = j-i-1;
			char subIn[len];
			memcpy(subIn, in+i+1, len);
			
     	    double result = bracketsSolver(subIn, len);
     	    
     	    doubleToInput(in, i, j, result);
		} 
		else 
		{
			perror("There is not enough closing brackets");
			return 0;
		}
		
		
		i = find(in, '(',  0, len);
		j = findRestpondingBracket(in, j, len);
		//printf("%s ", in);
		//printf("%d ", i);
		//printf("%d\n", j);
		//printf("%d\n", len);
	}
	
	return solve(in, 0, len-1);
}


int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		printf("%g\n",bracketsSolver(argv[1], strlen(argv[1])));
	}
	else
	{
		perror("There is nothink to solve");
		return 1;
	}
	return 0;
}
