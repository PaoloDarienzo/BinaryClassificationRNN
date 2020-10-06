#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int bDone;
	int i, j, N;
	int K, twoN, twoNo;
	char buf[1024];
	
	gets(buf);

	j = atoi(buf);

	for(i=0; i<j; i++)
	{
		gets(buf);

		N=0;
		K=0;
		sscanf(buf, "%d %I64d", &N, &K);
		twoN = (1 << N);
		twoNo = twoN;
		
		if(K == 0)
		{
			printf("Case #%d: OFF\n",i+1);
		}
		else
		{
			bDone = 0;
			while(twoN - 1 <= K && bDone == 0)
			{
			  if(K == twoN - 1)
			  {
				  printf("Case #%d: %s\n",i+1,"ON");
				  bDone = 1;
				  break;
			  }
			  twoN += twoNo;
			}

			if(bDone == 0)
			{
				  printf("Case #%d: %s\n",i+1,"OFF");
			}
		}
	}
}
