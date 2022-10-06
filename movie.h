#ifndef MOVIE_H
define MOVIE_H
#include "product.h"
#inlcude "util.h"
#include <iostream>
#include <string>
#include <set>

class Movie: public Product{
  public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    virtual std::set<std::string> keyword() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  protected:
    std::string rating_;
    std::string genre_;
  
};
#endif