# Step 1: Plot the PDF of a Cauchy distribution
x <- seq(-20, 20, length.out = 1000)
pdf <- dt(x, df = 1) # Cauchy distribution (t-distribution with df = 1)

plot(x, pdf, type = "l", col = "blue", lwd = 2,
     main = "PDF of the Cauchy Distribution (t with 1 df)",
     xlab = "x", ylab = "Density")
grid()

# Step 2: Simulate sample means for different sample sizes
set.seed(123) # For reproducibility
N_values <- c(100, 1000, 10000)

# Calculate sample means for each N
sample_means <- sapply(N_values, function(N) mean(rt(N, df = 1)))
print(sample_means)

# Step 3: Estimate the PDF of the sample mean (X-bar) using histograms
par(mfrow = c(1, 3)) # Set up a 3-panel layout
for (N in N_values) {
  X_bar <- replicate(1000, mean(rt(N, df = 1))) # Simulate sample means
  hist(X_bar, breaks = c(-Inf, -20:20, Inf), freq = FALSE,
       xlim = c(-20, 20), col = "gray",
       main = paste("Histogram of Sample Mean (N =", N, ")"),
       xlab = "Sample Mean")
  
  # Add the theoretical Cauchy curve
  curve(dt(x, df = 1), col = "red", lwd = 2, add = TRUE)
}
par(mfrow = c(1, 1)) # Reset layout

# Step 4: Does the CLT hold?
cat("Does the CLT hold for this distribution? NO.\n")
cat("The sample mean does not converge because the Cauchy distribution\n")
cat("has no finite mean or variance.\n")
