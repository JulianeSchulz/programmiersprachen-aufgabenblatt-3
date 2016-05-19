#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"

template <typename T>
void swap(T& x , T& y)
	{
		 T temp = x;
 		 x = y;
 		 y = temp;
  		
  	}


TEST_CASE("describe_object_swap","[describe_object_swap]"){

	Circle testi1{{1.0f,1.0f}, 2.0f, {1.0f}};
	Circle testi2{{2.0f,2.0f}, 4.0f, {1.0f}};

	swap(testi1, testi2);

	REQUIRE(testi1.radius() == 4.0f);
	REQUIRE(testi2.radius() == 2.0f);	
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
