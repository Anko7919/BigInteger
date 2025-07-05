#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace dorayaki {
    class BigInteger {
    private: 
        std::vector<std::uint64_t> digits; ///< 値を格納する. 最大値は`dorayaki::BigInteger::digit_max - 1`. 
        std::int8_t sign; ///< 符号を格納する. 符号はsignの符号と一致する. (`sign` is -1, 0, or 1.)

    public: 
        static const std::uint64_t digit_max{ static_cast<std::uint64_t>(std::pow(10, std::floor(std::log10(std::numeric_limits<std::uint64_t>::max())))) }; 

        BigInteger() noexcept : digits{ 0 }, sign{ 0 } {}

        BigInteger(std::int64_t num) noexcept : digits{ std::abs(num) }, sign{ (num == 0) ? (0) : ((num < 0) ? (-1) : (1)) } {
            if (num > digit_max - 1) {
                this->digits.push_back(num / digit_max); 
                this->digits[0] %= digit_max; 
            }
        }

        BigInteger(const std::string str)
    }; 
}

