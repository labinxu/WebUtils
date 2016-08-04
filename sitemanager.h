#ifndef CURL_ADAPTER_H
#define CURL_ADAPTER_H

#include <vector>
#include <memory>
#include "site.h"
class SiteManager
{
    private:
        SiteManager();
    public:
        bool openSite(std::shared_ptr<Site> site);
        static SiteManager *Instance();
		std::string getPage();
		std::shared_ptr<Site> site();
    private:
		bool init();
        std::vector<std::shared_ptr<Site>> _sites;
        static SiteManager *_instance;
};
#endif