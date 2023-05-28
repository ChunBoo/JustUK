class ZeroEvenOdd {
private:
    int n;
    mutex m0,m1,m2;
    int cnt;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m1.lock();
        m2.lock();
        cnt=0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;++i)
        {
        
        m0.lock();
        printNumber(0);
        if(i&1)
            m2.unlock();
        else
            m1.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2)
        {
        m2.lock();
        printNumber(i);
        m0.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
                for(int i=1;i<=n;i+=2)
        {
            m1.lock();
        printNumber(i);
        m0.unlock();
        }
    }
};