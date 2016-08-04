#include "sitemanager.h"
#include "log.h"
#include "dictyoudao.h"
using namespace std;

SiteManager* SiteManager::_instance = nullptr;

SiteManager::SiteManager(){
	init();
}

SiteManager *SiteManager::Instance()
{
    if(SiteManager::_instance == nullptr)
        SiteManager::_instance =  new SiteManager();
    return SiteManager::_instance;
}
bool SiteManager::init()
{
	return true;
}
std::shared_ptr<Site> SiteManager::site()
{
	return std::shared_ptr<Site>(new DictYouDao("youdao", "http://dict.youdao.com"));
}
std::string SiteManager::getPage()
{
	
}
bool SiteManager::openSite(std::shared_ptr<Site> site){
    string username = "";
    string passwd = "";
    if(!site->login(username, passwd))
    {
        LOGE("Login %s failed!\n", site->getName().c_str());
        return false;
    }
    
    
    // get video content
    //TODO:
    
    
    // play
    //TODO:
    
    
}