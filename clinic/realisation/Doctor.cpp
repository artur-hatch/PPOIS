#include "../include/Doctor.h"

Doctor::Doctor() = default;

Doctor::Doctor(const IdCard& idCard, int lifeStatus, double salary)
        : HealthProfessional(idCard, lifeStatus, salary) {}

Doctor::Doctor(const std::string& name, const std::string& surname, const std::string& lastName,
               const std::string& uniqueSignature, const std::string& gender, int age,
               const std::string& country, const std::string& maritalStatus,
               const std::string& idNumber, double salary, int lifeStatus)
        : HealthProfessional(name, surname, lastName, uniqueSignature, gender, age,
                             country, maritalStatus, idNumber, lifeStatus, salary) {}

void Doctor::revivePatient(Client* patient) const {
    patient->setLifeStatus(true);
}

void Doctor::performSurgery(Client* patient, HealthProfessional* assistant) const {
    if (!patient->getLifeStatus()) {
        revivePatient(patient);
    } else {
        patient->setLifeStatus(static_cast<int>(patient->getLifeStatus() * 1.3));
    }
}

void Doctor::prescribeMedication(Client* patient, const std::string& medicineName,
                                 const CustomDate& startDate, const CustomDate& endDate) const {
    // Получаем строку из подписи документа (предполагается, что метод toString() существует)
    std::string doctorSignature = getIdCard()->getSignature()->toString(); // Разыменовываем указатель и получаем строку

    // Создаем рецепт с использованием строки для подписи
    Recipe* prescription = new Recipe(medicineName, doctorSignature, startDate, endDate);

    // Добавляем рецепт в медицинскую карту пациента
    patient->addPrescription(prescription);

    // Записываем в медицинскую историю пациента
    patient->retrieveMedicalRecord()->appendMedicalHistory("Prescription issued for " + medicineName);
}


