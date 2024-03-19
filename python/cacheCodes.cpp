#include <functional>
#include <iostream>
#include <unordered_map>

/*
Implementing a caching mechanism similar to Python's `@cache` decorator (from
`functools`) in C++ requires understanding how caching works and then applying
those principles in C++. The Python `@cache` decorator automatically memoizes a
function, storing the results of expensive function calls and returning the
cached result when the same inputs occur again.

- The `FunctionCache` class template takes a function and caches its results.
The cache is a simple `std::unordered_map` that maps arguments to results.
*/
template <typename ReturnType, typename ArgType> class FunctionCache {
public:
  using FunctionType = std::function<ReturnType(ArgType)>;

  FunctionCache(FunctionType func) : func(func) {}

  ReturnType operator()(ArgType arg) {
    // Check if the result is already cached
    auto it = cache.find(arg);
    if (it != cache.end()) {
      return it->second; // Return cached result
    }

    // Otherwise, compute and cache the result
    ReturnType result = func(arg);
    cache[arg] = result;
    return result;
  }

private:
  FunctionType func;
  std::unordered_map<ArgType, ReturnType> cache;
};

// A simple recursive Fibonacci function (inefficient without caching)
int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  // Wrap the fibonacci function with the cache
  FunctionCache<int, int> cachedFibonacci(fibonacci);

  // Now use the cached version
  std::cout << "Fibonacci of 10: " << cachedFibonacci(10) << std::endl;
  std::cout << "Fibonacci of 30: " << cachedFibonacci(30)
            << std::endl; // Much faster than pure recursion

  return 0;
}