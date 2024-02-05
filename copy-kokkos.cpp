#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  Kokkos::View<int*> A("A", 8);
	  // fill View
	  for(int i = 0; i<A.extent(0); i++)
	    {
	      // accessor method uses parentheses
	      A(i) = i*i;
	    }
	  // View that points to original
	  Kokkos::View<int*> B = A;
	  B(2) = 4; // A(2) == 4
	  std::cout << "A(4) is " << A(2) << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
