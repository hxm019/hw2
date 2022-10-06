#include "book.h"
#include "product.h"
#include "util.h"
#include <string>
#include <sstream>
using namespace std;

Book:Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN):
  Product(category,name, price, qty){
    ISBN_=ISBN;
    author_=author;
  }
  // defining keywords 
  std::set<std::string> Book:keywords() const{
    std::set<std::string> name= parseStringToWords(name_);
    std::set<std::string> auth= parseStringToWords(author_);
    std::set<string> keys= setUnion (name,auth);
    keys.insert(ISBN_);
    // we parsed name and author and combined them and put it into keys
    return keys;
  }


  std::string Book::displayString() const{
    string output=""
    std::stringstream ss;
    ss << price_;
    string money = ss.str();
  // converting price into string 
    std::stringstream st;
    st << qty_;
    string amount = st.str();
    //converting quantity into string

    output= name_ + "Author: " + author_ + " " + "ISBN: "+ ISBN_+ "\n" + money + "\n" + amount + "left";
    return output;
    // returning output in the required format 
  }

  void Book::dump(std::ostream& os) const{
    Product::dump(os);
    //dumps category, name,price,qty
    os<< ISBN_ << "\n" << author_ << endl;
    //dumps books additional characteristics
  }


