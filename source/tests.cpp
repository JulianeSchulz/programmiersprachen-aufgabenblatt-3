#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"



TEST_CASE("describe_cirlce_compare_same","[circle_compare_same]")
{
	Circle test1{{1.0f,1.0f}, 4.0f, {1.0f}};
	Circle test2{{2.0f,2.0f}, 4.0f, {1.0f}};

	REQUIRE(test1 == test2);
}

TEST_CASE("describe_cirlce_compare_greater","[circle_compare_greater]")
{
	Circle test1{{1.0f,1.0f}, 10.0f, {1.0f}};
	Circle test2{{2.0f,2.0f}, 4.0f, {1.0f}};

	REQUIRE(test1 > test2);
}

TEST_CASE("describe_cirlce_compare_less","[circle_compare_less]")
{
	Circle test1{{1.0f,1.0f}, 2.0f, {1.0f}};
	Circle test2{{2.0f,2.0f}, 4.0f, {1.0f}};

	REQUIRE(test1 < test2);
}

TEST_CASE("describe_circle_sort","[circle_sort]")
{
	std::list<Circle> Clist;
	for(int i = 0; i< 50; i++){ 
		Clist.push_back(Circle{{0.0, 0.0}, std::rand() % 100 +1.0f, {1.0}});
	}
	Clist.sort();
	REQUIRE(std::is_sorted(Clist.begin(), Clist.end()));

}

TEST_CASE("describe_circle_sort_lambda","[circle_sort_lambda]")
{
	std::vector<Circle> Mlist;
	for(int i = 0; i< 50; i++){ 
		Mlist.push_back(Circle{{0.0, 0.0}, std::rand() % 100 +1.0f, {1.0}});
	}
	auto comp = [](const Circle& lhs, const Circle& rhs){return lhs < rhs;};
	std::sort(Mlist.begin(), Mlist.end(), comp);
	REQUIRE(std::is_sorted(Mlist.begin(), Mlist.end()));

}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
