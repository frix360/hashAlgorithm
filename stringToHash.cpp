#include <iostream>
#include <string>     // std::string, std::to_string
#include <sstream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <time.h>       /* time */
#include <bitset>

using namespace std;

void generateTestFiles();

int getAsciNumber(int, int);

string stringToHash(const string &input, int hashSize = 64);

void readFromFilesAndTest();

string getFileString(ifstream &stream);

void displayHashedStringFromFile(ifstream &stream);

unsigned long stringToNumberHash(const std::string &str);

int validAsciCodes[]{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102, 103, 104, 106, 107, 108};

class StringPair {
private:
    void generateSimilarPair() {
        ostringstream str1Stream;
        ostringstream str2Stream;
        for (int i = 0; i < 5; i++) {

            char letterStr1 = 'a' + rand() % 26; // Get random letter

            str1Stream << letterStr1;

        }

        str1 = str1Stream.str();
        str2 = str1;

        str2[0] = 'a' + rand() % 26;
    }

    void generatePair() {
        ostringstream str1Stream;
        ostringstream str2Stream;
        for (int i = 0; i < 5; i++) {

            char letterStr1 = 'a' + rand() % 26; // Get random letter
            char letterStr2 = 'a' + rand() % 26; // Get random letter

            str1Stream << letterStr1;
            str2Stream << letterStr2;
        }

        str1 = str1Stream.str();
        str2 = str2Stream.str();
    }

    string stringToBin(const std::string &a) {
        string binaryString;

        for (char _char : a) {
            binaryString += std::bitset<8>(_char).to_string();
        }
        return binaryString;
    }

public:
    string str1 = "";
    string str2 = "";


    string hashedStr1 = "";
    string hashedStr2 = "";

    StringPair(bool similar = false) {

        while (str1 == str2) {
            if (similar) {
                generateSimilarPair();
            } else {
                generatePair();
            }

        }

        hashPair();


    }


    double bitComparePercentage() {
        double ratio = 0;
        std::string aBin = stringToBin(hashedStr1);
        std::string bBin = stringToBin(hashedStr2);
        for (int i = 0; i < aBin.length(); i++) {
            if (aBin[i] != bBin[i])
                ratio++;
        }
        return ratio / aBin.length() * 100;

    }

    bool areEqual() {
        return hashedStr1 == hashedStr2;
    }

    void hashPair() {
        hashedStr1 = stringToHash(str1);
        hashedStr2 = stringToHash(str2);
    }

    void print() {
        cout << str1 << " " << str2 << endl;
    }

};

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};


long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(int argc, char *argv[]) {
    // cout << stringToHash("Lietuva") << endl << stringToHash("lietuva") << endl << stringToHash("lietuvą");
    //return 0;
    srand(time(NULL));
    generateTestFiles();
    readFromFilesAndTest();

    return 0;
}

unsigned long stringToNumberHash(const std::string &str) {
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned long hash = 0;

    for (std::size_t i = 0; i < str.length(); i++) {
        hash = hash * a + str[i];
        a = a * b;
    }
    return hash;
}

string stringToHash(const string &input, int hashSize) {
    unsigned long long intHash = stringToNumberHash(input);

    string numbersString = to_string(intHash);

    while (numbersString.size() <= hashSize) {
        intHash += (numbersString.size() * intHash);
        numbersString += to_string(intHash);
    }

    numbersString = numbersString.substr(0, hashSize); // limit the size of the string

    ostringstream oss;

    int lastNumber = 0;

    for (auto number : numbersString) {
        int val = number - '0';
        oss << char(getAsciNumber(val, lastNumber));

        lastNumber = val;
    }

    return oss.str();
}

int getAsciNumber(int number, int lastNumber) {
    return validAsciCodes[number + lastNumber];
}

void generateTestFiles() {

    int fileIndex = 1;

    for (int i = 1; i <= 2; i++) {
        ofstream oneLetterFile("oneLetterFile-" + to_string(i) + ".txt");
        fileIndex++;

        char letter = 'a' + rand() % 26; // Get random letter
        for (int i = 0; i <= 10000; i++) {

            oneLetterFile << letter;
        }

        ofstream differentLettersFile("differentLettersFile-" + to_string(i) + ".txt");
        fileIndex++;

        for (int i = 0; i <= 10000; i++) {
            char letter = 'a' + rand() % 26; // Get random letter
            differentLettersFile << letter;
        }
    }

    ofstream firstSimilarFile("firstSimilarFile.txt");
    ofstream secondSimilarFile("secondSimilarFile.txt");

    for (int i = 0; i <= 10000; i++) {
        char letter = 'a' + rand() % 26; // Get random letter
        firstSimilarFile << letter;
        if (i == 1000) {
            secondSimilarFile << 1;
        } else {
            secondSimilarFile << letter;
        }
    }

    ofstream emptyFile("emptyFile.txt");
    emptyFile << " ";
}

string getFileString(ifstream &stream) {
    string sLine;

    while (!stream.eof()) {
        stream >> sLine;
    }

    return sLine;
}

void displayHashedStringFromFile(ifstream &stream) {
    cout << stringToHash(getFileString(stream)) << endl;
}

void readFromFilesAndTest() {

    for (int i = 1; i <= 2; i++) {
        ifstream oneLetterFile("oneLetterFile-" + to_string(i) + ".txt");
        displayHashedStringFromFile(oneLetterFile);

        ifstream differentLettersFile("differentLettersFile-" + to_string(i) + ".txt");
        displayHashedStringFromFile(differentLettersFile);
    }

    ifstream firstSimilarFile("firstSimilarFile.txt");
    displayHashedStringFromFile(firstSimilarFile);

    ifstream secondSimilarFile("secondSimilarFile.txt");
    displayHashedStringFromFile(secondSimilarFile);

    ifstream constitutionFile("konstitucija.txt");

    Timer timer;

    double hashTime = 0;

    for (std::string strToHash; getline(constitutionFile, strToHash);) {
        timer.reset();

        string stringHash = stringToHash(strToHash);

        hashTime += timer.elapsed();
    }

    cout << "Failo konstitucija.txt eiluciu hashavimo laikas: " + to_string(hashTime) << endl << endl;

    int repeats = 0;
    for (int i = 0; i < 1000000; i++) {
        StringPair strPair;

        if (strPair.areEqual()) {
            repeats++;
        }

    }

    cout << "Rasta " << repeats << " pasikartojimu" << endl;

    double sum = 0;
    double maxPerc = -100000;
    double minPerc = 100000;
    for (int i = 0; i < 100000; i++) {
        StringPair strPair(true);
        double perc = strPair.bitComparePercentage();

        if (perc > maxPerc) {
            maxPerc = perc;
        }

        if (perc < minPerc) {
            minPerc = perc;
        }

        sum += perc;
    }

    cout << "Vidutinis panasumo procentas: " << sum / 100000 << "%" << endl;
    cout << "Min panasumo procentas: " << minPerc << "%" << endl;
    cout << "Max panasumo procentas: " << maxPerc << "%" << endl;
}
