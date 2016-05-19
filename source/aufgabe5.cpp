#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
bool is_even(unsigned int i);
bool is_odd(unsigned int i);


bool is_odd(unsigned int i){
	return ((i%2) == 1);
}

bool is_even(unsigned int i){
	return ((i%2) == 0);
}


TEST_CASE("describe_factorial", "[aufgabe3]" )
{
	std::vector<unsigned int> vec(100); //Vector mit Zufallszahlen
	for (std::vector <unsigned int>::iterator it = vec.begin(); it != vec.end(); ++it){
	*it = std::rand() % 100+1;
	}
	std::cout << "Vector mit odd Numbers" << "\n";
	std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<unsigned int> (std::cout, " \n"));

	std::vector<unsigned int> evenvec(vec.size()); // Vector kopieren um ungerade Zahlen zu entfernen
	std::copy (std::begin(vec), std::end(vec), std::begin(evenvec));

	evenvec.erase(std::remove_if(evenvec.begin(), evenvec.end(), is_odd), evenvec.end()); //Entfernen von odd zahlen

    std::cout << "\n";
    std::cout << "Vector ohne odd Numbers" << "\n";

    std::copy(std::begin(evenvec), std::end(evenvec), std::ostream_iterator<unsigned int> (std::cout, " \n"));


	REQUIRE(std::all_of(evenvec.begin(), evenvec.end(), is_even));
}


int main(int argc, char* argv[])
{

	return Catch::Session().run(argc, argv);
}