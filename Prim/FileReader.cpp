#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include "fileReader.h"

using namespace std;

FileReader::FileReader(string filename){
    this->filename = filename;
}

void FileReader::readfileData() {
    
    ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo" << std::endl;
        return;
    }

    //variaveis

    file >> n >> k >> Q >> L >> r;

    // array p
    p = readArray(file);
    // array d
    d = readArray(file);

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

    c = matrix;

    file.close();
}


vector<int> FileReader::readArray(ifstream& file)
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
    return array;
}

int FileReader::getN(){return n;}

int FileReader::getK(){return k;}

int FileReader::getQ(){return Q;}

int FileReader::getL(){return L;}

int FileReader::getR(){return r;}

vector<int> FileReader::getP(){return p;}

vector<int> FileReader::getD(){return d;}

vector<vector<int>> FileReader::getC(){return c;}
