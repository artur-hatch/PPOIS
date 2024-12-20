#pragma once

class CustomDate {
private:
    int year_;
    int month_;
    int day_;

public:
    CustomDate();
    CustomDate(int day, int month, int year);

    void setYear(int yearValue);
    void setMonth(int monthValue);
    void setDay(int dayValue);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    static CustomDate computeDifference(const CustomDate& earlier, const CustomDate& later);

    bool operator==(const CustomDate& other) const {
        return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
    }
    bool equals(const CustomDate& anotherDate) const;
    void copy(const CustomDate& anotherDate);
};
