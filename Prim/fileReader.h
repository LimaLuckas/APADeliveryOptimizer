#include <fstream>
#include <sstream>
#ifndef FILEREADER_H
#define FILEREADER_H

class FileReader {
    public:
        FileReader(std::string filename);
        void readfileData();
        int getN();
        int getK();
        int getQ();
        int getL();
        int getR();
        std::vector<int> getP();
        std::vector<int> getD();
        std::vector<std::vector<int>> getC();
    private:

        std::string filename;
        int n,k,Q,L,r;
        std::vector<int> p;
        std::vector<int> d;
        std::vector<std::vector<int>> c;
        std::vector<int> readArray(std::ifstream& file);
};

#endif