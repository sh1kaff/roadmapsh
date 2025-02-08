#include "task.h"
#include <chrono>

size_t now() {
    return std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

// добавить: функция для поиска по id


void TasksList::addTask(std::string description) {
    Task task;

    task.description = description;
    task.createdAt = task.updatedAt = now();

    size_t id = 0;
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i].id - id > 0) {
            id = list[i].id - 1;
            break;
        } else {
            ++id;
        }
    }
    task.id = id;

    list.push_back(task);
}


void TasksList::editTask(size_t id, std::string description) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (id == list[i].id) {
            
            list[i].description = description;
            list[i].updatedAt = now();

            return;
        }
    }

    // error out
}

void TasksList::delTask(size_t id) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (id == list[i].id) {

            list.erase(list.begin() + i);

            return;
        }
    }

    // error out
}

void TasksList::markStatus(size_t id, Status status) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (id == list[i].id) {

            list[i].status = status;
            
            return;
        }
    }

    // error_out
}



void TasksList::printByStatus(Status status) {
    if (status == Status::ANY) {
        std::cout << *this;
        return;
    }

    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i].status != status) continue;

        std::cout << list[i] << "\n";
    }
}


std::ostream& operator<<(std::ostream& os, const Status& status) {
    switch (status) {
        case Status::DONE: os << "done";
            break;
        case Status::INPROGRESS: os << "in-progress";
            break;
        case Status::TODO: os << "todo";
            break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "[" << task.id << "] ";
    os << "\"" << task.description << "\" ";
    os << "-- " << task.status;

    return os;
}

std::ostream& operator<<(std::ostream& os, const TasksList& list) {
    size_t list_size = list.list.size();

    for (size_t i = 0; i < list_size; ++i) {
        os << list.list[i] << "\n";
    }

    return os;
}