#ifndef SITE_H
#define SITE_H
#include <string>
#include <assert.h>
#include <memory>
#include "siteconf.h"

class CHttpClient;
class Site
{
    public:
        Site(const std::string &name, const std::string &url);
        
        std::string getName() const;
        std::string getUrl() const;
        std::string getMainPage();
        std::string setName(const std::string &name);
        std::string setUrl(const std::string &url);
        std::string getPage(const std::string &url);
    public:
        virtual bool init();
        virtual std::string composeUrl(std::string data){return "";};
        virtual bool login(const std::string&user, const std::string &passwd){return false;};
        virtual void logout(){};
        virtual std::string parse(const std::string &data){return "";};
        virtual std::string more(){return "";};
        
    private:
        std::string _name;
        std::string _url;
        SiteConf *_siteConf;
        std::shared_ptr<CHttpClient> _httpClient;
};


#endif