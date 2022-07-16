#include <boost/variant.hpp>
#include <map>

using std::map;

struct nmap;
struct nmap: map<std::string, boost::variant<std::string, nmap*>>
{
    typedef boost::variant<std::string, nmap*> Variant;
    typedef map<std::string, Variant> base;

    friend nmap&       as_map(Variant& v)       { return *boost::get<nmap*>(v); }
    friend nmap const& as_map(Variant const& v) { return *boost::get<nmap*>(v); }

    friend std::string&       as_string(Variant& v)       { return boost::get<std::string>(v); }
    friend std::string const& as_string(Variant const& v) { return boost::get<std::string>(v); }
};

int main()
{
    nmap my_map;
    my_map["a"] = "b";
    my_map["c"] =  new nmap;

    as_map(my_map["c"])["d"] = "e";
}