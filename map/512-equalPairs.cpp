#include<vector>
#include<iostream>
#include<map>
#include<tuple>


#include<iostream>
#include<algorithm>
#include<list>
// #include<vector>

template<typename T>
class Zip
{
    
public:    
    using container_t=std::vector<T>;
    template<typename... Args>   //Q1: what's typename... Args means?
    Zip(const T& head, const Args&... args)
    : items_(head.size()),min_(head.size())
    {
        zip_(head, args...);
    }
    
    inline operator container_t() const
    {
        return items_;
    }
    
    inline container_t operator()() const
    {
        return items_;
    }
    
private:
        /*! Holds the items for iterating. */
    container_t items_;
    /*! The minimum number of values held by all items */
    std::size_t min_;

    template<typename... Args>
    void zip_(const T& head, const Args&... tail)
    {
        // If the current item's size is less than
        // the one stored in min_, reset the min_
        // variable to the item's size
        if (head.size() < min_) min_ = head.size();
        
        for (std::size_t i = 0; i < min_; ++i)
        {
            // Use begin iterator and advance it instead
            // of using the subscript operator adds support
            // for lists. std::advance has constant complexity
            // for STL containers whose iterators are
            // RandomAccessIterators (e.g. vector or deque)
            typename T::const_iterator itr = head.begin();
            
            std::advance(itr, i);
            
            items_[i].push_back(*itr);
        }
        
        // Recursive call to zip_(T, Args...)
        // while the expansion of tail... is not empty
        // else calls the overload with no parameters
        return zip_(tail...);
    }

    inline void zip_()
    {
        // If min_ has shrunk since the
        // constructor call
        items_.resize(min_);
    }


    
};

template<typename T, typename... Args>
typename Zip<T>::container_t zip(const T& head, const Args&... tail)
{
    return Zip<T>(head, tail...);
}
using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using TUPLE=std::tuple<int,int,int>;
using MAP=std::map<TUPLE,int>;




int evalPairs(const MATRIX& m)
{
    MAP d{};
    for(auto &p:m)
    {
        TUPLE tmp=std::make_tuple(p);
        d[tmp]+=1;
    }

    int n=m.size();
    MATRIX M{};
    for(int i=0;i<n;++i)
    {}
}