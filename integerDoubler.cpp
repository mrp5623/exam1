#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

void integerDoubler(std::string inputFile, std::string outputFile){
    std::ifstream input(inputFile, std::ios::binary);
    std::vector<int32_t> doubled;

    while (!input.eof()&&!input.fail()){
        int32_t n;
        input.read(reinterpret_cast<char*>(&n), sizeof(n));
        doubled.push_back(n);
    }
    doubled.pop_back();

    input.close();

    std::ofstream output(outputFile, std::ios::binary);


    for (int32_t num : doubled){
        num*=2;
        output.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    
    
}