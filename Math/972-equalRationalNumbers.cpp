class Solution {
public:
    bool isRationalEqual(string s, string t) {
      auto convert=[](const string& s){
          auto i=s.find('.');
          auto p=s.find('(');
          string num;
          if(p==string::npos)
          {
              num=s;
          }
          else
          {
              num=s.substr(0,p);
              string r=s.substr(p+1,s.length()-p-2);
              while(num.length()<16)
                num+=r;
          }
          return stod(num);
      };
      return abs(convert(s)-convert(t))<1e-9;
    }
};

class Friction{
    public:
        Friction(long n=0,long d=1){
            long g=__gcd(n,d);
            n_=n/g;
            d_=d/g;
        }
        Friction operator+(const Friction& o) const{
            return Friction(n_*o.d_+d_*o.n_,d_*o.d_);
        }
        bool operator==(const Friction& o)const {
            return this->n_*o.d_==this->d_*o.n_;
        }
    private:
        long n_;
        long d_;
};

class Solution {
public:
    bool isRationalEqual(string s, string t) {
      auto convert=[](string s){
          std::regex re("(\\d+)\\.?(\\d+)?(\\((\\d+)\\))?");
          std::smatch matches;
          std::regex_match(s,matches,re);
          string int_part=matches[1].str();
          string nr_part=matches[2].str();
          string r_part=matches[4].str();

          Friction f(stoi(int_part),1);
          const int base=pow(10,nr_part.length());
          if(nr_part.length())
            f=f+Friction(stoi(nr_part),base);
          if(r_part.length())
            f=f+Friction(stoi(r_part),(pow(10,r_part.length())-1)*base);
        return f;

      };
      return convert(s)==convert(t);
    }
};