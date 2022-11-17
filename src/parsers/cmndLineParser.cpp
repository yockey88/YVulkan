#include "parsers/cmndLineParser.hpp"

#include <iostream>

namespace machy::util::parsers {

    void CmndLineParser::Read(const int& argc , char* argv[]) {
        for (int i = 0; i < argc; i++) 
            cmnds.push_back(std::string(argv[i]));
    }

    const std::string& CmndLineParser::getCmndOption(const std::string& option) {
        std::vector<std::string>::const_iterator itr;
        itr = std::find(cmnds.begin() , cmnds.end() , option);
        if (itr != cmnds.end() && ++itr != cmnds.end()) 
            return *itr;
        
        static const std::string empty_string("");
        
        return empty_string;
    }

    bool CmndLineParser::cmndOptionExists(const std::string& option) {
        return (std::find(cmnds.begin() , cmnds.end() , option) != cmnds.end());
    }

    void CmndLineParser::PrintOptions() {
        
        for (int i = 0; i < cmnds.size(); i++)
            std::cout << cmnds[i] << std::endl;

        return;
    }

}