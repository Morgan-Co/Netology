#include "db_manager.h"
#include <iostream>
#include <regex>

DatabaseManager::DatabaseManager(const std::string &connInfo) {
    try {
        conn = std::make_unique<pqxx::connection>(connInfo);
        if (conn->is_open()) {
            std::cout << "The connection is established: " << conn->dbname() << std::endl;
        } else {
            throw std::runtime_error("Сouldn't connect to the database!");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::create_tables(const std::string &createQuery) const {
    try {
        pqxx::work txn(*conn);
        txn.exec(createQuery);
        txn.commit();

        std::cout << "The table was created successfully!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::add_client(const std::string &name, const std::string &email) const {
    try {
        pqxx::work txn(*conn);
        const std::string sql = "INSERT INTO clients (name, email) VALUES (" + txn.quote(name) + ", " + txn.quote(email)
                                +
                                ");";
        txn.exec(sql);
        txn.commit();
        std::cout << "The entry was added successfully!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error when adding a client: " << e.what() << std::endl;
    }
}

void DatabaseManager::delete_client(const int &client_id) const {
    try {
        pqxx::work txn(*conn);
        delete_related_numbers(txn, client_id);
        const std::string sql = "DELETE FROM clients WHERE id = $1";
        txn.exec(sql, client_id);
        txn.commit();
        std::cout << "The client was deleted!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


void DatabaseManager::change_client(const int &client_id) const {
    try {
        std::vector<std::string> columns = get_fields_name("clients");
        pqxx::work txn(*conn);
        std::string sql = "UPDATE clients SET ";
        bool has_changes = false;

        for (const auto &column: columns) {
            std::string current_value;

            std::string select_sql = "SELECT " + column + " FROM clients WHERE id = $1";
            pqxx::result result = txn.exec(select_sql, client_id);
            if (!result.empty()) {
                current_value = result[0][0].c_str();
            } else {
                std::cerr << "Record with id = " << client_id << " not found!" << std::endl;
                return;
            }

            std::cout << "Current value of field \"" << column << "\": " << current_value << std::endl;
            std::cout << "Enter a new value (press Enter to skip): ";
            std::string new_value;
            std::getline(std::cin, new_value);
            if (new_value.empty()) {
                continue;
            }

            if (has_changes) {
                sql += ", ";
            }
            sql += column + " = " + txn.quote(new_value);
            has_changes = true;
        }

        sql += " WHERE id = " + txn.quote(client_id);
        txn.exec(sql);
        txn.commit();
        std::cout << "The record was successfully updated!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::find_client(const std::string &search_query) const {
    try {
        pqxx::work txn(*conn);
        std::string sql;
        pqxx::result result;
        if (is_number(search_query)) {
            sql = R"(
                SELECT DISTINCT clients.*
                FROM clients
                LEFT JOIN client_numbers ON clients.id = client_numbers.client_id
                WHERE clients.name = $1
                   OR clients.email = $1
                   OR client_numbers.client_id = $1::integer
            )";
            const pqxx::params params{search_query};
            result = txn.exec(sql, params);
        } else {
            sql = R"(
                SELECT DISTINCT clients.*
                FROM clients
                LEFT JOIN client_numbers ON clients.id = client_numbers.client_id
                WHERE clients.name = $1
                   OR clients.email = $1
            )";
            const pqxx::params params{search_query};
            result = txn.exec(sql, params);
        }
        if (result.empty()) {
            std::cout << "Client not found" << std::endl;
        } else {
            std::cout << "Found clients: " << std::endl;
            for (const auto &row: result) {
                for (const auto &field: row) {
                    std::cout << field.name() << ": " << field.c_str() << "\t";
                }
                std::cout << std::endl << "-------------------------" << std::endl;
            }
        }
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void DatabaseManager::add_number(const std::string &number, const int &client_id) const {
    try {
        pqxx::work txn(*conn);
        const std::string sql = "INSERT INTO client_numbers (number, client_id) VALUES (" + txn.quote(number) + ", " +
                                txn.
                                quote(client_id) + ");";
        txn.exec(sql);
        txn.commit();
        std::cout << "The number was added!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::delete_number(const int &client_id, const int &number_id) const {
    try {
        pqxx::work txn(*conn);
        const std::string sql = "DELETE FROM client_numbers WHERE id = $1 AND client_id = $2";
        const pqxx::params params{number_id, client_id};
        txn.exec(sql, params);
        txn.commit();
        std::cout << "The number was deleted!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::delete_related_numbers(pqxx::work &txn, const int &client_id) {
    try {
        const std::string sql = "DELETE FROM client_numbers WHERE client_id = $1";
        txn.exec(sql, client_id);
        txn.commit();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


std::vector<std::string> DatabaseManager::get_fields_name(const std::string &tableName) const {
    std::vector<std::string> columns;
    try {
        pqxx::work txn(*conn);
        const std::string sql = R"(
            SELECT column_name
            FROM information_schema.columns
            WHERE table_name = $1
            ORDER BY ordinal_position
        )";
        const pqxx::params params{tableName};
        const pqxx::result result = txn.exec(sql, params);
        for (const auto &row: result) {
            columns.push_back(row["column_name"].as<std::string>());
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    return columns;
}

void DatabaseManager::print_table_data(const std::string &tableName) const {
    try {
        std::vector<std::string> tableFields = get_fields_name(tableName);
        pqxx::work txn(*conn);
        const std::string sql = "SELECT * FROM " + tableName;
        const pqxx::result result = txn.exec(sql);

        if (result.empty()) {
            std::cout << "Data from table \"" << tableName << "\" not found." << std::endl;
            return;
        }

        for (const auto &row: result) {
            std::vector<std::pair<std::string, std::string> > table_data;
            for (auto &tableField: tableFields) {
                auto field_data = row[tableField].as<std::string>();
                std::cout << tableField << ": " << field_data << "\t";
                table_data.emplace_back(tableField, field_data);
            }
            std::cout << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::print_client_numbers(const int &client_id) const {
    try {
        pqxx::work txn(*conn);
        const std::string sql = "SELECT * FROM client_numbers WHERE client_id = $1";
        const pqxx::result result = txn.exec(sql, client_id);
        if (result.empty()) {
            std::cout << "Client numbers with id: " << client_id << " were not found." << std::endl;
            return;
        }
        std::cout << "Client number with id: " << client_id << std::endl;
        for (const auto &row: result) {
            const int id = row["id"].as<int>();
            const auto number = row["number"].as<std::string>();
            std::cout << "ID: " << id << "\tNumber: " << number << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void DatabaseManager::drop_tables(const std::string &tableName) const {
    try {
        pqxx::work txn(*conn);
        const std::string sql = "DROP TABLE IF EXISTS " + txn.quote(tableName);
        char action;
        std::cout << "Are you sure (y - yes, n - no): ";
        std::cin >> action;
        switch (action) {
            case 'y': {
                txn.exec(sql);
                txn.commit();
                std::cout << "The table was deleted!" << std::endl;
                break;
            }
            case 'n': {
                return;
            }
            default: break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

bool DatabaseManager::is_number(const std::string &s) {
    return std::regex_match(s, std::regex("^[0-9]+$"));
}
