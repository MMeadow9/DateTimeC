#include <stdio.h>

typedef struct Time {
    // Структура реализующая время
    int format;  // Формат времени (24 или 12 часов)
    int hours;
    int minutes;
    int seconds;
} Time;

void print_time(Time t) {
    // Функция печатающая время
    if (t.format == 12) {
        if (t.hours > 11) {
            printf("%02d:%02d:%02d - AM\n", (t.hours % 12), t.minutes, t.seconds);
        }
        if (t.hours < 12) {
            printf("%02d:%02d:%02d - PM\n", (t.hours % 12), t.minutes, t.seconds);
        }
    }
    if (t.format == 24) {
        printf("%02d:%02d:%02d\n", (t.hours % 24), t.minutes, t.seconds);
    }
}

Time add(Time t1, Time t2) {
    // Функция объединяющая два времени
    int seconds = t1.seconds + t2.seconds;
    int minutes = t1.minutes + t2.minutes + seconds / 60;
    int hours = (t1.hours + t2.hours + (minutes / 60)) % 24;
    
    seconds %= 60;
    minutes %= 60;

    return (Time){t1.format, hours, minutes, seconds};
}

Time sub(Time t1, Time t2) {
    // Функция вычитающая два времени
    int all_seconds = (t1.seconds - t2.seconds) + (t1.minutes - t2.minutes) * 60 + (t1.hours - t2.hours) * 3600;

    int seconds = all_seconds % 60;
    int minutes = all_seconds / 60 % 60;
    int hours = (all_seconds / 3600) % 24;

    return (Time){t1.format, hours, minutes, seconds};
}

int main() {
    Time t1 = {24, 18, 40, 20};
    Time t2 = {24, 11, 55, 35};
    Time t3 = {12, 18, 40, 20};
    Time t4 = {12, 11, 55, 35};
    
    print_time(t1);  // 18:40:20
    print_time(t2);  // 11:55:35
    print_time(t3);  // 06:40:20 - AM
    print_time(t4);  // 11:55:35 - PM
}
