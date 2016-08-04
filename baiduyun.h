#ifndef BAIDUYUN_H
#define BAIDUYUN_H
#include "site.h"

class BaiduYun : public Site
{
    public:
        
        BaiduYun(const std::string &name, const std::string url);
        bool login();
        void logout();
};
#endif //BAIDUYUN_H