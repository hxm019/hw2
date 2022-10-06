#ifndef BOOK_H
define BOOK_H
#include "product.h"
#inlcude "util.h"
#include <iostream>
#include <string>
#include <set>

class Book: public Product{
  public:
    Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN);
    virtual std::set<std::string> keyword() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  protected:
    std::string ISBN_;
    std::string author_;
  
};
#endif