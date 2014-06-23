
#include <cstring>
#include "ucobject.h"


class StringRep: public UCObject {

public:
    StringRep(const char* s) {
        if(s){
            int len = strlen(s) + 1;
            m_pChars = new char[len];
            strcpy(m_pChars, s);
        }else{
            m_pChars = new char[1];
            m_pChars[0] = '\0';
        }
    }

    ~StringRep() {
        delete [] m_pChars;
    }

    StringRep(const StringRep& sr) {
        int len = sr.length();
        m_pChars = new char[len + 1];
        strcpy(m_pChars, sr.m_pChars);
    }

    int length() const {
        return strlen(m_pChars);
    }

    int equal(const StringRep& sr) const {
        return (0 == strcmp(m_pChars, sr.m_pChars));
    }

private:
    char* m_pChars;

    // no assignment op
    StringRep& operator=(const StringRep&) {}

};