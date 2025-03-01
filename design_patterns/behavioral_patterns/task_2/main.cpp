#include <csignal>
#include <ios>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
#include <vector>
#include <algorithm>

class LogCommand {
public:
  virtual ~LogCommand() = default;
  virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
  void print(const std::string& message) override {
    std::cout << message << std::endl;
  }
};

class FileLogCommand : public LogCommand {
private:
  std::string filePath;
public:
  explicit FileLogCommand(const std::string& path) : filePath(path) {}
  void print(const std::string& message) override {
    std::ofstream file(filePath, std::ios::app);
    if (file.is_open()) {
      file << message << std::endl;
    } else {
      std::cerr << "File closing error: " << filePath << std::endl;
    }
  }
};

void print(LogCommand& command, const std::string& message) {
  command.print(message);
}

class Observer {
public:
  virtual ~Observer() = default;
  virtual void onWarning(const std::string& message) {}
  virtual void onError(const std::string& message) {}
  virtual void onFatalError(const std::string& message) {}
};

class LogSubject {
private:
  std::vector<Observer*> observers;
public:
  void addObserver(Observer* observer) {
    observers.push_back(observer);
  }

  void removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
  }

  void warning(const std::string& message) const {
    for (auto* observer : observers) {
      observer->onWarning(message);
    }
  }

  void error(const std::string& message) const {
    for (auto* observer : observers) {
      observer->onError(message);
    }
  }

  void fatalError(const std::string& message) {
    for (auto* observer: observers) {
      observer->onFatalError(message);
    }
  }
};

class WarningObserver : public Observer {
public:
  void onWarning(const std::string& message) override {
    std::cout << "Warning: " << message << std::endl;
  }
};

class ErrorObserver : public Observer {
private:
  std::string filePath;
public:
  explicit ErrorObserver(const std::string& path) : filePath(path) {}
  void onError(const std::string& message) override {
    std::ofstream file(filePath, std::ios::app);
    if (file.is_open()) {
      file << "Error: " << message << std::endl;
    } else {
      std::cerr << "Closing file error: " << filePath << std::endl;
    }
  }
};

class FatalErrorObserver : public Observer {
private: 
  std::string filePath;
public:
  explicit FatalErrorObserver(const std::string& path) : filePath(path) {}
  void onFatalError(const std::string& message) override {
    std::cout << "Fatal Error: " << message << std::endl;
    std::ofstream file(filePath, std::ios::app);
    if (file.is_open()) {
      file << "Fatal Error: " << message << std::endl;
    } else {
      std::cerr << "Closing file error: " << filePath << std::endl;
    }
  }
};

int main() {
  LogSubject logger;
  WarningObserver warningObserver;
  ErrorObserver errorObserver("error_log.txt");
  FatalErrorObserver fatalErrorObserver("fatal_log.txt");

  logger.addObserver(&warningObserver);
  logger.addObserver(&errorObserver);
  logger.addObserver(&fatalErrorObserver);

  logger.warning("It is a warning");
  logger.warning("It is an error");
  logger.warning("It is a fatal error");

  return 0;
}
