# Define the probability function for a match
p <- seq(0, 1, length.out = 100)
P_match <- 2 * p^2 - 2 * p + 1

# Set up the PNG export
pdf("Desktop/uni/Secondo Anno/Statistica/esercizi/2/probability_match_vs_p.pdf")


# Plot the graph
plot(p, P_match, type = "l", col = "blue", lwd = 2,
     main = "Probability of a Match vs. p",
     xlab = "p (Probability of convex side up)", ylab = "P(matching)",
     ylim = c(0, 1))
legend("topright", legend = c("P(matching) = 2p² - 2p + 1"),
       col = c("blue"), lty = c(1, 2), bty = "n", lwd = 2)

# Close the PNG device
dev.off()

getwd()
