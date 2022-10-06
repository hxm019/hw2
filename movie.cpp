#include "movie.h"
#include "product.h"
#include "util.h"
#include <string>
#include <sstream>
using namespace std;

Clothing:Clothing(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN):
  Product(category,name, price, qty){
    genre_=genre;
    rating_=rating;
  }
  // defining keywords 
  std::set<std::string> Movie:keywords() const{
    std::set<std::string> name= parseStringToWords(name_);
    std::set<std::string> genre= parseStringToWords(genre_);
    std::set<string> keys= setUnion (name,genre);
    // we parsed name and genre and combined them and put it into keys
    return keys;
  }


  std::string Movie::displayString() const{
    string output=""
    std::stringstream ss;
    ss << price_;
    string money = ss.str();
  // converting price into string 
    std::stringstream st;
    st << qty_;
    string amount = st.str();
    //converting quantity into string

    output= name_ + "Genre: " + genre_ + " " + "Rating: "+ rating_+ "\n" + money + "\n" + amount + "left";
    return output;
    // returning output in the required format 
  }

  void Movie::dump(std::ostream& os) const{
    Product::dump(os);
    //dumps category, name,price,qty
    os<< genre_ << "\n" << rating_ << endl;
    //dumps clothing additional characteristics
  }