# Step 1: Plot the PDF of a Cauchy distribution
x <- seq(-20, 20, length.out = 1000)
pdf <- dt(x, df = 1) # Cauchy distribution (t-distribution with df = 1)

plot(x, pdf, type = "l", col = "blue", lwd = 2,
     main = "PDF della distribuzione di Cauchy con 1 grado di libertà",
     xlab = "x", ylab = "Densità")
grid()

# Step 2: Simulate sample means for different sample sizes
set.seed(123) # For reproducibility
N_values <- c(100, 1000, 10000)

# Calculate sample means for each N
sample_means <- sapply(N_values, function(N) mean(rt(N, df = 1)))
cat("Sample mean for N=100:", sample_means[1], "\n")
cat("Sample mean for N=1000:", sample_means[2], "\n")
cat("Sample mean for N=10000:", sample_means[3], "\n")

# Step 3: Estimate the PDF of the sample mean (X-bar) using histograms
par(mfrow = c(1, 3)) # Set up a 3-panel layout
for (N in N_values) {
  X_bar <- replicate(1000, mean(rt(N, df = 1))) # Simulate sample means
  hist(X_bar, breaks = c(-Inf, -20:20, Inf), freq = FALSE,
       xlim = c(-20, 20), col = "gray",
       main = paste("Istogramma con N =", N),
       xlab = "Media")
  
  # Add the theoretical Cauchy curve
  curve(dt(x, df = 1), col = "red", lwd = 2, add = TRUE)
}
par(mfrow = c(1, 1)) # Reset layout

# Step 4: Does the CLT hold?
cat("Does the CLT hold for this distribution? NO.\n")
cat("The sample mean does not converge because the Cauchy distribution\n")
cat("has no finite mean or variance.\n")

# ----------------------------------------------

# Plot the PDF of a Cauchy distribution with 1 degree of freedom
x <- seq(-20, 20, by = 0.1)
y <- dt(x, df = 1)
plot(x, y, type = "l", col = "blue", lwd = 2, 
     main = "PDF of Cauchy Distribution (1 degree of freedom)",
     xlab = "x", ylab = "f(x)")

set.seed(123)  # For reproducibility
sample_sizes <- c(100, 1000, 10000)
sample_means <- sapply(sample_sizes, function(N) {
  means <- replicate(1000, mean(rt(N, df = 1)))  # 1000 simulations for each N
  return(means)
})

# Check the results for each sample size
cat("Sample mean for N=100 (first 10):", sample_means[1:10, 1], "\n")
cat("Sample mean for N=1000 (first 10):", sample_means[1:10, 2], "\n")
cat("Sample mean for N=10000 (first 10):", sample_means[1:10, 3], "\n")

par(mfrow = c(1, 3))  # Multiple plots in a row
for (i in 1:length(sample_sizes)) {
  hist(sample_means[, i], breaks = c(-Inf, -20:20, Inf), 
       xlim = c(-20, 20), main = paste("Sample Mean Distribution for N =", sample_sizes[i]),
       xlab = "Sample Mean", col = "lightblue", border = "blue", probability = TRUE)
  curve(dt(x, df = 1), add = TRUE, col = "red", lwd = 2)  # Add the Cauchy pdf
}

