#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <memory>

class Publisher {
public:
    std::string name;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, name, "name");
    }
};

class Book {
public:
    std::string title;
    int id_publisher;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::field(a, id_publisher, "id_publisher");
    }
};

class Stock {
public:
    int id_book;
    int id_shop;
    int count;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, id_book, "id_book");
        Wt::Dbo::field(a, id_shop, "id_shop");
        Wt::Dbo::field(a, count, "count");
    }
};

class Shop {
public:
    std::string name;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, name, "name");
    }
};

class Sale {
public:
    int price;
    int date_sale;
    int id_stock;
    int count;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, id_stock, "id_stock");
        Wt::Dbo::field(a, count, "count");
    }
};

int main() {
    try {
        auto postgresConnection = std::make_unique<Wt::Dbo::backend::Postgres>(
            "host=localhost port=5432 dbname=book_shop user=postgres"
        );

        Wt::Dbo::Session session;
        session.setConnection(std::move(postgresConnection));
        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Shop>("shop");
        session.mapClass<Sale>("sale");

        try {
            session.createTables();
            std::cout << "The tables were created." << std::endl;
        } catch (const Wt::Dbo::Exception &e) {
            std::cerr << "Table creation error: " << e.what() << std::endl;
        } {
            Wt::Dbo::Transaction transaction(session);
            // auto newUser = session.add(std::make_unique<User>());
            // newUser.modify()->name = "Bober";
            // newUser.modify()->age = 18;
            // transaction.commit();
            // std::cout << "The user was added." << std::endl;
        } {
            // Wt::Dbo::Transaction transaction(session);
            // typedef Wt::Dbo::collection<Wt::Dbo::ptr<User> > Users;
            // Users users = session.find<User>();

            // for (const auto &user: users) {
                // std::cout << "Name: " << user->name << "\t Age: " << user->age << std::endl;
            // }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
