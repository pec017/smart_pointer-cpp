#include <assert.h>

class UCObject {

public:
    UCObject():
        m_refCount(0) {}

    virtual ~UCObject() {
        assert(0 == m_refCount);
    }

    UCObject(const UCObject&): 
        m_refCount(0) {}

    void incr() {
        m_refCount++;
    }

    void decr() {
        m_refCount--;
        if(0 == m_refCount){
            delete this;
        }
    }

    int references() {
        return m_refCount;
    }

private:
    int m_refCount;

};