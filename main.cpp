#include <iostream>
#include <fstream>

int main()
{
    unsigned int n;
    int num = 1;
    int tmp;
    std::cout << "Enter n ";
    std::cin >> n;
    std::ofstream output ("output.bin", std::ios::out |  std::ios::binary);
    for (int i = 0; i <= n; i++)
    {
        output.write(reinterpret_cast<const char *>(&num), sizeof num);
        num = num * 2;
    }
    output.close();
    std::ifstream input ("output.bin", std::ios::binary | std::ios::ate);
    int sizeoffile = input.tellg();
    input.seekg(0, std::ios::beg);
    while (input.tellg() < sizeoffile)
    {
        input.read(reinterpret_cast<char *>(&num), sizeof num) ;
        std::cout << num << " ";
    }
    input.close();
    return 0;
}
