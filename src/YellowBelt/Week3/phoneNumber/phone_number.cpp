#include "phone_number.h"
#include <regex>
#include <sstream>

const regex numberFormatRegexp("[+]([a-zA-Z0-9]{1,3})[-]([a-zA-Z0-9]{1,3})[-](.+)");

PhoneNumber::PhoneNumber(const string &international_number) {
    if (!regex_match(international_number, regex(numberFormatRegexp))) {
        throw invalid_argument("Invalid international format number!");
    }

    smatch data;
    regex_match(international_number, data, numberFormatRegexp);

    country_code_ = data[1];
    city_code_ = data[2];
    local_number_ = data[3];
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    stringstream result;
    result << '+' << country_code_ << '-' << city_code_ << '-' << local_number_;
    return result.str();
}

