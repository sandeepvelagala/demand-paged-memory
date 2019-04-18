#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
double page_fault_rate();
void userInput(void);

double spfe,spfm,memacctym,tympagmod,effacctym,PFR,spfens,spfmns,tympagmodp;
	

void main(){
	int op,t=0;
	main:
	system("cls");
	system("COLOR 05");
	printf("*****************DEMAND PAGING*****************\n");
	printf("1.PAGE FAULT RATE.\n");
	printf("2.TO EXIT FROM THE INTERFACE.");
	printf("\nSELECT ANY OPTION:");
	
	scanf("%d",&op);
	switch(op){
		case 1:
		 {
		 	userInput();
		 	t=1;
			 break;
		 }
		case 2:
		{
			exit(0);
		}
		default:
			{
				printf("\nU HAVE SELECTED AN INVALID OPTION...PLEASE TRY AGAIN");
				sleep(3);
				goto main;
			}
	}
	if(t==1)
	{
	  t=0;
	  goto main; 	
	 }
}
	scanf("%lf",&spfe);
	printf("\nEnter Service Page Fault (Modified Page)[in milliseconds] : ");
	scanf("%lf",&spfm);
	printf("\n Enter Memory Access Time[in nanoseconds] :");

}

