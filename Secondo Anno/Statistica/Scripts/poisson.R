#Generate a Poisson-distributed dataset
lambda <- 5  # Average rate of events
poisson_data <- rpois(100, lambda)

# Create a bar plot to visualize the probability mass function
barplot(table(poisson_data)/length(poisson_data), 
        col = "skyblue", 
        main = "Poisson Distribution PMF",
        xlab = "Number of Events",
        ylab = "Probability",
        ylim = c(0, 0.15))

# Add a red line representing the theoretical Poisson PMF
points(0:max(poisson_data), dpois(0:max(poisson_data), lambda), type = "b", col = "red")

# Add legend
legend("topright", legend = c("Empirical PMF", "Theoretical PMF"), 
       fill = c("skyblue", "red"), 
       cex = 0.8)

## Processo di Poisson
#set.seed(123)
lambda <- 5   # Tasso
Tmax <- 10    # Tempo massimo di osservazione
times <- cumsum(rexp(100, rate=lambda)) # Tempi degli arrivi

# Filtriamo gli eventi che rientrano in Tmax
times <- times[times <= Tmax]
counts <- seq_along(times) # Numero cumulativo di eventi

# Grafico del processo
plot(times, counts, type="s", col="blue", lwd=2, xlab="Tempo", ylab="Numero di eventi",
     main="Processo di Poisson")
abline(h=0, col="gray")