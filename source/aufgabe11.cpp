#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>


bool is_even(int i);
bool is_odd(int i);


bool is_odd(int i){
	return ((i%2) == 1);
}

bool is_even(int i){
	return ((i%2) == 0);
}

template <typename Container, typename function>
Container filter(Container& contain , function praed)
	{
		contain.erase(std::remove_if(contain.begin(), contain.end(), praed), contain.end());
		return contain;
  		
  	}


TEST_CASE("describe_filter_test","[filter_test]"){

	std::vector<int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<int> alleven = filter(v2, is_odd);

	std::cout << "Elemente von alleven:" << "\n";
	std::copy(std::begin(alleven), std::end(alleven), std::ostream_iterator<unsigned int> (std::cout, " \n"));

	REQUIRE(std::all_of(alleven.begin(), alleven.end(), [](int i){return i%2 == 0;}));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
