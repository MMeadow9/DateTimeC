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
    printf("%02d:%02d:%02d - format %d\n", (t.hours % t.format), t.minutes, t.seconds, t.format);
}

Time add(Time t1, Time t2) {
    // Функция объединяющая два времени
    int seconds = t1.seconds + t2.seconds;
    int minutes = t1.minutes + t2.minutes + seconds / 60;
    int hours = (t1.hours + t2.hours + (minutes / 60)) % t1.format;
    
    seconds %= 60;
    minutes %= 60;

    return (Time){t1.format, hours, minutes, seconds};
}

Time sub(Time t1, Time t2) {
    // Функция вычитающая два времени
    int all_seconds = (t1.seconds - t2.seconds) + (t1.minutes - t2.minutes) * 60 + (t1.hours - t2.hours) * 3600;

    int seconds = all_seconds % 60;
    int minutes = all_seconds / 60 % 60;
    int hours = (all_seconds / 3600) % t1.format;

    return (Time){t1.format, hours, minutes, seconds};
}

int main() {
    Time t1 = {24, 18, 40, 20};
    Time t2 = {24, 11, 55, 35};
    Time t3 = sub(t1, t2);  // Time{24, 6, 44, 45}
    print_time(t3);  // "06:44:45 - format 24"
}
