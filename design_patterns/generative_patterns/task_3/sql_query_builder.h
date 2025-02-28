#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>

class SqlSelectQueryBuilder {
protected:
  std::vector<std::string> columns_;
  std::string table_;
  std::unordered_map<std::string, std::string> where_clauses_;

public:
  SqlSelectQueryBuilder& AddColumn(const std::string& column) {
    columns_.push_back(column);    
    return *this;
  }

  SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) {
    columns_.insert(columns_.end(), columns.begin(), columns.end());
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

  SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
    where_clauses_.insert(kv.begin(), kv.end());
    return *this;
  }

  virtual std::string BuildQuery() const {
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

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
private:
  std::vector<std::tuple<std::string, std::string, std::string>> advanced_where_;

public:
  AdvancedSqlSelectQueryBuilder& AddWhereCondition(const std::string& column, const std::string& op, const std::string& value) {
    advanced_where_.emplace_back(column, op, value);
    return *this;
  }

  std::string BuildQuery() const override {
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

    if (!where_clauses_.empty() || !advanced_where_.empty()) {
      query << " WHERE ";
      bool first = true;
      for (const auto& [column, value] : where_clauses_) {
        if (!first) query << " AND ";
        query << column << "=" << value;
        first = false;
      }
      for (const auto& [column, op, value] : advanced_where_) {
        if (!first) query << " AND ";
        query << column << op << value;
        first = false;
      }
    }

    query << ";";
    return query.str();
  }
};
