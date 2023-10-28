#ifndef FILEREADER_H
#define FILEREADER_H

class FileReader {
    public:
        FileReader();
        void readfileData(std::vector<std::string>& fileData);
        int getN();
        int getK();
        int getQ();
        int getL();
        int getR();
        std::vector<int> getP();
        std::vector<int> getD();
        std::vector<std::vector<int>> getC();
    private:
        
        int n,k,Q,L,r;
        std::vector<int> p;
        std::vector<int> v;
        std::vector<std::vector> c;
        std::vector<int> readArray();
};

#endif
