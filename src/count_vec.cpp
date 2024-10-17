#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector count_occurrences(NumericVector vec) {
  std::map<double, int> counts;
  
  // Continue while vec has elements
  while (vec.size() > 0) {
    double check = vec[0];
    
    // Count how many times the first element occurs in vec
    int count = std::count(vec.begin(), vec.end(), check);
    
    // Store the count in the map
    counts[check] = count;
    
    // Remove all elements equal to check from vec
    vec.erase(std::remove(vec.begin(), vec.end(), check), vec.end());
  }
  
  // Convert the map to an R integer vector with names
  IntegerVector result(counts.size());
  CharacterVector names(counts.size());
  
  int index = 0;
  for (auto& pair : counts) {
    result[index] = pair.second;
    names[index] = std::to_string(pair.first);
    index++;
  }
  
  result.attr("names") = names;
  
  return result;
}
