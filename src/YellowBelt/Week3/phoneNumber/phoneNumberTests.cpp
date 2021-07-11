#include "phone_number.h"
#include "test_runner.h"

void generalTest1() {
    string expectedInternationalNumber = "+7-495-111-22-33";
    string expectedCountryCode = "7";
    string expectedCityCode = "495";
    string expectedLocalNumber = "111-22-33";

    PhoneNumber phoneNumber(expectedInternationalNumber);

    AssertEqual(phoneNumber.GetInternationalNumber(), expectedInternationalNumber);
    AssertEqual(phoneNumber.GetCountryCode(), expectedCountryCode);
    AssertEqual(phoneNumber.GetCityCode(), expectedCityCode);
    AssertEqual(phoneNumber.GetLocalNumber(), expectedLocalNumber);
}

void generalTest2() {
    string expectedInternationalNumber = "+XXX-YYY-ZZZZZZ";
    string expectedCountryCode = "XXX";
    string expectedCityCode = "YYY";
    string expectedLocalNumber = "ZZZZZZ";

    PhoneNumber phoneNumber(expectedInternationalNumber);

    AssertEqual(phoneNumber.GetInternationalNumber(), expectedInternationalNumber);
    AssertEqual(phoneNumber.GetCountryCode(), expectedCountryCode);
    AssertEqual(phoneNumber.GetCityCode(), expectedCityCode);
    AssertEqual(phoneNumber.GetLocalNumber(), expectedLocalNumber);
}

void generalTest3() {
    string expectedInternationalNumber = "+1-2-3";
    string expectedCountryCode = "1";
    string expectedCityCode = "2";
    string expectedLocalNumber = "3";

    PhoneNumber phoneNumber(expectedInternationalNumber);

    AssertEqual(phoneNumber.GetInternationalNumber(), expectedInternationalNumber);
    AssertEqual(phoneNumber.GetCountryCode(), expectedCountryCode);
    AssertEqual(phoneNumber.GetCityCode(), expectedCityCode);
    AssertEqual(phoneNumber.GetLocalNumber(), expectedLocalNumber);
}

void generalTest4() {
    string expectedInternationalNumber = "+1-2-coursera-cpp";
    string expectedCountryCode = "1";
    string expectedCityCode = "2";
    string expectedLocalNumber = "coursera-cpp";

    PhoneNumber phoneNumber(expectedInternationalNumber);

    AssertEqual(phoneNumber.GetInternationalNumber(), expectedInternationalNumber);
    AssertEqual(phoneNumber.GetCountryCode(), expectedCountryCode);
    AssertEqual(phoneNumber.GetCityCode(), expectedCityCode);
    AssertEqual(phoneNumber.GetLocalNumber(), expectedLocalNumber);
}

void shouldFailOnInvalidData1() {
    string invalidInternationaNumber = "1-2-333";

    try {
        PhoneNumber phoneNumber(invalidInternationaNumber);
        fail("Constructor does not throw an exception on invalid data!");
    } catch (const invalid_argument& err) {
    }
}

void shouldFailOnInvalidData2() {
    string invalidInternationaNumber = "+7-1233";

    try {
        PhoneNumber phoneNumber(invalidInternationaNumber);
        fail("Constructor does not throw an exception on invalid data!");
    } catch (const invalid_argument& err) {
    }
}


int main() {
    TestRunner testRunner;
    testRunner.RunTest(generalTest1, "generalTest1");
    testRunner.RunTest(generalTest2, "generalTest2");
    testRunner.RunTest(generalTest3, "generalTest3");
    testRunner.RunTest(generalTest4, "generalTest4");
    testRunner.RunTest(shouldFailOnInvalidData1, "shouldFailOnInvalidData1");
    testRunner.RunTest(shouldFailOnInvalidData2, "shouldFailOnInvalidData2");
}
