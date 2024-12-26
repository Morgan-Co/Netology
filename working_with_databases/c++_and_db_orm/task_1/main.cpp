#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Wt/Dbo/Session.h>
#include <iostream>

class Stock;
class Publisher;
class Shop;
class Sale;

class Book {
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::ptr<Stock> stock;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::belongsTo(a, stock, "stock");
    }
};

class Publisher {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Book> > books;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Stock {
public:
    int count{};
    Wt::Dbo::collection<Wt::Dbo::ptr<Book> > books;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale> > sales;


    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "stock");
        Wt::Dbo::belongsTo(a, shop);
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Shop {
public:
    std::string name;
    Wt::Dbo::weak_ptr<Stock> stock;

    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasOne(a, stock);
    }
};

class Sale {
public:
    int price{};
    int date_sale{};
    int count{};
    Wt::Dbo::ptr<Stock> stock;


    template<class Action>
    void persist(Action &a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "stock");
    }
};

int main() {
    try {
        auto postgresConnection = std::make_unique<Wt::Dbo::backend::Postgres>(
            "host=localhost port=5432 dbname=book_shop user=postgres"
        );

        Wt::Dbo::Session session;
        session.setConnection(std::move(postgresConnection));
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Publisher>("publisher");
        session.mapClass<Sale>("sale");
        session.mapClass<Shop>("shop");

        // session.dropTables();
        // session.createTables();
        // std::cout << "The tables were created." << std::endl;
        // {
        //     Wt::Dbo::Transaction transaction(session);
        //
        //     // Publishers
        //     const Wt::Dbo::ptr<Publisher> publisher_1 = session.add(std::make_unique<Publisher>("Capy Books"));
        //     const Wt::Dbo::ptr<Publisher> publisher_2 = session.add(std::make_unique<Publisher>("Cool Books"));
        //     const Wt::Dbo::ptr<Publisher> publisher_3 = session.add(std::make_unique<Publisher>("Books For You"));
        //
        //     // Shops
        //     const Wt::Dbo::ptr<Shop> shop_1 = session.add(std::make_unique<Shop>("Capy Store"));
        //     const Wt::Dbo::ptr<Shop> shop_2 = session.add(std::make_unique<Shop>("Cool Store"));
        //     const Wt::Dbo::ptr<Shop> shop_3 = session.add(std::make_unique<Shop>("Store For You"));
        //
        //     // Books
        //     const Wt::Dbo::ptr<Book> book_1 = session.add(std::make_unique<Book>("Great Expectations"));
        //     const Wt::Dbo::ptr<Book> book_2 = session.add(std::make_unique<Book>("1984"));
        //     const Wt::Dbo::ptr<Book> book_3 = session.add(std::make_unique<Book>("Animal Farm"));
        //     const Wt::Dbo::ptr<Book> book_4 = session.add(std::make_unique<Book>("Star Wars"));
        //     const Wt::Dbo::ptr<Book> book_5 = session.add(std::make_unique<Book>("Brief Answers to the Big Questions"));
        //     const Wt::Dbo::ptr<Book> book_6 = session.add(std::make_unique<Book>("Dune"));
        //
        //
        //     // Stocks
        //     const Wt::Dbo::ptr<Stock> stock_1 = session.add(std::make_unique<Stock>());
        //     const Wt::Dbo::ptr<Stock> stock_2 = session.add(std::make_unique<Stock>());
        //     const Wt::Dbo::ptr<Stock> stock_3 = session.add(std::make_unique<Stock>());
        //     stock_1.modify()->count = 6;
        //     stock_2.modify()->count = 1;
        //     stock_3.modify()->count = 2;
        //
        //     // Sales
        //     const Wt::Dbo::ptr<Sale> sale_1 = session.add(std::make_unique<Sale>());
        //     const Wt::Dbo::ptr<Sale> sale_2 = session.add(std::make_unique<Sale>());
        //     const Wt::Dbo::ptr<Sale> sale_3 = session.add(std::make_unique<Sale>());
        //     sale_1.modify()->price = 40;
        //     sale_2.modify()->price = 30;
        //     sale_3.modify()->price = 60;
        //
        //     sale_1.modify()->count = 3;
        //     sale_2.modify()->count = 4;
        //     sale_3.modify()->count = 5;
        //
        //     sale_1.modify()->date_sale = 20242512;
        //     sale_2.modify()->date_sale = 20240104;
        //     sale_3.modify()->date_sale = 20242403;
        //
        //     // Connection
        //     book_1.modify()->publisher = publisher_1;
        //     book_2.modify()->publisher = publisher_1;
        //     book_3.modify()->publisher = publisher_2;
        //     book_4.modify()->publisher = publisher_2;
        //     book_5.modify()->publisher = publisher_3;
        //     book_6.modify()->publisher = publisher_3;
        //
        //     book_1.modify()->stock = stock_1;
        //     book_2.modify()->stock = stock_1;
        //     book_3.modify()->stock = stock_2;
        //     book_4.modify()->stock = stock_2;
        //     book_5.modify()->stock = stock_3;
        //     book_6.modify()->stock = stock_3;
        //
        //     stock_1.modify()->shop = shop_1;
        //     stock_2.modify()->shop = shop_2;
        //     stock_3.modify()->shop = shop_3;
        //
        //     sale_1.modify()->stock = stock_1;
        //     sale_2.modify()->stock = stock_2;
        //     sale_3.modify()->stock = stock_3;
        // }

        std::string publisherName;
        std::cout << "Enter the name of the publisher: " << std::endl;
        std::getline(std::cin, publisherName); {
            Wt::Dbo::Transaction transaction(session);


            Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(publisherName);
            if (!publisher) {
                std::cout << "Publisher with name " << publisherName << " not found." << std::endl;
                return 1;
            }

            std::cout << "Publisher: " << publisher->name << std::endl;
            std::cout << "Books --------------------------------------" << std::endl;
            for (const auto &book: publisher->books) {
                std::cout << book->title << std::endl;
            }
            std::cout << "Shops --------------------------------------" << std::endl;
            for (const auto &book: publisher->books) {
                const std::string shopName = book->stock->shop ? book->stock->shop->name : "Not Found";
                std::cout << shopName << std::endl;
            }

            transaction.commit();
        }
    } catch (Wt::Dbo::Exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
