#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace dorayaki {
    class BigInteger {
    private: 
        std::vector<std::uint64_t> digits; ///< 値を格納する. 最大値は`dorayaki::BigInteger::digit_max - 1`. 
        bool is_negative; ///< 符号を格納する. 

    public: 
        static const std::uint64_t digit_max; 

        BigInteger() noexcept : digits{ 0 }, is_negative{ false } {}

        BigInteger(std::int64_t num) noexcept : digits{ static_cast<std::uint64_t>(std::abs(num)) }, is_negative{ num < 0 } {
            if (static_cast<std::uint64_t>(std::abs(num)) > digit_max - 1) {
                this->digits.push_back(num / digit_max); 
                this->digits[0] %= digit_max; 
            }
        }

        BigInteger(const std::string &str); 
    }; 
}

