#include <stdio.h>
#include <string.h>


int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);

	int cases,icases;
	int n,m,k;

	scanf("%d",&cases);
	icases=1;

	while(icases<=cases)
	{
		scanf("%d %d",&n,&k);
		m=(1<<n)-1;
		if((m&k)==m)
			printf("Case #%d: ON\n",icases);
		else
			printf("Case #%d: OFF\n",icases);
		icases++;

	}

	return 0;
}