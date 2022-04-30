#include "filetool.h"
#include <fstream>
#include <filesystem>
#include <sstream>


#include <openssl/md5.h>

namespace tools{
    bool ReadFile(const std::string & file_name,std::vector<char> & data)
    {
        std::ifstream f(file_name,std::ios_base::in | std::ios_base::binary);
        if(f.is_open()){
            f.seekg(0,std::ios_base::end);
            auto size =  f.tellg();
            data.resize(size);
            f.seekg(0,std::ios_base::beg);
            f.read(data.data(),size);
            f.close();
            return true;
        }
        else {
            return false;
        }
    }

    std::vector<std::string> GetFileNameListNoPath(const std::string & path,const std::string & extension)
    {
        std::vector<std::string> paths;
        for(auto & p : std::filesystem::directory_iterator(path)){
            auto ext = p.path().extension().string();
            if(p.path().extension().string()  == extension){
                paths.push_back(p.path().filename().string());
            }
        }
        return paths;
    }

    std::string CalcFileMd5(const std::string & file_name)
    {
        std::ifstream file(file_name,std::ifstream::binary);

        MD5_CTX md5Context;
        MD5_Init(&md5Context);
        char buf[1024 * 16];
        while (file.good()) {
            file.read(buf, sizeof(buf));
            MD5_Update(&md5Context, buf, file.gcount());
        }
        unsigned char result[MD5_DIGEST_LENGTH];
        MD5_Final(result, &md5Context);

        char hex[35] = {0};
        for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
        {
            sprintf(hex + i * 2, "%02x", result[i]);
        }
        hex[32] = '\0';
        return std::string(hex);
    }

    uint64_t GetFolderFileSize(const std::string & path)
    {
        uint64_t r = 0.0;
        if (!std::filesystem::is_directory(path))
            r += (double)std::filesystem::file_size(path);
        else
            for(auto entry: std::filesystem::directory_iterator(path))
                GetFolderFileSize(entry.path().string());
        return r;
    }
}