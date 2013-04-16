#include <cstdint>

namespace std 
{
namespace net 
{
  uint32_t htonl(uint32_t host32);
  uint16_t htons(uint16_t host16);
  
  uint32_t ntohl(uint32_t net32);  
  uint16_t ntohs(uint16_t net16);
  
  // kkloepper: Remove '= delete' to allow types of unsigned to compile.
  template<typename T>
    constexpr T hton(T host) noexcept = delete;

  // XXX only when host is little endian
  template<>
    constexpr uint16_t hton(uint16_t host) noexcept
    { return __builtin_bswap16(host); }

  template<>
    constexpr uint32_t hton(uint32_t host) noexcept
    { return __builtin_bswap32(host); }

  template<>
    constexpr uint64_t hton(uint64_t host) noexcept
    { return __builtin_bswap64(host); }


  template<typename T>
    constexpr T ntoh(T net);

  template<>
  constexpr uint32_t ntoh(uint32_t host) = delete;

} // namespace net
} // namespace std


int main()
{

  // uint32_t OK.
  //typedef std::uint32_t int_type;
  // unsigned does not compile with '= delete'.
  typedef unsigned int_type;
  constexpr int_type b(4444444);
  constexpr int_type bswap(std::net::hton(b));
  static_assert(b != bswap, "byte swap didn't work");

  return 0;
}
