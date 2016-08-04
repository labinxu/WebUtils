#include "dictyoudao.h"
#include "utils/stringutil.h"
#include "log.h"
#include "tinyhtml.h"
using namespace TinyHTML;
using namespace std;
bool DictYouDao::login(const std::string&user, const std::string &passwd){

}
void DictYouDao::logout(){

}
DictYouDao::DictYouDao(const std::string &name, const std::string &url)
:Site(name,url),
_wordUrl("http://dict.youdao.com/w/"),
_sentenceUrl("http://fanyi.youdao.com/")
{
    
}
std::string DictYouDao::more()
{
    return _moreContent;
}
std::string DictYouDao::parse(const std::string &data)
{
    assert(data.empty());
    HTML *html = new HTML(data);
    std::string result;
    auto tinyTag = html->find("div", {{"id","phrsListTab"}, {"class", "trans-wrapper clearfix"}});
    if(tinyTag){
        auto spans = tinyTag->findAll("span", {{"class", "pronounce"}});
        for(auto span: spans){
            result += span->getValue();
            result += ":";
            auto phonetic = span->find("span",{{"class","phonetic"}});
            result += phonetic->getContentText();
            result += " ";
        }
        result+="\n";
        LOGD("pronounce %s\n", result.c_str());  
        auto lis = tinyTag->findAll("li");
        for(auto li: lis){
            result+=li->getContentText()+'\n';
        }
        
        // parse the more info
        
    }
    else
    {
        tinyTag = html->find("div", {{"class", "error-typo"}});
        if(tinyTag){
            auto h4Tag = tinyTag->find("h4");
            result+=h4Tag->getContentText()+"\n";
            if(h4Tag)
            {
                auto tags = tinyTag->findAll("a");
                for(auto tag: tags){
                    result+=tag->getContentText()+"\n";
                }
            }
        }
    }
    
    return result;
}

std::string DictYouDao::composeUrl(std::string data){
	LOGD("composeUrl %s\n", data.c_str());  
	data = trim(data);
	LOGD("composeUrl trimed %s\n", data.c_str());  
	auto pos = data.find(' ');
	if(pos != -1)
	{
		return _sentenceUrl;
	}
	LOGD("composeUrl URL %s\n", std::string(_wordUrl+data).c_str());   
	return _wordUrl+data;
}