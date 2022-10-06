#include <iomanip>
#include "util.h"
#include "mydatastore.h"
#include "book.h"
#include "util.h"
#include "product.h"
#include "db_parser.h"
#include "user.h"
#include "datastore.h"
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;
//constructor
MyDataStore::MyDataStore(){

}
MyDataStore::~MyDataStore(){

}
  void addProduct(Product* p){
    //have to check keywords from productlist and if it does, insert
    //if not then create the keyword and then insert
    productlist.insert(p);
    set <string> k=p->keywords();
    for(set <string>::iterator it=k.begin();it!=k.end();++it){ //iterating through list
      if(productmap.find(*it)==productmap.end()){
        set <Product*> sp;
        sp.insert(p);  //inserting if not found
        productmap[*it]=sp;
      }
    else{
      productmap[*it].insert(p);
    }
    }
  }

  void addUser(User* u){
    //adding user by making a pair and then pushing into the list
    if(user.find(u->getName())==user.end()){
      user.insert(make_pair(u->getName(),u))
    }
  }


  std::vector<Product*> search(std::vector<std::string>& terms, int type){
    vector<Product*> res;
    vector<set<Product *>> psetT;
    for(unsigned j=0;j<terms.size();j++){ //iterating through terms
      if(productmap.find(terms[j])!=productmap.end()){ //if doesnt find
        psetT.push_back(productmap[terms[j]]);
      }
    }
    if(psetT.size()==0){
      return res; //returns result
    }
    set<Product*> fset=psetT[0];
    for(unsigned i=1;i<psetT.size();i++){ //iterating
      if(type==0){
        fset=setIntersection(fset,psetT[i]); //assigning the common terms
      }
      else{
        fset=setUnion(fset,psetT[i]); //assigning all terms
      }
    }
    for(Product* p:finalSet){
      res.push_back(p);
    }
    return res; //returns final result
  }

  void dump(std::ostream& ofile){}

  void addtocart(std::string username, Product* p){}

  void viewcart(std::string username){}



  void buycart(std::string username){}

