#   Smart Pointer of String

*   Templates
*   Inheritance
*   Reference Counting
*   Smart Pointers

### UCObject

*   UCObject holds the count
    *   use-counted object

### UCPointer 

*   UCPointer is a smart pointer to a UCObject
    *   Using a template
    *   Overloads -> and *

##  Relationship

*   String has a UCPointer
*   UCPointer has a StringRep
*   StringRep is a UCObject(inheritance)

##  Critique

*   UCPointer maintains reference counts
*   UCObject hides the details of the count String is very clean
*   StringRep deals only with string storage and manipulation
*   UCObject and UCPointer are reusable
*   Objects with cycles of UCPointer will never be deleted