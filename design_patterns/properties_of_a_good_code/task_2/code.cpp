#include <fstream>

enum class Format
{
    kText,
    kHTML,
    kJSON
};

class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};

class Data : public Printable
{
public:
  Data(std::string data, Format format) : data_(std::move(data)), format_(format) {}
protected:
    std::string data_;
    Format format_;
};

class HTMLData : public Data {
public:
  HTMLData(std::string data) : Data(data, Format::kHTML) {} 

  std::string print() const override {
    if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
    }
    return "<html>" + data_ + "<html/>";
  }
};

class TextData : public Data {
public:
  TextData(std::string data) : Data(data, Format::kText) {} 

  std::string print() const override {
    if (format_ != Format::kText) {
      throw std::runtime_error("Invalid format!");
    }
    return data_;
  }
};

class JSONData : public Data {
public:
  JSONData(std::string data) : Data(data, Format::kJSON) {} 

    std::string print() const override {
      if (format_ != Format::kJSON) {
        throw std::runtime_error("Invalid format!");
      }
      return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream &file, const Printable& printable) {
  file << printable.print();
}
