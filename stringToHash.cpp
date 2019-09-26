#include <iostream>
#include <string>     // std::string, std::to_string
#include <sstream>
#include <cmath>

using namespace std;

bool isValidAsci(int);
int getAsciNumber(int, int);
string stringToHash(string, int = 24);

int validAsciCodes[] {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102, 103, 104, 106, 107, 108};

int main(int argc,char* argv[])
{
    for (size_t i = 1; i < argc; i++) {
        cout << stringToHash(argv[i], 5) << endl;
    }

    return 0;
}

string stringToHash(string input, int hashSize) {

    if (input.size() == 0) {
        throw "Input'as tuscias";
    }
    long int sum = (char)input[0];

    int index = 0;
    for (auto c : input)
    {
        int code = (int)c;
        int processedCode = code + (index ^ (code * 2));
        sum = abs(processedCode + sum);
        index += 1;
    }

    ostringstream os;
    string numbers= "";


    while (os.str().size() < hashSize) {
        int number = sum ^ (sum / hashSize * (os.str().size()+1));
        cout << sum << " " << number << endl;
        os << number;
    }

    string numbersString = os.str();

    ostringstream oss;

    int lastNumber = 0;

    for (auto number : numbersString){
        int val = number - '0';
        oss << char(getAsciNumber(val, lastNumber));

        lastNumber = val;
    }

    return oss.str();
}

int getAsciNumber(int number, int lastNumber) {
     return validAsciCodes[number+lastNumber];
}
