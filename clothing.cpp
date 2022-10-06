#include "clothing.h"
#include "product.h"
#include "util.h"
#include <string>
#include <sstream>
using namespace std;

Clothing:Clothing(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN):
  Product(category,name, price, qty){
    brand_=brand;
    size_=size;
  }
  // defining keywords 
  std::set<std::string> Clothing:keywords() const{
    std::set<std::string> name= parseStringToWords(name_);
    std::set<std::string> brand= parseStringToWords(brand_);
    std::set<string> keys= setUnion (name,brand);
    // we parsed name and brand and combined them and put it into keys
    return keys;
  }


  std::string Clothing::displayString() const{
    string output=""
    std::stringstream ss;
    ss << price_;
    string money = ss.str();
  // converting price into string 
    std::stringstream st;
    st << qty_;
    string amount = st.str();
    //converting quantity into string

    output= name_ + "Size: " + size_ + " " + "Brand: "+ brand_+ "\n" + money + "\n" + amount + "left";
    return output;
    // returning output in the required format 
  }

  void Clothing::dump(std::ostream& os) const{
    Product::dump(os);
    //dumps category, name,price,qty
    os<< brand_ << "\n" << size_ << endl;
    //dumps clothing additional characteristics
  }