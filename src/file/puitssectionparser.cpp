#include <iostream>
#include "puitssectionparser.h"

PuitsSectionParser::PuitsSectionParser(SectionParserCOR* next) :
        SectionParserCOR("puits", next) {

}

bool PuitsSectionParser::parseInternal(const std::string& line, GPRParser* parser) {
    if(canParse(line)) {
        return true;
    }

    if(line.empty()) {
        return false;
    }

    std::cout << "Puits trouvée : " << line.substr(0, line.find(' ')) << std::endl;
}
