#ifndef __PROGTEST__
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <compare>
#include <stdexcept>
#endif /* __PROGTEST__ */

class CBigInt
{
public:
    // default constructor
    CBigInt();
    // copying/assignment/destruction
    // int constructor
    CBigInt(int a);
    // string constructor
    CBigInt(const std::string & input);
    CBigInt(const char* a);
    // operator +, any combination {CBigInt/int/string} + {CBigInt/int/string}
    CBigInt operator+(const CBigInt & a)const;
    // operator *, any combination {CBigInt/int/string} * {CBigInt/int/string}
    CBigInt operator * (const CBigInt &a)const;
    // operator +=, any of {CBigInt/int/string}
    CBigInt & operator+=(const CBigInt &a);

    // operator *=, any of {CBigInt/int/string}
    CBigInt & operator *= (const CBigInt &a);



    // comparison operators, any combination {CBigInt/int/string} {<,<=,>,>=,==,!=} {CBigInt/int/string}
    bool operator < (const CBigInt &a)const;
    bool operator <= (const CBigInt &a)const;
    bool operator > (const CBigInt &a)const;
    bool operator >= (const CBigInt &a)const;
    bool operator == (const CBigInt &a)const;
    bool operator != (const CBigInt &a)const;
    void CleaningNulls();
    // output operator <<
    friend std::ostream  & operator <<(std::ostream& outstr, const CBigInt& a);
    friend std::string anylizeInput(std::string & input);
    // input operator >>
    friend std::istream & operator >>(std::istream & inpstr, CBigInt & a);
    friend CBigInt operator+(int a,const CBigInt &b);
    friend CBigInt operator+(const char* a,const CBigInt &b);
private:
    std::string number;
    std::string number_reversed;
};


CBigInt operator+(int a, const CBigInt &b){
    CBigInt tmp(a);
    return (b+tmp);
}
CBigInt operator+(const char* a,const CBigInt &b){
    CBigInt neww(a);
    return (b+neww);
}

CBigInt operator +(const std::string & a, const CBigInt &b){
    CBigInt tmp(a);
    return (tmp+b);
}


CBigInt operator *(int a,const CBigInt &b){
    CBigInt tmp(a);
    return (tmp*b);
}

CBigInt operator *(const char* a,const CBigInt &b){
    CBigInt tmp(a);
    return (tmp*b);
}

CBigInt operator *(const std::string & a,const CBigInt &b){
    CBigInt tmp(a);
    return (tmp*b);
}


bool operator < (int a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp < b);
}

bool operator < (const char * a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp < b);
}

bool operator < (std::string & a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp < b);
}


bool operator <= (int a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp <= b);
}

bool operator <= (const char * a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp <= b);
}

bool operator <= (std::string & a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp <= b);
}


bool operator > (int a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp > b);
}

bool operator > (const char * a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp > b);
}

bool operator > (std::string & a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp > b);
}

bool operator >= (int a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp >= b);
}

bool operator >= (const char * a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp >= b);
}

bool operator >= (std::string & a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp >= b);
}

/*
bool operator == (int a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp == b);
}

bool operator == (const char * a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp == b);
}

bool operator == (std::string & a , const CBigInt & b ){
    CBigInt tmp(a);
    return (tmp == b);
}*/

std::ostream  & operator <<(std::ostream& outstr, const CBigInt& a){
    outstr<<a.number;
    return outstr;
}


std::string anylizeInput(std::string & input){
    if(input.empty()){
        throw std::invalid_argument("empty string");
    }
    size_t size = input.size();
    std::string result;
    for(size_t i = 0; i< size;i++){
        if(isdigit(input[i])){
            result.push_back(input[i]);
        }
        else if(result.empty() && input[i] == '-'){
            result.push_back(input[i]);
        }
        else if(result.empty() && input[i] == '+' ){
            continue;
        }
        else if(result.empty() && input[i] == ' ' ){
            continue;
        }
        else if(!result.empty()){
            if(result[0]=='-' && input[i] == ' ' ){
                continue;
            }else{
                break;
            }
        }else{
            break;
        }
    }

    if(result.empty()){ throw std::invalid_argument("not a number at all");}
    else if(result.size() == 1 && result[0]=='-'){throw std::invalid_argument("only minus");}
    else if(result == "-0"){result = "0";}

    return result;
}
std::istream & operator >>(std::istream & inpstr, CBigInt & a){
    std::string tmp;
    inpstr>>tmp;
    try{
        std::string tmpin = anylizeInput(tmp);
        CBigInt tmpnum(tmpin);
        a = tmpnum;

    }catch(std::invalid_argument & e ){

        inpstr.setstate(std::ios::failbit);
    }

    return inpstr;
}
CBigInt::CBigInt() {
    number = "0";
    number_reversed="0";
}

CBigInt::CBigInt(const char *a) {
    std:: string tmp = a;
    CBigInt obema(tmp);
    *this = obema;
    CleaningNulls();
    number_reversed = number;
    std::reverse(number_reversed.begin(),number_reversed.end());
}
CBigInt::CBigInt(const std::string & input) {

    if(input.empty()){
        throw std::invalid_argument("empty string");
    }
    size_t size = input.size();
    for(size_t i = 0; i< size;i++){
       if(isdigit(input[i]) || (input[i] =='-' && number.empty() ) || (input[i] =='+' && number.empty() )){
           if(input[i] != '+'){
               number.push_back(input[i]);
           }
       }else{
           throw  std::invalid_argument("non digit");
       }

    }

    if(number.empty()){ throw std::invalid_argument("not a number at all");}
    else if(number.size() == 1 && number[0]=='-'){throw std::invalid_argument("only minus");}
    else if(number == "-0"){number = "0";}
    CleaningNulls();
    number_reversed = number;
    std::reverse(number_reversed.begin(),number_reversed.end());
}
CBigInt::CBigInt(int a) {

    std::ostringstream oss;
    oss << a;
    number = oss.str();
    CleaningNulls();
    number_reversed = oss.str();
    std::reverse(number_reversed.begin(),number_reversed.end());

}

void CBigInt::CleaningNulls(){ /// uluchsit dlya -01

    if(number.size()>1){
        if(number[0]=='-' && number[1]!='0'){
            return;
        }
    }
    else if(number[0]!='0' ){
        return;
    }

    size_t size = number.size();

    std::string tmp;
    size_t i;
    if(number[0]=='-'){tmp.push_back('-');}
    for(i = 0 ;i< size;i++){
        if(number[i] != '0' && number[i]!='-'){
            break;
        }
    }

    for(size_t j = i;j<size;j++){
        tmp.push_back(number[j]);
    }
    if(tmp.empty()){
        number = "0";
    }
    else{
        number = tmp;
    }



}


bool CBigInt::operator<(const CBigInt &a)const {


    if(this->number[0] == '-' && a.number[0] != '-'){return true;}

    else if(this->number[0] != '-' && a.number[0] == '-'){return false;}

    else if(this->number[0] == '-' && a.number[0] == '-'){
        if(this->number.size() > a.number.size()){
            return true;
        }
        else if(this->number.size() < a.number.size()){
            return false;
        }
        else{
            for(size_t i = 1; i< this->number.size();i++){
                if(this->number[i]!=a.number[i]){
                    return this->number[i] > a.number[i];
                }
            }

            return false;
        }
    }

    if(this->number.size() > a.number.size()){
        return false;
    }
    else if(this->number.size() < a.number.size()){
        return true;
    }
    else{
        for(size_t i = 0; i< this->number.size();i++){
            if(this->number[i]!=a.number[i]){
                return this->number[i] < a.number[i];
            }
        }

        return false;
    }


}


bool CBigInt ::operator==(const CBigInt &a)const {
    if((this->number == "0" && a.number =="-0")||(this->number == "-0" && a.number =="0")){return true;}
    return this->number == a.number;
}


bool CBigInt::   operator != (const CBigInt &a)const{
    return !(*this==a);
}


bool CBigInt ::operator<=(const CBigInt &a) const {
    if((*this<a) || (*this==a)){
        return true;
    }
    return false;
}

bool CBigInt::operator >(const CBigInt &a)const{
    return (!(*this<=a));
}


bool CBigInt::operator>=(const CBigInt &a) const {
    return (*this > a || *this==a);
}


std::string SUM(const std::string &a , const std::string &b){


    std::string result ;
    int prenos= 0;

    size_t maxLength = 0;
    if(a.length() < b.size()){
        maxLength = b.size();
    }else{
        maxLength = a.size();
    }

    for (size_t i = 0; i < maxLength || prenos; ++i) {
        int number1 = 0;

        if(i < a.length()){
            number1 = a[i]-48;
        }
        int number2 =  0;

        if(i < b.length() ){
            number2 = b[i]-48;
        }


        int sum = number1 + number2 + prenos;
        prenos = sum / 10;
        sum %= 10;
        result += std::to_string(sum);
    }


    std::reverse(result.begin(), result.end());

    return result;
}

std::string difference(std::string &a, std::string &b){

    bool isNegative = false;
    int carry = 0;
    std::string result;

    CBigInt tmp1(a), tmp2(b);
    if (tmp1<tmp2) {
        std::string tmp = a;
        a=b;
        b=tmp;
        isNegative = true;
    }



    while (b.length() < a.length()) b.push_back('0');
    while (a.size() < b.length()) a.push_back('0');

    size_t size = a.size();
    for (size_t i = 0; i < size; i++) {

        int digit2 = b[i] - 48;
        int digit1 = a[i] - 48;
        digit1 -= carry;
        carry = 0;

        if (digit1 < digit2) {
            digit1 += 10;
            carry = 1;
        }

        result += (char)((digit1 - digit2) + 48);
    }


    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    if (isNegative) result = "-" + result;
    return result;
}


CBigInt & CBigInt::operator+=(const CBigInt &a) {


    if(this->number[0]=='-' && a.number[0]=='-'){

        std::string thiscpy(this->number_reversed.begin(), this->number_reversed.end() - 1);
        std::string acpy (a.number_reversed.begin(), a.number_reversed.end()-1);
        std::string res = '-'+ SUM(thiscpy,acpy);

        this->number = res;
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;
    }else if(this->number[0]!='-' && a.number[0]!='-'){
        std::string res =  SUM(this->number_reversed,a.number_reversed);
        this->number = res;//izm esche reverese
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;

    } else if(this->number[0]!='-' && a.number[0]=='-'){
        std::string thiscpy(this->number_reversed.begin(), this->number_reversed.end());
        std::string acpy (a.number_reversed.begin(), a.number_reversed.end()-1);
        std::string res = difference(thiscpy,acpy);
        this->number = res;
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;


    }else if(this->number[0]=='-' && a.number[0]!='-'){
        std::string thiscpy(this->number_reversed.begin(), this->number_reversed.end() - 1);
        std::string acpy (a.number_reversed.begin(), a.number_reversed.end());
        std::string res = difference(acpy,thiscpy);
        this->number = res;
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;
    }
    return *this;
}

CBigInt CBigInt::operator+(const CBigInt &a) const {
    CBigInt tmp(this->number);
    tmp+=a;
    return tmp;
}


std::string MULT(const std::string & str1, const std::string& str2) {

    if (str1 == "0" || str2 == "0" || str1 == "-0" ||str2 == "-0" )
    {
        return "0";
    }
    std::vector<int> result(str1.size() + str2.size(), 0);
    for (size_t i = 0; i < str1.size(); i++) {
        for (size_t j = 0; j < str2.size(); j++) {
            int um = (str1[i] - 48) * (str2[j] - 48);
            result[i + j] =result[i + j]+ um;
            result[i + j + 1] = result[i + j + 1]+result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    while (result.back() == 0) result.pop_back();
    std::string resultstr;
    for (int i = result.size() - 1; i >= 0; i--) {
        resultstr += (char)(result[i]+48);
    }

    return resultstr;
}
CBigInt & CBigInt::operator*=(const CBigInt &a) {
    if(this->number[0]=='-' && a.number[0]=='-'){

        std::string thiscpy(this->number_reversed.begin(), this->number_reversed.end() - 1);
        std::string acpy (a.number_reversed.begin(), a.number_reversed.end()-1);
        std::string result = MULT(thiscpy, acpy);
        this->number = result;
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;

    }else if(this->number[0]!='-' && a.number[0]!='-'){
        std::string result = MULT(this->number_reversed, a.number_reversed);
        this->number = result;
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;

    } else if(this->number[0]!='-' && a.number[0]=='-'){

        std::string acpy (a.number_reversed.begin(), a.number_reversed.end()-1);
        std::string result = MULT(this->number_reversed, acpy);
        if(result == "0"){
            this->number = result;
        }else{
            this->number = "-"+result;
        }
        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;

    }else if(this->number[0]=='-' && a.number[0]!='-'){
        std::string thiscpy(this->number_reversed.begin(), this->number_reversed.end() - 1);
        std::string result = MULT(thiscpy, a.number_reversed);
        if(result == "0"){
            this->number = result;
        }else{
            this->number = "-"+result;
        }

        this->number_reversed = this->number;
        std::reverse(this->number_reversed.begin(), this->number_reversed.end());
        return *this;

    }
return *this;
}


CBigInt CBigInt::operator * (const CBigInt &a)const{
    CBigInt tmp(this->number);

    tmp*=a;
    return tmp;
}

#ifndef __PROGTEST__
static bool equal ( const CBigInt & x, const char val [] )
{
    std::ostringstream oss;
    oss << x;
    return oss . str () == val;
}
static bool equalHex ( const CBigInt & x, const char val [] )
{
    return true; // hex output is needed for bonus tests only
    // std::ostringstream oss;
    // oss << std::hex << x;
    // return oss . str () == val;
}

bool operator == (const char *a,const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp==b);
}
bool operator == (int a,const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp==b);
}

bool operator == (const std::string  &a,const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp==b);
}

bool operator != (const char *a,const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp!=b);
}
bool operator != (int a, const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp!=b);
}

bool operator != (const std::string  &a, const CBigInt &b ){
    CBigInt tmp(a);
    return (tmp!=b);
}

int main ()
{

    CBigInt a, b;
    std::istringstream is;
    a = 10;
    a += 20;
    assert ( equal ( a, "30" ) );
    a *= 5;

    assert ( equal ( a, "150" ) );
    b = a + 3;
    assert ( equal ( b, "153" ) );
    b = a * 7;
    assert ( equal ( b, "1050" ) );
    assert ( equal ( a, "150" ) );
    assert ( equalHex ( a, "96" ) );

    a = 10;
    a += -20;
    assert ( equal ( a, "-10" ) );
    a *= 5;
    assert ( equal ( a, "-50" ) );
    b = a + 73;
    assert ( equal ( b, "23" ) );
    b = a * -7;
    assert ( equal ( b, "350" ) );
    assert ( equal ( a, "-50" ) );
    assert ( equalHex ( a, "-32" ) );

    a = "12345678901234567890";
    a += "-99999999999999999999";
    assert ( equal ( a, "-87654321098765432109" ) );
    a *= "54321987654321987654";
    assert ( equal ( a, "-4761556948575111126880627366067073182286" ) );
    a *= 0;

    assert ( equal ( a, "0" ) );
    a = 10;
    b = a + "400";
    assert ( equal ( b, "410" ) );
    b = a * "15";
    assert ( equal ( b, "150" ) );
    assert ( equal ( a, "10" ) );
    assert ( equalHex ( a, "a" ) );

    is . clear ();
    is . str ( " 1234" );
    assert ( is >> b );
    assert ( equal ( b, "1234" ) );
    is . clear ();
    is . str ( " 12 34" );
    assert ( is >> b );
    assert ( equal ( b, "12" ) );
    is . clear ();
    is . str ( "999z" );
    assert ( is >> b );
    assert ( equal ( b, "999" ) );
    is . clear ();
    is . str ( "abcd" );
    assert ( ! ( is >> b ) );
    is . clear ();
    is . str ( "- 758" );
    assert ( ! ( is >> b ) );
    a = 42;
    try
    {
        a = "-xyz";
        assert ( "missing an exception" == nullptr );
    }
    catch ( const std::invalid_argument & e )
    {
        assert ( equal ( a, "42" ) );
    }

    a = "73786976294838206464";
    assert ( equal ( a, "73786976294838206464" ) );
    assert ( equalHex ( a, "40000000000000000" ) );
    assert ( a < "1361129467683753853853498429727072845824" );
    assert ( a <= "1361129467683753853853498429727072845824" );
    assert ( ! ( a > "1361129467683753853853498429727072845824" ) );
    assert ( ! ( a >= "1361129467683753853853498429727072845824" ) );
    assert ( ! ( a == "1361129467683753853853498429727072845824" ) );
    assert ( a != "1361129467683753853853498429727072845824" );
    assert ( ! ( a < "73786976294838206464" ) );
    assert ( a <= "73786976294838206464" );
    assert ( ! ( a > "73786976294838206464" ) );
    assert ( a >= "73786976294838206464" );
    assert ( a == "73786976294838206464" );
    assert ( ! ( a != "73786976294838206464" ) );
    assert ( a < "73786976294838206465" );
    assert ( a <= "73786976294838206465" );
    assert ( ! ( a > "73786976294838206465" ) );
    assert ( ! ( a >= "73786976294838206465" ) );
    assert ( ! ( a == "73786976294838206465" ) );
    assert ( a != "73786976294838206465" );
    a = "2147483648";
    assert ( ! ( a < -2147483648 ) );
    assert ( ! ( a <= -2147483648 ) );
    assert ( a > -2147483648 );
    assert ( a >= -2147483648 );
    assert ( ! ( a == -2147483648 ) );
    assert ( a != -2147483648 );
    a = "-12345678";
    assert ( ! ( a < -87654321 ) );
    assert ( ! ( a <= -87654321 ) );
    assert ( a > -87654321 );
    assert ( a >= -87654321 );
    assert ( ! ( a == -87654321 ) );
    assert ( a != -87654321 );







    return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
