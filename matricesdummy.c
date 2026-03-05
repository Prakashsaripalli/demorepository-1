#include<stdio.h>
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}

    }
    int odd=0;
    int even=0; 
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
            if(arr[i][j]%2==0)
            {
                even=even+arr[i][j];
            }
            else
            {
                odd=odd+arr[i][j];
            }
		}
    }
    printf("%d\n",even);
    printf("%d",odd);

    return 0;
    
}
