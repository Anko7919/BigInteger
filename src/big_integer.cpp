#include "big_integer.hpp"

namespace dorayaki {

const std::uint64_t BigInteger::digit_max{ static_cast<std::uint64_t>(std::pow(10, std::floor(std::log10(std::numeric_limits<std::uint64_t>::max())))) }; 
    
BigInteger::BigInteger(const std::string &str) {
    std::string s{ str }; 
    if (s.empty()) {
        this->digits.push_back(0); 
        this->is_negative = false;  
        return; 
    }
    // 先頭の符号を処理
    else if (s.at(0) == '+') {
        this->is_negative = false;  
        s.erase(s.begin()); 
    }
    else if (s.at(0) == '-') {
        this->is_negative = true;  
        s.erase(s.begin()); 
    }
    
    std::size_t l{ str.size() }; // strの残り桁数
    const std::size_t d{ static_cast<std::size_t>(std::log10(digit_max)) }; // digit_maxの桁数
    auto it{ str.cbegin() }; // 現在の位置
    while (l != 0) {
        if (l < d) {
            this->digits.push_back(std::stol(std::string(it, str.cend()))); 
            return; 
        }
        else {
            this->digits.push_back(std::stol(std::string(it, it + d))); 
            it += d; 
            l -= d; 
        }
    }
}

}

