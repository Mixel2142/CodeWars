/*
https://www.codewars.com/kata/int32-to-ipv4/train/cpp
Take the following IPv4 address: 128.32.10.1
This address has 4 octets where each octet is a single byte (or 8 bits).
1st octet 128 has the binary representation: 10000000
2nd octet 32 has the binary representation: 00100000
3rd octet 10 has the binary representation: 00001010
4th octet 1 has the binary representation: 00000001
So 128.32.10.1 == 10000000.00100000.00001010.00000001
Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 214958336
Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cmath>
#include <bitset>

using namespace std;

string uint32_to_ip(uint32_t ip)
{
string bin = bitset<32>(ip).to_string(); 
ostringstream oss;
oss<<bitset<8>(bin.substr(0,8).c_str()).to_ulong()<<"."<<bitset<8>(bin.substr(8,16).c_str()).to_ulong()<<"."<<bitset<8>(bin.substr(16,24).c_str()).to_ulong()<<"."<<bitset<8>(bin.substr(24,32).c_str()).to_ulong();
return oss.str().c_str();
}

void main(int n1)
{
cout<<uint32_to_ip(n1);
}