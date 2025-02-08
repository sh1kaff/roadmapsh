#include <iostream>
#include "task.h"
#include "json.hpp"

 
int main() {
    int a;

    TasksList list;

    list.addTask(std::string("First"));
    list.addTask(std::string("Second"));
    list.addTask(std::string("Third"));
    list.addTask(std::string("Fourth"));

    std::cin >> a;

    list.markStatus(3, Status::DONE);
    list.editTask(1, std::string("Second Edit"));

    std::cout << list << "\n";

    std::cin >> a;

    list.delTask(2);

    std::cout << list << "\n";

    list.addTask(std::string("some"));

    list.printByStatus(Status::ANY);
}
