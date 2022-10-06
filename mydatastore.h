#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "util.h"
#include "product.h"
#include "db_parser"
#include "user.h"
#include "datastore.h"
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

class MyDataStore : public datastore
{
  public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    void addtocart(std::string username, Product* p);

    void viewcart(std::string username);

    void buycart(std::string username);
  
  private:

    std::set<Product*> productlist;

    std::map<std::string,User*> user;

    std::map<std::string,std:vector<Product*>> cart;

    std::map<std::string,std::set<Product*>> productmap;

};

#endif


};

#endif

}

