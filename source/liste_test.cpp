#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "List.hpp"

TEST_CASE("constr and getter")
{
    SECTION("isEmpty")
    {
        List<int> liste;
        REQUIRE(liste.empty());
        REQUIRE(liste.size()==0);
    }

    SECTION("push_font")
    {
        List<int> liste;
        liste.push_front(42);
        REQUIRE(42 == liste.front());
        REQUIRE(liste.size() == 1);
    }

    SECTION("push_back")
    {
        List<int> liste;
        liste.push_front(42);
        liste.push_back(66);
        REQUIRE(42 == liste.front());
        REQUIRE(liste.size() == 2);
    }

    


};




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}