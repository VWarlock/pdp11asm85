#include "fstools.h"
#include <fstream>
#include <limits>
#include <stdexcept>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

void saveStringToFile(const char* fileName2, const void* buf, size_t len)
{
    std::ofstream file;
    file.open(fileName2);
    if(!file.is_open()) throw std::runtime_error("Can't create lst file");
    file.write((const char*)buf, len);
}

//-----------------------------------------------------------------------------

void loadStringFromFile(std::string& buf, const char* fileName) {
    std::fstream file(fileName, std::ifstream::in|std::ifstream::binary);
    if(!file.is_open()) throw std::runtime_error("Can't open source file");
    std::streamoff size = file.rdbuf()->pubseekoff(0, std::fstream::end);
    if(size < 0 || size >= SIZE_MAX) throw std::runtime_error("Source file too large");
    buf.resize((size_t)size);
    file.rdbuf()->pubseekoff(0, std::fstream::beg);
    file.rdbuf()->sgetn(const_cast<char*>(buf.c_str()), buf.size());
}

//-----------------------------------------------------------------------------

void chdirToFile(const char* fileName) {
    const char *a = strrchr(fileName, '/');
    if(a) chdir(std::string(fileName, a-fileName).c_str()); //! Код ошибки
}

//-----------------------------------------------------------------------------

std::string replaceExtension(const std::string& fileName, const char* ext) {
    size_t s = fileName.rfind('.');
    if(s==std::string::npos || fileName.find('/', s)!=std::string::npos || fileName.find('\\', s)!=std::string::npos) return fileName;
    return fileName.substr(0,s+1) + ext;
}

