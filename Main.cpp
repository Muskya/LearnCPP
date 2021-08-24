// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <typeinfo> // type_name<decltype(x)>()
// STL Headers
#include <array>
#include <vector>
#include <algorithm>
#include <memory>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"

int main() {
	/*---------------------------------------------------------------*/
	/*	Some practice with allocators, type_traits, before jumping   */
					/*in my own vector implementation*/
	/*---------------------------------------------------------------*/

	int a = 10;
	//	Decltype can be used to declare variables, typeid can't:
	decltype(a) b = 25;								// OK
	//typeid(a).name() b;							// NOT OK

	//	typeid(x).name() returns info about passed entity's type:
	std::cout << typeid(b).name() << std::endl;		// OK
	//std::cout << decltype(a) << std::endl;		// NOT OK

	//	Allocators : 
	std::allocator<std::string> s_all;

	//	allocate() first param 'n' is the number of OBJECTS to allocate
	//	which is n * sizeof(T):
	std::string* str1 = s_all.allocate(2);
	s_all.construct(str1, "Hello boys");
	std::cout << *(str1) << std::endl;		// Output: "Hello boys"
	s_all.construct(str1 + 1, "Hello girls");
	std::cout << *(str1 + 1) << std::endl;	// Output: "Hello girls"
	//	Compilation error: we only allocated 2 * (std::string*):
	//s_all.construct(str1 + 2, "Hello all"); 

	s_all.destroy(str1);		// Destroy entities at their memory location
	s_all.destroy(str1 + 1);	// don't forget the other one(s). Memory is
								// still allocated though.

	//	from here we can still construct <T> from our <T> allocator:
	s_all.construct(str1, "Heyyy I'm back");
	std::cout << *str1 << std::endl;		// Output: "Heyyy I'm back"
	s_all.construct(str1 + 1, "Heyyy I'm back too!");
	std::cout << *(str1 + 1) << std::endl;	// Output: "Heyyy I'm back too!"

	//	To completely destroy an entity, destroy() then deallocate():
	s_all.destroy(str1); s_all.destroy(str1 + 1);
	s_all.deallocate(str1, 2); // Deallocates 2 * sizeof(T)

	std::allocator<int> i_all;
	static_assert(std::is_same_v<int, decltype(i_all)::value_type>,
		"Types are not equivalent");
	int* ints = i_all.allocate(1);
	i_all.construct(ints, 2392);
	std::cout << "Ints value: " << *ints << std::endl;
	ints[1] = 5000;
	std::cout << "Ints value: " << *(ints+1) << std::endl;

	i_all.destroy(ints); i_all.deallocate(ints, 1);

	//	Allocators through std::allocator_traits
	//	(no clue yet why some people use allocators through this 
	//	template and not single std::allocator only)
	std::allocator<int> i_all1;
	int* p; 

	//	std::allocators_traits member functions for allocation/dealloc
	//	construct/destruct require 3 arguments : allocator, ptr, value
	//	instead of only ptr, value for std::allocator

	//using traits_t = std::allocator_traits<decltype(i_all)>;
	typedef std::allocator_traits<decltype(i_all1)> traits_t;
	p = traits_t::allocate(i_all1, 1);
	traits_t::construct(i_all1, p, 1500);
	std::cout << *p << std::endl;	// Output: 1500
	//	Kill entity: (destroy, deallocate)
	traits_t::destroy(i_all, p);
	traits_t::deallocate(i_all, p, 1);
}