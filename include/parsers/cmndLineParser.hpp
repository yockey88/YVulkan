#ifndef CMND_LINE_PARSER_HPP
#define CMND_LINE_PARSER_HPP

#include <string>
#include <vector>

namespace machy {
namespace util {
namespace parsers {

    class CmndLineParser {
        std::vector<std::string> cmnds;

        public:
            CmndLineParser() {}
            ~CmndLineParser() {}

            void Read(const int& argc , char* argv[]);

            const std::string& getCmndOption(const std::string& option);
            bool cmndOptionExists(const std::string& option);

            void PrintOptions();
    };

}
} 
}

#endif