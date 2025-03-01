#include <iostream>
#include <memory>

class VeryHeavyDatabase {
public:
  virtual ~VeryHeavyDatabase() = default;
  virtual std::string GetData(const std::string& key) {
    return "value";
  }
};

class OneShotDB : public VeryHeavyDatabase {
private:
  VeryHeavyDatabase* real_object;
  size_t shots_remaining;

public:
  explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1) 
    : real_object(real_object), shots_remaining(shots) {}

  std::string GetData(const std::string& key) override {
    if (shots_remaining > 0) {
      --shots_remaining;
      return real_object->GetData(key);
    } 
    return "error";
  }
};

int main() {
  VeryHeavyDatabase real_db;
  OneShotDB limit_db(std::addressof(real_db), 2);

  std::cout << limit_db.GetData("key") << std::endl;
  std::cout << limit_db.GetData("key") << std::endl;
  std::cout << limit_db.GetData("key") << std::endl;

  return 0;
}
