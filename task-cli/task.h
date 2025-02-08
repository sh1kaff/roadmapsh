#include <string>
#include <vector>
#include <iostream>

enum class Status {TODO, INPROGRESS, DONE, ANY};

struct Task {
    size_t id { 0 };
    std::string description { std::string() };
    Status status { Status::TODO };
    size_t createdAt { 0 };
    size_t updatedAt { 0 };
};

std::ostream& operator<<(std::ostream& os, const Task& task);

class TasksList {
public:
    std::vector<Task> list { std::vector<Task>() };

public:
    void addTask(std::string description);
    void editTask(size_t id, std::string description);
    void delTask(size_t id);

    void markStatus(size_t id, Status status);
    void printByStatus(Status status);
    
    friend std::ostream& operator<<(std::ostream& os, const TasksList& list);
};

