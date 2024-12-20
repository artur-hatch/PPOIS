#include <gtest/gtest.h>
#include "../include/Chamber.h"
#include "../include/Client.h"
#include "../include/CustomDate.h"
#include "../include/Doctor.h"
#include "../include/DocumentSignature.h"
#include "../include/Employee.h"
#include "../include/FullName.h"
#include "../include/HealthProfessional.h"
#include "../include/IDCard.h"
#include "../include/Identity.h"
#include "../include/Individual.h"
#include "../include/MedicalRecord.h"
#include "../include/Recipe.h"



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}