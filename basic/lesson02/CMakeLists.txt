cmake_minimum_required(VERSION 3.5)

find_package(GTest)
find_package(Threads)

# Test Partition
add_executable(PartitionTest
  Partition_test.cc)

target_link_libraries(PartitionTest
  PRIVATE
  GTest::GTest
  GTest::Main
  Threads::Threads)


# Test Partition
add_executable(QuickSortTest
  QuickSort_test.cc)

target_link_libraries(QuickSortTest
  PRIVATE
  GTest::GTest
  GTest::Main
  Threads::Threads)
