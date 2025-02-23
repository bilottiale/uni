# Set seed for reproducibility
set.seed(1)

# Number of simulations
n_sim <- 100000

# Define the deck with card values
deck <- c(rep(2:10, each = 4), rep(10, 4 * 3), rep(11, 4))  # Values 2-10, J/Q/K as 10, Ace as 11

# Initialize counters
blackjack_count <- 0
sum_19_count <- 0

# Run the simulations
for (i in 1:n_sim) {
  # Draw two cards
  hand <- sample(deck, 2, replace = FALSE)
  hand_sum <- sum(hand)
  
  # Check for blackjack (Ace + 10)
  if ((11 %in% hand) && (10 %in% hand) && length(hand) == 2) {
    blackjack_count <- blackjack_count + 1
  }
  
  # Check for sum of 19 with Ace as 11
  if (hand_sum == 19) {
    sum_19_count <- sum_19_count + 1
  }
}

# Calculate probabilities
p_blackjack <- blackjack_count / n_sim
p_sum_19 <- sum_19_count / n_sim

# Print the results
cat("Estimated Probability of Blackjack:", p_blackjack, "\n")
cat("Estimated Probability of Sum 19:", p_sum_19, "\n")
