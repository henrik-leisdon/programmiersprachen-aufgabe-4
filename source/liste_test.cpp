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
};
TEST_CASE("mod methods"){
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
        REQUIRE(43 == *liste.last());
    }

        SECTION("copy constr 1")
        {
            List<int> list1;
            list1.push_front(1);
            list1.push_front(2);
            list1.push_front(3);
            list1.push_front(4);
            List<int> list2{list1};
            REQUIRE(list2 == list1);
        }

        SECTION("copy consrt 2")
        {
            List<int> list1;
            list1.push_front(1);
            list1.push_front(2);
            list1.push_front(3);
            list1.push_front(4);
        
            List<int> list2;
            list2.push_front(5);
            list2.push_front(6);
            list2 = list1;

            REQUIRE(4 == list2.front());
            REQUIRE(1 == list2.back());
        }

        SECTION("== op test 2")
        {
           List<int> list1;
            List<int> list2;
            list1.push_front(12);
            list2.push_front(12);
            REQUIRE(list1 == list2);
        }

       /* SECTION("== op test")
        {
            List<int> list1;
            List<int> list2;
            list1.push_front(12);
            list2.push_front(13);
            REQUIRE(list1 == list2);
        }*/



    SECTION("reverse")
    {
        List<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);
        list.reverse();
        REQUIRE(1 == list.front());    
    }

    SECTION("vector")
    {
        List<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);
        std::vector<int> vector(4);
        std::copy(list.begin(),list.end(),vector.begin());
        REQUIRE(4 == vector.front());
        REQUIRE(1 == vector.back());
    }

    SECTION("move constr")
    {
        List<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);
        List<int> list2 = std::move(list);
        REQUIRE(0==list.size());
        REQUIRE(list.empty());
        REQUIRE(4==list2.size());
    }
    
};




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}