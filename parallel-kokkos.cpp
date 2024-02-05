#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  Kokkos::View<int*> check(n);
	  Kokkos::parallel_for (“iterator”, n, KOKKOS_LAMBDA(const int& i){
	      check(i) = i*i;
	    });
	  struct Foo{
	    void operator(const double& i, double& lsum){
	      lsum+=i;
	    }	};
	  Foo functor;
	  double result;
	  Kokkos::parallel_reduce (n, functor, result);
	  std::cout << "Result: " << result << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
