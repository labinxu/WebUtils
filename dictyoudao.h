#ifndef DICT_YOUDAO_H
#define DICT_YOUDAO_H
#include "site.h"

class DictYouDao : public Site
{
    public:
        DictYouDao(const std::string &name, const std::string &url);
        std::string parse(const std::string &data) override;
        std::string composeUrl(std::string data) override;
        bool login(const std::string&user, const std::string &passwd) override;
        void logout() override;
        std::string more();
    private:
        std::string _wordUrl;
        std::string _sentenceUrl;
        std::string _moreContent;
};
#endif //BAIDUYUN_H