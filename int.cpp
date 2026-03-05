#include <stdio.h>
int main() {
    float units, bill;

    
    scanf("%f", &units);

    if (units <= 199)
	{
        bill = units * 1.20;
    } 
	else if (units>=200||units<400)
	 {
        bill = (units)*1.50;
    } 
	else if (units>=400||units<600)
	 {
        bill = (units)*1.80;
    } 
	else
	 {
        bill =(units)*2.00;
     }
     
     int ans = bill;
		if (ans>=400)
		{
			printf("%.2f",ans+(ans*0.15));
		}
		else
		{
			printf("%.2f",ans+100);
        }
}
