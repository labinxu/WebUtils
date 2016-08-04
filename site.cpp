#include "site.h"
#include "sitemanager.h"
#include "httpclient.h"
using namespace std;
Site::Site(const std::string &name, const std::string &url)
    :_name(name),
    _httpClient(new CHttpClient()), 
    _url(url), 
    _siteConf(nullptr){
    
    //_httpClient->SetDebug(true);

}
bool Site::init()
{
    return true;
}
std::string Site::getName() const
{
    return _name;
}

std::string Site::getUrl() const{
    return _url;
}

std::string Site::setName(const std::string &name){
    _name = name;
}
std::string Site::setUrl(const std::string &url){
    _url = url;
}
std::string Site::getMainPage()
{
    assert(_url.empty());
    string content;
    auto ret = _httpClient->Get(_url, content);
    if(ret != 0)
    {
        LOGE("GET %s failed" , _url.c_str());
    }
    return content;
}

std::string Site::getPage(const std::string &url){
    assert(url.empty());
    assert(_httpClient != nullptr);
    string content;
    auto ret = _httpClient->Get(url, content);
    //LOGD("received data is: %s", content.c_str());
    
    return content;
}