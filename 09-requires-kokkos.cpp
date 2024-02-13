#include <Kokkos_Core.hpp>
#include <iostream>

// 
template<typename View_t> requires std::is_same_v<typename View_t::value_type, char>
void foo(View_t& buf){
  std::cout << buf.label() << " Char View works!" << std::endl;
}

// default version works on all Views
template<typename View_t>
void foo(View_t& buf){
  std::cout << buf.label() << " View works!" << std::endl;
  }

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
    	int n = 8;
	int result = 0;
	// what happens if 
	Kokkos::View<char*> check("check", n);
	//Kokkos::View<int*> check("check", n);
	// fill array
	for(int i = 0; i<check.extent(0); i++){
	  check(i) = i*i;
	}
	foo(check);
    	}
    	Kokkos::finalize();
    	return 0;
}
