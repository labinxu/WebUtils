 #include "stringutil.h"
 std::string& trim(std::string& text)
 {  
        if(!text.empty())  
        {  
            text.erase(0, text.find_first_not_of(" \n\r\t"));  
            text.erase(text.find_last_not_of(" \n\r\t") + 1);  
        }  
        return text;  
  } 
