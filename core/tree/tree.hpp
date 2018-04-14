#include <list>
#include <vector>
#include <memory>

/*
* Analyzes data
*/
namespace StructureAnalyze {

  template<typename C> class Tree {
    class Element {
      /*
      * Counts elements
      * Increased with every constructor
      */
      static uint32_t ammount;
      /*
      * Objects can be removed or pushed by id
      */
      uint32_t id;
      /*
      * Value of object can be any type
      */
      C value;
      /*
      * Points to the previous element
      */
      Element * parent;

    public:
      /*
      * Creates new element with automatically added id
      * that points to itsel
      */
      Element(C value);
      /*
      * Sets new parent of the element
      */
      void setParent(Element * parent);
      /*
      * Returns pointer to the parent
      *
      */
      Element* getParent();
      /*
      * Gets length of the branch from that point
      */
      uint32_t getBranchLength();
      /*
      * Simply other simple getters
      */
      uint32_t getID();
      C getValue();

      /*
      * Prints info about
      */
      void info();
    };

    /*
    * Handle elements
    */
    std::list<Element> elements;
    Element root;
    /*
    * Handle pointers to edges
    */
    std::vector<Element *> edges;
    /*
    * max value from edges
    */
    Element * maxElement;
    /*
    * Max length of the tree's branch counted from root
    * and pointer to the corresponding edge
    */
    uint32_t maxBranchLength;
    Element * maxBranchLengthElem;
    /*
    * Min length of the tree's branch counted from root
    * and pointer to the corresponding edge
    */
    uint32_t minBranchLength;
    Element * minBranchLengthElem;

  public:
    Tree() {}
    /*
    * Insert new element
    */
    void push(C value);
    /*
    * Removes an element
    */
    void remove(uint32_t id);
    /*
    * Gets edges
    */
    void writeEdgesIDs();
  };
};
