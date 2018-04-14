#include <iostream>
#include "tree.hpp"

namespace StructureAnalyze {

  template<typename C> uint32_t Tree<C>::Element::ammount = 0;

  template<typename C> Tree<C>::Element::Element(C value) {
    this->id = ammount;
    Tree<C>::Element::ammount++;
    this->value = value;
  }

  template<typename C> void Tree<C>::Element::setParent(typename Tree<C>::Element* parent) {
    this->parent = parent;
  }

  template<typename C> typename Tree<C>::Element* Tree<C>::Element::getParent() {
    return this->parent;
  }

  template<typename C> uint32_t Tree<C>::Element::getBranchLength() {
    uint32_t length = 0;
    auto x = this->parent;
    while(x != this->parent) {
      length++;
      x = x->parent;
    }
    return length;
  }

  template<typename C> uint32_t Tree<C>::Element::getID() {
    return this->id;
  }

  template<typename C> C Tree<C>::Element::getValue() {
    return this->value;
  }

  template<typename C> void Tree<C>::Element::info() {
    std::cout<<"ID: "<<this->getID();
    std::cout<<"; Parent address: "<<this->getParent();
    std::cout<<"; Value: "<<this->getValue();
    std::cout<<std::endl;

  }

  template<typename C> void Tree<C>::push(C value) {
    this->elements.push_back(Element(value));

    typename std::list<Element>::reverse_iterator rit = this->elements.rbegin();
    /*
    * Possible cancer
    */
    rit->setParent(&(*rit)); //set parent to itself
    if(this->edges.size() == 0) this->edges.push_back(&(*rit)); //if it's first
    else {
      uint32_t maxLen = -1;
      for(Element* el: this->edges) {
        do {
          el = el->getParent();
          if(el == el->getParent()) break;
        } while(rit->getValue() < el->getValue());
        if(el->getBranchLength() > maxLen) {
          rit->setParent(el);
        }
      }
    }
    /*
    * end of Possible cancer
    */

    rit->info();
    std::cout<<std::endl;
  }


  template<typename C> void Tree<C>::writeEdgesIDs() {
    std::cout<<"Edges: "<<std::endl;
    for(Element* x: this->edges) {
      std::cout<<x->getID()<<std::endl;
    }
  }






};



/*
* Currently here 'cause of testing reasons
*/
int main() {
  StructureAnalyze::Tree<int> p;
  /*
  StructureAnalyze::Tree<int> t;
  t.push(4);
  t.push(2);
  t.push(5);
  t.push(100);

  StructureAnalyze::Tree<std::string> ts;
  ts.push("Hi");


  ts.writeEdgesIDs();
  */

  return 0;
}
