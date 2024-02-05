#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  // set the typedef
	  typedef Kokkos::View<double***> View_t;
	  int n,m,l = 8;
	  // subview
	  View_t A("A", n, m, l);
	  auto B = Kokkos::subview(A, 
				   std::make_pair(2, 5), 6, Kokkos::ALL);
	  // unmanaged View
	  char buf[] = {1, 2, 3, 4, 5};
	  Kokkos::View<char*> C(buf, n);
	  // A.data() == buf;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
