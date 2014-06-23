
template <typename T>
class UCPointer {

public:
    UCPointer(T* r = NULL):
        m_pObj(r) {
            increment();
        }

    ~UCPointer() {
        decrement();
    }

    UCPointer(const UCPointer<T>& p) {
        m_pObj = p.m_pObj;
        increment();
    }

    UCPointer& operator=(const UCPointer<T>& p) {
        if(m_pObj != p.m_pObj){
            decrement();
            m_pObj = p.m_pObj;
            increment();
        }

        return *this;
    }

    T* operator->() const {
        return m_pObj;
    }

    T& operator*() const {
        return *m_pObj;
    }


private:
    T* m_pObj;

    void increment() {
        if(m_pObj){
            m_pObj->incr();
        }
    }

    void decrement() {
        if(m_pObj){
            m_pObj->decr();
        }
    }

};