set.seed(123)

# Parametri
mu_X <- 0
mu_Y <- 8
sigma_X <- 3
sigma_Y <- 4

# Simulazione
n_sim <- 10000
X <- rnorm(n_sim, mean = mu_X, sd = sigma_X)
Y <- rnorm(n_sim, mean = mu_Y, sd = sigma_Y)

# X + Y
sum_XY <- X + Y
mu_sum_XY <- mu_X + mu_Y
sigma_sum_XY <- sqrt(sigma_X^2 + sigma_Y^2)

# 5X - Y/2
comb_XY <- 5 * X - (Y / 2)
mu_comb_XY <- 5 * mu_X - mu_Y / 2
sigma_comb_XY <- sqrt(25 * sigma_X^2 + (1 / 4) * sigma_Y^2)

# Grafici
library(ggplot2)

# X + Y
ggplot(data = data.frame(Value = sum_XY), aes(x = Value)) +
  geom_histogram(aes(y = ..density..), bins = 50, fill = "lightblue", color = "black", alpha = 0.7) +
  stat_function(fun = dnorm, args = list(mean = mu_sum_XY, sd = sigma_sum_XY), 
                color = "red", size = 1) +
  labs(
    title = "Distribuzione di X + Y e densità",
    x = "X + Y",
    y = "Densità"
  ) +
  theme_minimal()

# 5X - Y/2
ggplot(data = data.frame(Value = comb_XY), aes(x = Value)) +
  geom_histogram(aes(y = ..density..), bins = 50, fill = "lightblue", color = "black", alpha = 0.7) +
  stat_function(fun = dnorm, args = list(mean = mu_comb_XY, sd = sigma_comb_XY), 
                color = "blue", size = 1) +
  labs(
    title = "Distribuzione di 5X - Y/2 e densità",
    x = "5X - Y/2",
    y = "Densità"
  ) +
  theme_minimal()
