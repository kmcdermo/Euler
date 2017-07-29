void quick()
{
  const int N = 100;
  int sum_of_squares = 0;
  int square_of_sum  = 0;

  for (int i = 1; i <= N; i++)
  {
    sum_of_squares += i*i;
    square_of_sum += i;
  }
  square_of_sum *= square_of_sum;

  std::cout << square_of_sum-sum_of_squares << std::endl;
}
