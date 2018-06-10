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

    SECTION("pop_front")
    {
        List<int> liste;
        liste.push_front(42);
        liste.push_back(66);
        REQUIRE(42 == liste.front());
        REQUIRE(liste.size() == 2);
        liste.pop_back();
        REQUIRE(liste.size()==1);
        liste.pop_back();
        REQUIRE(liste.empty());
    }

    SECTION("clear")
    {
        List<int> liste;
        liste.push_front(42);
        liste.push_back(66);
        liste.push_back(123);
        liste.clear();
        REQUIRE(liste.empty()); 
    }

    SECTION("sould be an empty range...")
    {
        List<int> liste2;
        auto b = liste2.begin();
        auto e = liste2.end();
        REQUIRE(b == e);
    }

    SECTION("prove access to first element")
    {
        List<int> liste;
        liste.push_front(42);
        REQUIRE(42 == *liste.begin());
    }

        SECTION("prove access to last element")
    {
        List<int> liste;
        liste.push_front(42);
        liste.push_back(43);
        REQUIRE(43 == *liste.end());
    }

};




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}