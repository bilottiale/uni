# for replicability
set.seed(3)

# Simulate the Deathrolling game for a large number of iterations
deathroll_sim <- function(num_simulations = 10000) {
  wins_player1 <- 0
  total_rolls <- numeric(num_simulations)
  
  for (i in 1:num_simulations) {
    rolls <- 0
    x1 <- 1000  # Initial sides for player 1
    player <- 1  # Start with player 1
    
    while (TRUE) {
      rolls <- rolls + 1
      # Simulate the roll
      if (runif(1) < 1 / x1) {  # Player rolls a 1 and loses
        if (player == 1) {
          break  # Player 1 loses
        } else {
          wins_player1 <- wins_player1 + 1  # Player 1 wins
          break
        }
      }
      
      # If no 1 is rolled, switch to the other player and update sides
      if (player == 1) {
        player <- 2
        x1 <- sample(1:1000, 1)  # New die for player 2
      } else {
        player <- 1
        x1 <- sample(1:1000, 1)  # New die for player 1
      }
    }
    
    total_rolls[i] <- rolls
  }
  
  # Return the results: Probability of player 1 winning, average rolls, and PMF
  list(
    prob_player1_wins = wins_player1 / num_simulations,
    avg_rolls = mean(total_rolls),
    pmf_rolls = table(total_rolls) / num_simulations
  )
}

# Run the simulation
result <- deathroll_sim(num_simulations = 10000)

# Display the results
cat("Probability Player 1 wins: ", result$prob_player1_wins, "\n")
cat("Average total rolls: ", result$avg_rolls, "\n")
cat("PMF of total rolls: \n")
print(result$pmf_rolls)

# Plot the PMF of total rolls

barplot(result$pmf_rolls, xlab = "Total rolls", ylab = "Probability", main = "PMF of total rolls")