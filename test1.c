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
void userInput(){
	
	
	printf("\nEnter service Page Fault (Empty|not Modified)[in milliseconds] :  ");
	scanf("%lf",&spfe);
	printf("\nEnter Service Page Fault (Modified Page)[in milliseconds] : ");
	scanf("%lf",&spfm);
	printf("\n Enter Memory Access Time[in nanoseconds] :");
	scanf("%lf",&memacctym);
	printf("\nEnter Percentage of time the page to be replaced is modified:");
	scanf("%lf",&tympagmod);
	printf("\n Enter Effective Access time[in nanoseconds] : ");
	scanf("%lf",&effacctym);

	spfens = (spfe*1000000);
	spfmns = (spfm*1000000);
	tympagmodp = (tympagmod/100);
	system("cls");   
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n********************Page Fault rate calculated For************************");
	system("COLOR 01");
    sleep(1);f
    system("COLOR 02");
    sleep(1);
    system("COLOR 0D");
    sleep(1);
    system("COLOR 0C");
    sleep(1);
    system("COLOR 0A");
    sleep(1);
    system("COLOR 03");
    sleep(1);
    system("cls");
	printf("\n Service Page Fault[Empty|Page Not Modified] =  %lf \n",spfens);
	printf("\n Service Page Fault [Modified Page][ nanoseconds] :%lf \n",spfmns);
	printf("\n Memory Access Time[in nanoseconds] : %lf\n",memacctym);
	printf(" Effective Access Time %lf\n",effacctym);
    PFR =  page_fault_rate(spfens,spfmns,memacctym,tympagmodp,effacctym);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",PFR);
	printf("\n\nPress any key to goto main menu");
	getch();


}

double page_fault_rate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double numErator,denOminator;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 numErator = effAccess - memAccess;
     denOminator = (assume+serve);

	pageFault = numErator/denOminator;
	
	return pageFault;


}

