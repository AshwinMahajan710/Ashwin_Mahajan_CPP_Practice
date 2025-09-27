
#ifndef HUGEINT_H
#define HUGEINT_H

#include<string>
#include<iostream>

class HugeInt{
    private:
        int no[32] ; // for storing bits of hugeint 
        int bits_len; // index of lowest bit maximum val to traverse no array

    public:

        // constructors --> one for long val and one for string val
        HugeInt(long val);
        HugeInt( const std::string &);
        friend std::ostream& operator<<( std::ostream &, const HugeInt &);
        friend std::istream& operator>>( std::istream &, HugeInt &);
        HugeInt operator+( const HugeInt & ) const;
        HugeInt operator-( const HugeInt & ) const;
        HugeInt operator*( const HugeInt & ) const;
        HugeInt operator/( const HugeInt & ) const;
        bool operator==(const HugeInt & ) const;
};

#endif 