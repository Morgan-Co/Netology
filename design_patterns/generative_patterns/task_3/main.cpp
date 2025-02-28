#include <iostream>
#include "sql_query_builder.h"

int main() {
  AdvancedSqlSelectQueryBuilder query_builder;
  query_builder.AddColumns({"name", "phone"});
  query_builder.AddFrom("students");
  query_builder.AddWhereCondition("id", ">", "42");

  std::cout << query_builder.BuildQuery() << std::endl;
}
