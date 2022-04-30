#include <vector>
#include <string>
namespace tools{
    bool ReadFile(const std::string & file_name,std::vector<char> & data);
    std::vector<std::string> GetFileNameListNoPath(const std::string & path,const std::string & extension);
    std::string CalcFileMd5(const std::string & file_name);
    uint64_t GetFolderFileSize(const std::string & path);
}