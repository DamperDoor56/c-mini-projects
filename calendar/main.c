#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] =
{
" ",
"\n\n\nJanuary",
"\n\n\nFebruary",
"\n\n\March",
"\n\n\nApril",
"\n\n\nMay",
"\n\n\nJune",
"\n\n\nJuly",
"\n\n\nAugust",
"\n\n\nSeptember",
"\n\n\nOctober",
"\n\n\nNovember",
"\n\n\nDecember"
};

int input_year(void) {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    return year;
}

//  Leap Years are any year that can be exactly divided by 4 (such as 2020, 2024, 2028, etc)
// if it can be exactly divided by 100, then it isn't (such as 2100, 2200, etc)
// except if it can be exactly divided by 400, then it is (such as 2000, 2400)
int check_leap_year(int year){
    if(year% 4 == FALSE && year %100 != FALSE || year%400 == FALSE) { // Check if it is divisible by 4 and not divisible by 100, and divisable by 400
        days_in_month[2] = 29; //If is leap year then add 29 days to february
        return TRUE;
    }
    else {
        days_in_month[2] = 28;
        return FALSE;
        }
    }

// To know more, check : https://www.mathsisfun.com/leap-years.html math is fun ;)

// Calculate the day of the week
int get_day_code(int year) {
    int daycode, d1, d2, d3;

    d1=(year -1.)/4.0; // counts leap years every 4 years
    d2=(year -1.)/100.; // normal years every 100 years
    d3=(year -1.)/400.; // leap years every 400 years

    daycode=(year + d1 - d2 + d3) %7;
    return daycode ;
    }

void calendar (int year, int daycode){
    int month, day;
    for(month= 1; month <= 12; month++){
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n ");

    // correct the position for the firsts dates
    for (day=1; day <=  1 + daycode * 5 ; day++){
        printf(" ");
        }
    // print all the dates for the month!
    for( day=1; day <= days_in_month[month]; day++){
        printf("%2d", day);

        // If day is before saturday else start on Sunday
        if((day + daycode) % 7 >0){
            printf("   ");
        }
        else {
                printf("\n ");

        }
        // Set position for next month
        daycode = (daycode + days_in_month[month]) %7;
    }}
}

int main (void){
    int year, daycode, leapyear;
    year= input_year();
    daycode= get_day_code(year);
    check_leap_year(year);
    calendar(year, daycode);
    printf("\n");
}
