#include "dbng.hpp"
#include "doctest.h"
#include "mysql.hpp"
#include "ormpp_cfg.hpp"

using namespace std::string_literals;
using namespace ormpp;
struct person {
  int id;
  std::string name;
  int age;
};
REFLECTION(person, id, name, age)

template <class T, size_t N> constexpr size_t size(T (&)[N]) { return N; }

TEST_CASE("test") {
  dbng<mysql> mysql;
  REQUIRE(mysql.connect("127.0.0.1", "root", "", "test_ormppdb",
                        /*timeout_seconds=*/5, 3306));
  REQUIRE(mysql.create_datatable<person>());
  CHECK(mysql.insert<person>({1, "2", 3}) == 1);
  auto result = mysql.query<person>();
  REQUIRE(result.size() == 1);
  CHECK(result[0].id == 1);
  CHECK(result[0].name == "2");
  CHECK(result[0].age == 3);
  // #ifndef _WIN32
  //   A
  // #endif
}