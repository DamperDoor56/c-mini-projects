#include<stdio.h>
#include<time.h>


int main() {
    time_t s;
    struct tm* current_time;
    struct tm* ;

    // time in seconds
    s = time(NULL);
    // get current time owo

    current_time = localtime(&s);

    printf("%02d : %02d : %02d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}
