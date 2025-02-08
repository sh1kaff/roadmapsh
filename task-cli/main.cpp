#include <iostream>
#include "task.h"
#include "json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
 
int main() {
    std::string Data = R"({ "name": "Alex", "role": "admin" })";

    json Doc = json::parse(Data);

    std::cout << Doc["name"];
}
