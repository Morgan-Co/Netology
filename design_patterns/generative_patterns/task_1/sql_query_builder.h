#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

class SqlSelectQueryBuilder {
private:
  std::vector<std::string> columns_;
  std::string table_;
  std::unordered_map<std::string, std::string> where_clauses_;

public:
  SqlSelectQueryBuilder& AddColumn(const std::string& column) {
    columns_.push_back(column);    
    return *this;
  }

  SqlSelectQueryBuilder& AddFrom(const std::string& table) {
    table_ = table;
    return *this;
  }

  SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
    where_clauses_[column] = value;
    return *this;
  }

  std::string BuildQuery() const {
    std::ostringstream query;
    query << "SELECT ";

    if (columns_.empty()) {
      query << "*";
    } else {
      for (size_t i = 0; i < columns_.size(); i++) {
        if (i > 0) query << ", ";
        query << columns_[i];
      }
    }

    query << " FROM " << table_;

    if (!where_clauses_.empty()) {
      query << " WHERE ";
      bool first = true;
      for (const auto& [column, value] : where_clauses_) {
        if (!first) query << " AND ";
        query << column << "=" << value;
        first = false;
      }
    }

    query << ";";
    return query.str();
  }
};
