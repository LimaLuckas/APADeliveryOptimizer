#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include "FileReader.h"
#include "fileReader.h"

using namespace std;

FileReader::FileReader(){}

void FileReader::readfileData(vector<string>& fileData) {
    ifstream file("your_file.txt");

    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    //variaveis

    file >> this.n >> this.k >> this.Q >> this.L >> this.r;

    // array p
    this.p = readArray();
    // array d
    this.d = readArray();

    //matriz
    vector<vector<int>> matrix;
    string line;
    while (std::getline(file, line)) {
        istringstream lineStream(line);
        vector<int> row;
        int value;
        while (lineStream >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    this.c = matrix;

    file.close();
}


vector<int> FileReader::readArray()
{
    std::string arrayLine;
    std::getline(file, arrayLine);
    std::getline(file, arrayLine);
    std::istringstream arrayStream(arrayLine);
    std::vector<int> array;
    int arrayElement;
    while (arrayStream >> arrayElement) {
        array.push_back(arrayElement);
    }

}

int FileReader::getN(){return this.n}

int FileReader::getK(){return this.k}

int FileReader::getQ(){return this.Q}

int FileReader::getL(){return this.L}

int FileReader::getR(){return this.r}

vector<int> FileReader::getP(){return this.p}

vector<int> FileReader::getD(){return this.d}

vector<vector<int>> FileReader::getC(){return this.c}
