# Load required package
library(stringr)

simulate_tosses <- function(pattern) {
  
  count <- 0
  tosses <- c()

  # Repeat until the pattern is found
  repeat {
    count <- count + 1
    tosses <- c(tosses, ifelse(runif(1) < 0.5, "H", "T"))
    
    # Check if the pattern is in the tosses so far
    result <- str_locate(paste(tosses, collapse = ""), pattern)
    
    # Only exit the loop if the pattern is found (result is not NA)
    if (!is.na(result[1])) {
      break
    }
  }
  
  return(count)
}

# Patterns
patterns <- c("HTH", "HHT", "TTTT", "THHH")

n_simulations <- 1000

# Simulation
results <- sapply(patterns, function(pattern) {
  mean(replicate(n_simulations, simulate_tosses(pattern)))
})

names(results) <- patterns
print(results)