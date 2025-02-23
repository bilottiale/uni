require(ggplot2)

set.seed(123)

# Dataset originale
data <- rnorm(20, mean = 10, sd = 1)
data <- c(data, 1000) # Aggiunta l'outlier

# t-test con H0: μ = 0
t_test <- t.test(data, mu = 0)

# Risultati
print(t_test)

set.seed(123)

# Funzione per simulare il t-test
simulate_t_test <- function(outlier = FALSE, n_sim = 1000, n = 20) {
  results <- data.frame(t_value = numeric(n_sim), p_value = numeric(n_sim))
  
  for (i in 1:n_sim) {
    data <- rnorm(n, mean = 10, sd = 1)
    if (outlier) data[n] <- 1000  # Aggiunta outlier
    t_test <- t.test(data, mu = 0)
    results$t_value[i] <- t_test$statistic
    results$p_value[i] <- t_test$p.value
  }
  
  return(results)
}

# Simulazioni
results_no_outlier <- simulate_t_test(outlier = FALSE)
results_no_outlier
results_with_outlier <- simulate_t_test(outlier = TRUE)

# Confronto dei risultati
par(mfrow = c(2, 2))


# Distribuzione dei t-value
hist(results_no_outlier$t_value, breaks = 30, col = "lightblue", main = "Senza Outlier", xlab = "t-value", ylab = "Frequenza")
hist(results_with_outlier$t_value, breaks = 30, col = "pink", main = "Con Outlier", xlab = "t-value", ylab = "Frequenza")

# Distribuzione dei p-value
hist(results_no_outlier$p_value, breaks = 30, col = "lightblue", main = "Senza Outlier", xlab = "p-value", ylab = "Frequenza")
hist(results_with_outlier$p_value, breaks = 30, col = "pink", main = "Con Outlier", xlab = "p-value", ylab = "Frequenza")
