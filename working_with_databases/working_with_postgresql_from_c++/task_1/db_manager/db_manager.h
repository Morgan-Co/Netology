#pragma once
#include <pqxx/pqxx>


struct Client {
    int id;
    std::string name, email;
};

class DatabaseManager {
private:
    std::unique_ptr<pqxx::connection> conn;

public:
    explicit DatabaseManager(const std::string &connInfo);
    void create_tables(const std::string &createQuery) const;
    void add_client(const std::string &name, const std::string &email) const;
    void add_number(const std::string &number, const int &client_id) const;
    void delete_client(const int& client_id) const;
    void delete_number(const int& client_id, const int& number_id) const;
    static void delete_related_numbers(pqxx::work& txn, const int& client_id);
    void change_client(const int& client_id) const;
    void find_client(const std::string& search_query) const;
    std::vector<std::string> get_fields_name(const std::string& tableName) const;
    void print_table_data(const std::string &tableName) const;
    void print_client_numbers(const int& client_id) const;
    void drop_tables(const std::string &tableName) const;
private:
    static bool is_number(const std::string& s);
};