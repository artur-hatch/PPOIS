#include "../include/Recipe.h"

Recipe::Recipe()
        : signature_(std::make_unique<DocumentSignature>()),
          dateFrom_(std::make_unique<CustomDate>()),
          dateTo_(std::make_unique<CustomDate>()) {}

Recipe::Recipe(const std::string& medicineName, const std::string& doctorSignature, const CustomDate& startDate, const CustomDate& endDate)
        : Recipe() {
    setMedicineName(medicineName);
    // Подпись преобразуем в объект DocumentSignature (если она передается как строка)
    signature_ = std::make_unique<DocumentSignature>(doctorSignature);
    setStartDate(startDate);
    setEndDate(endDate);
}

Recipe::Recipe(const std::string& medicineName, const std::string& firstName, const std::string& middleName, const std::string& familyName,
               const std::string& uniqueSignature, int startDay, int startMonth, int startYear,
               int endDay, int endMonth, int endYear)
        : Recipe() {
    setMedicineName(medicineName);
    signature_ = std::make_unique<DocumentSignature>(uniqueSignature, firstName, middleName, familyName);
    dateFrom_ = std::make_unique<CustomDate>(startDay, startMonth, startYear);
    dateTo_ = std::make_unique<CustomDate>(endDay, endMonth, endYear);
}

void Recipe::setMedicineName(const std::string& medicineName) {
    medicineName_ = medicineName;
}

void Recipe::setSignature(const DocumentSignature& signature) {
    if (!signature_) {
        signature_ = std::make_unique<DocumentSignature>();
    }
    *signature_ = signature;
}

void Recipe::setStartDate(const CustomDate& startDate) {
    if (!dateFrom_) {
        dateFrom_ = std::make_unique<CustomDate>();
    }
    *dateFrom_ = startDate;
}

void Recipe::setEndDate(const CustomDate& endDate) {
    if (!dateTo_) {
        dateTo_ = std::make_unique<CustomDate>();
    }
    *dateTo_ = endDate;
}

std::string Recipe::getMedicineName() const {
    return medicineName_;
}

const DocumentSignature* Recipe::getSignature() const {
    return signature_.get();
}

const CustomDate* Recipe::getStartDate() const {
    return dateFrom_.get();
}

const CustomDate* Recipe::getEndDate() const {
    return dateTo_.get();
}

bool Recipe::operator==(const Recipe& other) const {
    return medicineName_ == other.getMedicineName() &&
           *signature_ == *(other.getSignature()) &&
           *dateFrom_ == *(other.getStartDate()) &&
           *dateTo_ == *(other.getEndDate());
}

Recipe& Recipe::operator=(const Recipe& other) {
    if (this != &other) {
        setMedicineName(other.getMedicineName());
        setSignature(*(other.getSignature()));
        setStartDate(*(other.getStartDate()));
        setEndDate(*(other.getEndDate()));
    }
    return *this;
}
