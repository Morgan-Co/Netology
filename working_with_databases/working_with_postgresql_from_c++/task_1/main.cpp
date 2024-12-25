#include <iostream>
#include <string>
#include "db_manager/db_manager.h"
#include <pqxx/pqxx>


int main() {
    try {
        const DatabaseManager db_manager("host=localhost port=5432 dbname=clients user=postgres");
        db_manager.create_tables(
            "CREATE TABLE IF NOT EXISTS clients (id SERIAL PRIMARY KEY, name VARCHAR(40) NOT NULL, email VARCHAR(30) UNIQUE NOT NULL)");
        db_manager.create_tables(
            "CREATE TABLE IF NOT EXISTS client_numbers (id SERIAL PRIMARY KEY, number VARCHAR(20), client_id SERIAL REFERENCES clients(id));");


        int action;
        std::cout << "Welcome to Database Manager -------------------------------" << std::endl;
        do {
            std::cout << "Enter an action (0 - show info): ";
            std::cin >> action;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            switch (action) {
                case 0: {
                    std::cout << "1 - add client" << std::endl;
                    std::cout << "2 - add client number" << std::endl;
                    std::cout << "3 - change client data" << std::endl;
                    std::cout << "4 - delete client number" << std::endl;
                    std::cout << "5 - delete client" << std::endl;
                    std::cout << "6 - get clients" << std::endl;
                    std::cout << "7 - find client" << std::endl;
                    std::cout << "8 - get client numbers" << std::endl;
                    std::cout << "9 - exit" << std::endl;
                    break;
                }
                case 1: {
                    std::string name, email;
                    std::cin.ignore();
                    std::cout << "Enter a name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter a email: ";
                    std::getline(std::cin, email);
                    db_manager.add_client(name, email);
                    break;
                }
                case 2: {
                    db_manager.print_table_data("clients");
                    int client_id;
                    std::string number;
                    std::cout << "Enter client ID: ";
                    std::cin >> client_id;
                    std::cout << "Enter a number: ";
                    std::cin >> number;
                    db_manager.add_number(number, client_id);
                    break;
                }

                case 3: {
                    db_manager.print_table_data("clients");
                    int client_id;
                    std::cout << "Enter client id: ";
                    std::cin >> client_id;
                    std::cin.ignore();
                    db_manager.change_client(client_id);
                    break;
                }

                case 4: {
                    db_manager.print_table_data("clients");
                    int client_id, number_id;
                    std::cout << "Enter client id: ";
                    std::cin >> client_id;
                    db_manager.print_client_numbers(client_id);
                    std::cout << "Enter number id: ";
                    std::cin >> number_id;
                    db_manager.delete_number(client_id, number_id);
                    break;
                }
                case 5: {
                    db_manager.print_table_data("clients");
                    int client_id;
                    std::cout << "Enter a client id: ";
                    std::cin >> client_id;
                    db_manager.delete_client(client_id);
                }
                case 6: {
                    db_manager.print_table_data("clients");
                    break;
                }
                case 7: {
                    std::string search_query;
                    std::cin.ignore();
                    std::cout << "Enter: ";
                    std::getline(std::cin, search_query);
                    db_manager.find_client(search_query);
                    break;
                }
                case 8: {
                    db_manager.print_table_data("clients");
                    int client_id;
                    std::cout << "Enter client id: ";
                    std::cin >> client_id;
                    db_manager.print_client_numbers(client_id);
                    break;
                }
                default: break;
            }
        } while (action != 9);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
