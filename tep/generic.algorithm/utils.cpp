#include <random>
#include <sstream>

using namespace std;

bool generateRandomBool() {
    std::random_device randomDevice;
    std::mt19937 generate(randomDevice());
    std::uniform_int_distribution<> range(0, 1);
    return range(generate);
}

int generateInt(int from, int to){
    std::random_device randomDevice;
    std::mt19937 generate(randomDevice());
    std::uniform_int_distribution<> range(from, to);
    return range(generate);
}

vector<double> convertToVector(const string& stringToConvert) {
    vector<double> temp;
    vector<string> numbers;
    string token;
    istringstream token_stream(stringToConvert);

    while (getline(token_stream, token, ','))
        numbers.push_back(token);

    for(int i = 0; i < numbers.size(); i++)
        temp.push_back(stod(numbers[i]));

    return temp;
}

#include "utils.h"
