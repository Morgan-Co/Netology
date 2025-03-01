#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <fstream>

enum class Type {
  Warning,
  Error,
  FatalError,
  Unknown
};

class LogMessage {
private:
  Type logType;
  std::string logMessage;
public:
  LogMessage(Type type, const std::string& message) : logType(type), logMessage(message) {}
  Type type() const { return logType; }
  const std::string& message() const { return logMessage; }

};

class LogHandler {
protected:
  std::shared_ptr<LogHandler> nextHandler;
public:
  virtual ~LogHandler() = default;
  void setNext(std::shared_ptr<LogHandler> handler) {
    nextHandler = handler;
  }
  virtual void handle(const LogMessage& logMessage) {
    if (nextHandler) {
      nextHandler->handle(logMessage);
    } else {
      throw std::runtime_error("Unhandled log message type.");
    }
  }
};

class FatalErrorHandler : public LogHandler {
public:
  void handle(const LogMessage& logMessage) override {
    if (logMessage.type() == Type::FatalError) {
      throw std::runtime_error("Fatal Error: " + logMessage.message());
    }
    LogHandler::handle(logMessage);
  }
};

class ErrorHandler : public LogHandler {
private:
  std::string filePath;
public:
  explicit ErrorHandler(const std::string& path) : filePath(path) {}
  void handle(const LogMessage& logMessage) override {
    if (logMessage.type() == Type::Error) {
      std::ofstream file(filePath, std::ios::app);
      if (file.is_open()) {
        file << "Error: " << logMessage.message() << std::endl;
      } else {
        std::cerr << "Opening file error: " << filePath << std::endl;
      }
    } else {
      LogHandler::handle(logMessage);
    } 
  } 
};

class WarningHanlder : public LogHandler {
public:
  void handle(const LogMessage& logMessage) override {
    if (logMessage.type() == Type::Warning) {
      std::cout << "Warning: " << logMessage.message() << std::endl;
    } else {
      LogHandler::handle(logMessage);
    }
  }
};

class UnknownHandler : public LogHandler {
public:
  void handle(const LogMessage& logMessage) override {
    if (logMessage.type() == Type::Unknown) {
      throw std::runtime_error("Uknown log message: " + logMessage.message());
      LogHandler::handle(logMessage);
    }
  }
};

int main() {
  auto fatalHandler = std::make_shared<FatalErrorHandler>();
  auto errorHandler = std::make_shared<ErrorHandler>("error_log.txt");
  auto warningHandler = std::make_shared<WarningHanlder>();
  auto unknownHandler = std::make_shared<UnknownHandler>();

  fatalHandler->setNext(errorHandler);
  errorHandler->setNext(warningHandler);
  warningHandler->setNext(unknownHandler);

  try {
    LogMessage warningMessage(Type::Warning, "Warning!");
    LogMessage errorMessage(Type::Warning, "Error!");
    LogMessage fatalErrorMessage(Type::Warning, "Fatal Error!");
    LogMessage unknownMessage(Type::Warning, "Unknown!");

    fatalHandler->handle(warningMessage);
    fatalHandler->handle(errorMessage);
    fatalHandler->handle(fatalErrorMessage);
    fatalHandler->handle(unknownMessage);
  } catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}




