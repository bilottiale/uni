# a. 
h1 <- function(x) {
  ifelse(x >= 0 & x <= 2, 1, ifelse(x >= 2 & x <= 3, -1, 0))
}

# Plot 1
curve(h1(x), from = -1, to = 4, ylab = "h(x)", main = "Funzione 1")
integrate(function(x) h1(x), -Inf, Inf) # Neither a PDF nor a CDF

# b.
h2 <- function(x) {
  sin(x) + 1
}

# Plot 2
curve(h2(x), from = 0, to = 10, ylab = "h(x)", main = "Funzione 4")
# integrate(function(x) h2(x), -Inf, Inf)
# It oscillates, it does not integrate, it is not a PDF or CDF

# c.
h3 <- function(x) {
  ifelse(x >= 0, 1 - exp(-x^2), 0)
}

# Plot 3
curve(h3(x), from = 0, to = 5, ylab = "h(x)", main = "Funzione 3")
# integrate(function(x) h3(x), 0, Inf)
# It does not integrate to 1, it is a valid CDF

# d.
h4 <- function(x) {
  ifelse(x >= 0, 2 * x * exp(-x^2), 0)
}

# Plot 4
curve(h4(x), from = 0, to = 5, ylab = "h(x)", main = "Funzione 4")
integrate(function(x) h4(x), 0, Inf) # It integrates to 1, it is a valid PDF

