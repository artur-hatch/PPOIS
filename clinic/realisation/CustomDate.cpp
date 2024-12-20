#include "../include/CustomDate.h"

CustomDate::CustomDate() : year_(0), month_(1), day_(1) {}

CustomDate::CustomDate(int day, int month, int year) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

void CustomDate::setYear(int yearValue) {
    year_ = (yearValue >= 0) ? yearValue : 0; // Год не может быть отрицательным
}

void CustomDate::setMonth(int monthValue) {
    month_ = (monthValue >= 1 && monthValue <= 12) ? monthValue : 1; // Диапазон месяцев: 1–12
}

void CustomDate::setDay(int dayValue) {
    day_ = (dayValue >= 1 && dayValue <= 30) ? dayValue : 1; // Упрощение: все месяцы по 30 дней
}

int CustomDate::getYear() const {
    return year_;
}

int CustomDate::getMonth() const {
    return month_;
}

int CustomDate::getDay() const {
    return day_;
}

CustomDate CustomDate::computeDifference(const CustomDate& earlier, const CustomDate& later) {
    CustomDate result;

    int totalDaysEarlier = earlier.year_ * 360 + earlier.month_ * 30 + earlier.day_;
    int totalDaysLater = later.year_ * 360 + later.month_ * 30 + later.day_;
    int differenceInDays = totalDaysLater - totalDaysEarlier;

    result.setYear(differenceInDays / 360);
    differenceInDays %= 360;
    result.setMonth(differenceInDays / 30);
    result.setDay(differenceInDays % 30);

    return result;
}

bool CustomDate::equals(const CustomDate& anotherDate) const {
    return year_ == anotherDate.getYear() &&
           month_ == anotherDate.getMonth() &&
           day_ == anotherDate.getDay();
}

void CustomDate::copy(const CustomDate& anotherDate) {
    setYear(anotherDate.getYear());
    setMonth(anotherDate.getMonth());
    setDay(anotherDate.getDay());
}
