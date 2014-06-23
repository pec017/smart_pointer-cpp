#include "ucpointer.h"
#include "mystringrep.h"

class String {

public:
    String(const char* s): 
        m_rep(NULL) {
        m_rep = new StringRep(s);
    }

    ~String() {}

    String(const String& s): 
        m_rep(s.m_rep) {}

    String& operator=(const String& s) {
        m_rep = s.m_rep;    //smart pointer do work
        return *this;
    }

    bool operator==(const String& s) const {
        return m_rep->equal(*s.m_rep);  //smart pointer
    }

    // String operator+(const String&) const;

    int length() const {
        return m_rep->length();
    }

    // operator const char*() const;

private:
    UCPointer<StringRep> m_rep;

};