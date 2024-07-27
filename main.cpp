#include <iostream>
#include <string>
#include <cstring>

extern "C" char sample_code[];
extern "C" std::uint32_t sample_code_size;

int main() {
    std::cout << "address: " << reinterpret_cast<void*>(sample_code) << std::endl;
    char* buf = (char*)std::malloc(sample_code_size);

    // SEGV
    std::memcpy(buf, sample_code, sample_code_size);
    
    std::cout << "size: " << std::strlen(buf) << std::endl;
    std::cout << "head: " << std::string(buf, buf + 10) << std::endl;
    std::cout << "tail: " << std::string(buf + sample_code_size - 11, buf + sample_code_size - 1) << std::endl;
}
