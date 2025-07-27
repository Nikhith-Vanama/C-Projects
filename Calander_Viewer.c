#include <stdio.h>

// Function to check leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// Function to get number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default:return 30;
    }
}

// Function to calculate day of week for Jan 1 of the year
int getStartDay(int year) {
    int d = 1, m = 1;
    year--;
    int day = (year + year/4 - year/100 + year/400 + 1) % 7;
    return day; // 0=Sunday, 1=Monday,...
}

void printMonth(int month, int year, int *startDay) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int days = getDaysInMonth(month, year);

    printf("\n\n  ------------%s %d-------------\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < *startDay; i++) {
        printf("     ");
    }

    for (int i = 1; i <= days; i++) {
        printf("%5d", i);
        if (++(*startDay) > 6) {
            *startDay = 0;
            printf("\n");
        }
    }
    if (*startDay != 0)
        printf("\n");
}

int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    int startDay = getStartDay(year);
    for (int month = 1; month <= 12; month++) {
        printMonth(month, year, &startDay);
    }

    return 0;
}
