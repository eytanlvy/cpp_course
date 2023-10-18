#include "TimeStamp.hpp"

Timestamp::Timestamp(int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0)
	{
		throw std::invalid_argument("Hours, minutes, and seconds must be non-negative.");
	}
	int sum = a * 3600 + b * 60 + c;
	setHour(sum / 3600);
	int mod = sum % 3600;
	setMinute(mod / 60);
	int rest = mod % 60;
	setSecond(rest);
}

int Timestamp::getHour() const{
	return hour;
}

int Timestamp::getMinute() const{
	return minute;
}

int Timestamp::getSecond() const{
	return second;
}

void Timestamp::setHour(int h) {
	if (h >= 0 && h < 24) {
		hour = h;
	} else {
		throw std::invalid_argument("Hour should be >=0 and <24");
	}
}

void Timestamp::setMinute(int m) {
	if (m >= 0 && m < 60) {
		minute = m;
	} else {
		throw std::invalid_argument("Minute should be >=0 and <60");
	}
}

void Timestamp::setSecond(int s) {
	if (s >= 0 && s < 60) {
		second = s;
	} else {
		throw std::invalid_argument("Second should be >=0 and <60");
	}
}

int main() {
    int hours, minutes, seconds;

    std::cout << "Enter hours: ";
    std::cin >> hours;
    
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    
    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    Timestamp timestamp(hours, minutes, seconds);

    std::cout << "Timestamp created:" << std::endl;
    std::cout << "Hours: " << timestamp.getHour() << std::endl;
    std::cout << "Minutes: " << timestamp.getMinute() << std::endl;
    std::cout << "Seconds: " << timestamp.getSecond() << std::endl;

    return 0;
}
