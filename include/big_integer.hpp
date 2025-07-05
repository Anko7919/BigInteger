#include <cstdint>
#include <limits>
#include <vector>

namespace dorayaki {
    class BigInteger {
    private: 
        std::vector<std::uint64_t> digits; ///< 値を格納する. 最大値は`dorayaki::BigInteger::digit_max - 1`. 
        std::int8_t sign; ///< 符号を格納する. 符号はsignの符号と一致する. (`sign` is -1, 0, or 1.)

    public: 
        static const std::uint64_t digit_max{ static_cast<std::uint64_t>(std::pow(10, std::floor(std::log10(std::numeric_limits<std::uint64_t>::max())))) }; 

        BigInteger() noexcept : digits{ 0 }, sign{ 0 } {}
    }; 
}
