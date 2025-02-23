# Step 1: Create the dataset with a normal distribution and an outlier
set.seed(1)  # Set seed for reproducibility

# Generate 19 random values from a normal distribution with mean = 10, sd = 1
data <- c(rnorm(19, mean = 10, sd = 1), 1000)  # Replace the 20th value with 1000 as the outlier

# View the generated data
print("Generated data:")
head(data)

# Step 2: Perform the t-test with H0: μ = 0
t_test_result <- t.test(data, mu = 0)

# View t-test result
print("T-test result:")
print(t_test_result)

# Step 3: Analyze the behavior of the t-test with large outliers (Mathematical Explanation)

# Define a function to simulate the mean as the outlier increases
simulate_mean <- function(n) {
  data <- c(rnorm(n - 1, mean = 10, sd = 1), 1000)  # n-1 normal values, one outlier 1000
  mean(data)
}

# Simulate for different n values and plot the mean
n_values <- 2:50  # Values for n (sample size)
means <- sapply(n_values, simulate_mean)  # Simulate mean for each n

# Plot the sample mean vs n
plot(n_values, means, type = "b", main = "Sample Mean vs n", 
     xlab = "n", ylab = "Sample Mean", col = "blue")

# Step 4: Simulate the sample variance behavior
simulate_variance <- function(n) {
  data <- c(rnorm(n - 1, mean = 10, sd = 1), 1000)  # n-1 normal values, one outlier 1000
  var(data)
}

# Simulate for different n values and plot the variance
variances <- sapply(n_values, simulate_variance)  # Simulate variance for each n

# Plot the sample variance vs n
plot(n_values, variances, type = "b", main = "Sample Variance vs n", 
     xlab = "n", ylab = "Sample Variance", col = "red")

# Step 5: Simulate the t-statistic behavior
simulate_t_statistic <- function(n) {
  data <- c(rnorm(n - 1, mean = 10, sd = 1), 1000)  # n-1 normal values, one outlier 1000
  t_test <- t.test(data, mu = 0)
  t_test$statistic  # Return the t-statistic value
}

# Simulate for different n values and plot the t-statistic
t_statistics <- sapply(n_values, simulate_t_statistic)  # Simulate t-statistic for each n

# Plot the t-statistic vs n
plot(n_values, t_statistics, type = "b", main = "t-statistic vs n", 
     xlab = "n", ylab = "t-statistic", col = "darkgreen")

# Step 6: Conclusion from R output

# Interpretation of results:
# As n increases, the t-statistic tends to approach 1, indicating that the t-test becomes less sensitive to the outlier.
# The sample mean and variance are dominated by the outlier, and the t-statistic stabilizes around 1 as the sample size grows.
