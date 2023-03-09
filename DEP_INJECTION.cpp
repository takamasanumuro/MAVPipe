#include <fstream>
#include <iostream>
#include <memory>
#include "fboat/mavlink.h"

class ILogger {
public:
    virtual void log(const char* message) = 0; 
};

class ConsoleLogger : public ILogger {
public:
    void log(const char* message) override {
        std::cout << message << std::endl;
    }
};

class FileLogger : public ILogger {
public:
    void log(const char* message) override {
        std::ofstream file("logtest.txt");
        file << message << '\n';
    }
};

class Client {
public:
    Client(std::shared_ptr<ILogger> log) : m_logger(log) {}
    void setLogger(std::shared_ptr<ILogger> log) {
        m_logger = log;
    }
    void writeLog(const char* message) {
        m_logger -> log(message);
    }
private:
    std::shared_ptr<ILogger> m_logger; // Composition
};

int main() {
    Client new_client = Client(std::make_shared<ConsoleLogger>());
    new_client.writeLog("Hello, console logger");
    new_client.setLogger(std::make_shared<FileLogger>());
    new_client.writeLog("Hello, file logger");
    return 0;
}
