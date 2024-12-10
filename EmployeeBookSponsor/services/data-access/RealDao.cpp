#include "RealDao.h"

#include <fstream>
#include <iostream>
#include <string>
#include <format>
using namespace std;

#include "../business/ParserFactory.h"
#include "../business/IParsable.h"


std::vector<std::shared_ptr<Proposal>> RealDao::getAll() {
    std::vector<std::shared_ptr<Proposal>> projects;

    std::string input = "data/May2024Proposals.txt";
    ifstream reader;
    reader.open(input, ios::in);

    if (!reader.good()) {
        cout << "File not found\n";
        return projects;
    }

    std::string line = "";

    while (!reader.eof()) {
        getline(reader, line);

        if (line == "\n" || line == "") {
            continue;
        }

        if (line.find("=>") != std::string::npos) {
            line.erase(0, line.find("=>") + 3);
        }
        
        // 1. Trích xuất từ đầu tiên
        std::string type = _firstWord(line);

        // 2. Dựa trên từ đầu tiên, lựa chọn parser tương ứng
        std::shared_ptr<IParsable> parser = nullptr;
        parser = dynamic_pointer_cast<IParsable>(ParserFactory::getServiceForType(type));

        // 3. Parse dòng thành hình
        if (parser != nullptr) {
            std::shared_ptr<Proposal> project = dynamic_pointer_cast<Proposal> (parser->parse(line));

            // 4. Đưa hình đã parse vào mảng
            projects.push_back(project);
        }        
    }

    reader.close();
    return projects;
}

std::string RealDao::_firstWord(std::string line) {
    size_t pos = line.find(':');
    if (pos != std::string::npos) {
        return line.substr(0, pos);
    }
    return line;
}