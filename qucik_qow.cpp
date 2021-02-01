#include<iostream>
#include<stdlib.h>

template <size_t a,size_t f,size_t n,size_t mod>
constexpr size_t pow_ = a * pow_<a*a%mod,(n/2)&1,n/2,mod>%mod;

template<size_t a,size_t n,size_t mod>
constexpr size_t pow_<a,0,n,mod> = pow_<a*a%mod,(n/2)&1,n/2,mod>;
template<size_t a,size_t mod>
constexpr size_t pow_<a,0,0,mod> = 1;

template<size_t a,size_t n,size_t mod>
constexpr size_t Pow = pow_<a,n & 1,n,mod>;


int main(){
	size_t x = Pow<2,8,(size_t)1e9+7>;
	std::cout<<x<<std::endl;
	return 0;
}