#include <string>
#include <fstream>

#include "TruncateFile.h"

void truncateFile(const std::string& filename) {
    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}