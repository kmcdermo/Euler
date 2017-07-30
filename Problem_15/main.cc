#include "common.hh"

static const long N = 20;

int main() 
{
  long grid[N+1][N+1];

  for (long i = 0; i < N; i++)
  {
    grid[i][N] = 1;
    grid[N][i] = 1;
  }

  for (long i = N-1; i >= 0; i--)
  {
    for (long j = N-1; j >= 0; j--)
    {
      grid[i][j] = grid[i+1][j]+grid[i][j+1];
    }
  }

  std::cout << grid[0][0] << std::endl;
}
