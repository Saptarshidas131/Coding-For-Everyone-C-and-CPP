/*
Write enumerated types that supports dates—such as december 12. Then add a function that produces a next day.  So nextday(date) of december 12 is december 13. Also write a function printdate(date) that prints a date legibly.The function can assume that February has 28 days and it most know how many days are in each month. Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).
*/

#include<stdio.h>

int da=0;
int mo=0;

typedef enum month{January,February,March,April,May,June,July,August,September,October,November,December} month;

// function to print date legibly
void printdate()
{
	if(mo==2)
	printf("March %d\n",da);
	else if(mo==10)
	printf("November %d\n",da);
	else if(mo==0)
	printf("January %d\n",da);

	}
	typedef struct date{
	month m;
	int d;
} date;

// function to produce next day
void nextday(date dat)
{
	if(dat.m==1 && dat.d==28)
	{
	da=1;
	mo=(dat.m+1);


	}
	else if(dat.m==2 && dat.d==14)
	{
		da=15;
		mo=2;
	}
	else if(dat.m==9 && dat.d==31)
	{
		da=1;
		mo=10;
	}
	else if(dat.m==11 && dat.d==31)
	{
		da=1;
		mo=0;
	}


}

// main function
int main(){

	date dates;

	dates.m=February;
	dates.d=28;
	nextday(dates);
	printdate();

	dates.m=March;
	dates.d=14;
	nextday(dates);
	printdate();

	dates.m=October;
	dates.d=31;
	nextday(dates);
	printdate();

	dates.m=December;
	dates.d=31;
	nextday(dates);
	printdate();
}
