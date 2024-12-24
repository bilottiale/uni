# Number of simulations
n_sim <- 100000

# Generate samples of size 5 from the uniform distribution
samples <- replicate(n_sim, sort(runif(5)))

# Calculate the mean of the k-th smallest values (k = 1 to 5)
expected_values <- colMeans(samples)

# Theoretical expected values
theoretical_values <- 1:5 / 6

# Print results
results <- data.frame(
  k = 1:5,
  Simulated_Mean = expected_values,
  Theoretical_Mean = theoretical_values
)
print(results)

# Plot results for visualization
library(ggplot2)
ggplot(results, aes(x = k)) +
  geom_point(aes(y = Simulated_Mean, color = "Simulated")) +
  geom_point(aes(y = Theoretical_Mean, color = "Theoretical")) +
  labs(
    title = "Expected Values of k-th Smallest Values",
    x = "k",
    y = "Expected Value",
    color = "Type"
  ) +
  theme_minimal()