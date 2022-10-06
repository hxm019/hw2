#ifndef CLOTHING_H
define CLOTHING_H
#include "product.h"
#inlcude "util.h"
#include <iostream>
#include <string>
#include <set>

class Clothing: public Product{
  public:
    Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);
    virtual std::set<std::string> keyword() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  protected:
    std::string brand_;
    std::string size_;
  
};
#endif