#include <gtest/gtest.h>
#include "../include/Doctor.h"
#include "../include/Client.h"
#include "../include/Recipe.h"
#include "../include/CustomDate.h"
#include "../include/MedicalRecord.h"

class DoctorTest : public ::testing::Test {
protected:
    Doctor* doctor;
    Client* patient;
    CustomDate startDate;
    CustomDate endDate;

    DoctorTest() {
        // Создаем пациента и доктора
        doctor = new Doctor("John", "Doe", "Smith", "unique123", "Male", 30, "Country", "Single", "ID123", 1000.0, 1);
        patient = new Client("Jane", "Doe", "Smith", "unique456", "Female", 28, "Country", "Single", "ID456", "Address", 2, true, 1);

        startDate = CustomDate(1, 1, 2024);
        endDate = CustomDate(1, 2, 2024);
    }

    ~DoctorTest() {
        delete doctor;
        delete patient;
    }
};

TEST_F(DoctorTest, RevivePatientTest) {
// Проверка метода revivePatient
patient->setLifeStatus(false); // Пациент "умер"
doctor->revivePatient(patient);

ASSERT_TRUE(patient->getLifeStatus());  // Пациент должен быть "в живых"
}

TEST_F(DoctorTest, PerformSurgeryTest) {
// Проверка метода performSurgery
patient->setLifeStatus(false); // Пациент "умер"
doctor->performSurgery(patient, doctor);  // Проводим операцию

ASSERT_TRUE(patient->getLifeStatus());  // Пациент должен быть "в живых" после операции

// Проверка, что жизнь пациента увеличена
int lifeStatusBeforeSurgery = 0;  // Пациент был мертв
patient->setLifeStatus(lifeStatusBeforeSurgery);  // Умираем снова
doctor->performSurgery(patient, doctor);  // Еще раз операция

ASSERT_GT(patient->getLifeStatus(), lifeStatusBeforeSurgery);  // Жизнь пациента должна увеличиться после операции
}

TEST_F(DoctorTest, PrescribeMedicationTest) {
// Проверка метода prescribeMedication
const std::string medicineName = "Aspirin";

doctor->prescribeMedication(patient, medicineName, startDate, endDate);

// Проверим, что рецепт добавлен в список рецептов пациента
Recipe* recipe = patient->findPrescription(medicineName);
ASSERT_NE(recipe, nullptr);  // Рецепт должен быть найден

// Проверим, что медицинская история обновлена
auto medicalHistory = patient->retrieveMedicalRecord()->fetchMedicalHistory();
bool prescriptionFound = false;
for (const auto& record : medicalHistory) {
if (record == "Prescription issued for Aspirin") {
prescriptionFound = true;
break;
}
}

ASSERT_TRUE(prescriptionFound);  // В медицинской истории должна быть запись о назначении лекарства
}
