#ifndef DATE_TIME_H
#define DATE_TIME_H
#include "date_time.h"
#include <stdio.h>
#include <stdlib.h>

void show_date() {
    system("date /T");
}
void show_time() {
    system("time /T");
}
#endif
