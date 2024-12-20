#pragma once
#include "../include/DocumentSignature.h"
#include "../include/CustomDate.h"
#include <string>
#include <memory>

class Recipe {
private:
    std::string medicineName_;
    std::unique_ptr<DocumentSignature> signature_;
    std::unique_ptr<CustomDate> dateFrom_;
    std::unique_ptr<CustomDate> dateTo_;

public:
    Recipe();
    Recipe(const std::string& name, const std::string& doctorSignature, const CustomDate& startDate, const CustomDate& endDate);
    Recipe(const std::string& medicineName, const std::string& firstName, const std::string& middleName, const std::string& familyName,
           const std::string& uniqueSignature, int startDay, int startMonth, int startYear,
           int endDay, int endMonth, int endYear);
           
    void setMedicineName(const std::string& medicineName);
    void setSignature(const DocumentSignature& signature);
    void setStartDate(const CustomDate& startDate);
    void setEndDate(const CustomDate& endDate);

    std::string getMedicineName() const;
    const DocumentSignature* getSignature() const;
    const CustomDate* getStartDate() const;
    const CustomDate* getEndDate() const;

    bool operator==(const Recipe& other) const;
    Recipe& operator=(const Recipe& other);
};