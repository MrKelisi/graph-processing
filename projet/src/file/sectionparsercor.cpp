#include "sectionparsercor.h"
#include "parseexception.h"
#include "gprparser.h"
#include "../util/string.h"

SectionParserCOR::SectionParserCOR(const std::string& sectionName, SectionParserCOR* next) :
        SectionParser(sectionName),
        _next(next) {

}

SectionParserCOR::~SectionParserCOR() {

}

bool SectionParserCOR::canParse(const std::string& name) const {
    return compareCaseInsensitive(sectionName(), name);
}

void SectionParserCOR::parse(std::istream& is, GPRParser* parser) {
    std::streampos position = is.tellg();
    std::string line;

    do {
        if (!std::getline(is, line)) {
            return;
        }
        GPRParser::cleanLine(line);
    } while(line.empty());

    if(!canParse(line)) {
        if(_next) {
            is.seekg(position);
            return _next->parse(is, parser);
        }
        else {
            throw ParseException(("Impossible de traiter la ligne " + line).c_str());
        }
    }

    while(parseInternal(line, parser)) {
        position = is.tellg();
        if(!std::getline(is, line)) {
            return;
        }

        GPRParser::cleanLine(line);
    }

    is.seekg(position);
}
