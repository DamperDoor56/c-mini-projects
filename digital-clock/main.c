
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>


int main() {
int hour, second = 0;
int minute= 59;

while(1) {
    system("clear"); // clear screen

    // print time in hh : mm : ss format
    printf("%02d : %02d : %02d", hour, minute, second);

    fflush(stdout); // clear buffer
    // increase seconds!
   second ++;

   if(second == 60) {
        minute+=1;
        second = 0;
   }
   if (minute == 60) {
        hour +=1;
        minute= 0;
   }
   if (hour == 24) {
        hour= 0;
        minute= 0;
        second= 0;
        }
    sleep(1); // wait 1 second
    }
    return 0;
}
