#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

struct matrixIOFixture {
  matrixIOFixture()
  {
    A = Eigen::MatrixXd(3, 3);
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
  }

  Eigen::MatrixXd A;
  int             matrix_size                = 3;
  std::string     valid_matrix_file          = "../data/matrix_valid.csv";
  std::string     invalid_format_matrix_file = "../data/matrix_invalid_format.csv";
  std::string     invalid_cols_matrix_file   = "../data/matrix_invalid_cols.csv";
  std::string     invalid_rows_matrix_file   = "../data/matrix_invalid_rows.csv";
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture)

BOOST_AUTO_TEST_CASE(open_valid_data)
{
  Eigen::MatrixXd read = matrixIO::openData(valid_matrix_file, matrix_size);
  BOOST_TEST(read == A);
}

BOOST_AUTO_TEST_CASE(open_invalid_format_data)
{
  BOOST_REQUIRE_THROW(matrixIO::openData(invalid_format_matrix_file, matrix_size), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(open_invalid_rows_data)
{
  BOOST_REQUIRE_THROW(matrixIO::openData(invalid_rows_matrix_file, matrix_size), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(open_invalid_cols_data)
{
  BOOST_REQUIRE_THROW(matrixIO::openData(invalid_cols_matrix_file, matrix_size), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
