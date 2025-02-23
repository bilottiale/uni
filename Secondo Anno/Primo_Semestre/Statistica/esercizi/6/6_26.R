# Load necessary libraries
library(dplyr)

# Set parameters
n <- 18  # Number of M&M's per bag (number of trials)
p <- 0.94  # Probability of getting a M&M of a certain color
colors <- c("Blue", "Orange", "Green", "Yellow", "Red", "Brown")  # Colors of M&M's
n_bags <- 200  # Number of bags to simulate
num_replicates <- 500  # Number of replicates to estimate the probability

# Function to simulate the distribution of M&M's in one bag
simulate_bag <- function() {
  sample_size <- sapply(1:length(colors), function(i) {
    rbinom(1, n, p)  # Binomial distribution for each color
  })
  return(sample_size)
}

# Create a data frame for one replicate
simulate_bags <- function() {
  # Generate bags by simulating each one
  bags <- t(replicate(n_bags, simulate_bag()))  # Use t() to transpose and ensure correct dimensions
  colnames(bags) <- colors  # Assign color names as column names
  return(as.data.frame(bags))  # Convert to data frame
}

# Run 500 replicates to estimate the probability of distinct distributions
distinct_count <- 0

for (i in 1:num_replicates) {
  bags <- simulate_bags()  # Generate bags for one replicate
  distinct_rows <- nrow(distinct(bags))  # Check how many distinct rows (distributions) are present
  
  # Print a sample of bags if necessary for debugging
  if (i %% 100 == 0) {
    cat("Replicate:", i, "Distinct rows:", distinct_rows, "\n")
  }
  
  if (distinct_rows == n_bags) {
    distinct_count <- distinct_count + 1  # Increment if all distributions are distinct
  }
}

# Calculate the probability that all bags have distinct distributions
distinct_probability <- distinct_count / num_replicates
cat("Estimated probability that all bags have distinct distributions:", distinct_probability, "\n")
