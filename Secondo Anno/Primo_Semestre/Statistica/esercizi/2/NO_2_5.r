## Title: M&M's proportions
## Author: Alessandro Bilotti

# Define the probability for each color
proportions <- c(Yellow = 0.14, Red = 0.13, Orange = 0.20, Brown = 0.12, Green = 0.20, Blue = 0.21)

# a. Probability of not green
p_not_green <- 1 - proportions["Green"]
p_not_green

# b. Probability of red, orange, or yellow
p_red_orange_yellow <- proportions["Red"] + proportions["Orange"] + proportions["Yellow"]
p_red_orange_yellow

# c. 4 M&M's contain at least one blue
# Set the seed for reproducibility
set.seed(1)
n_sim <- 10000  # Number of simulations
sample_size <- 4  # Number of M&Ms drawn

# Simulations
contains_blue <- replicate(n_sim, {
  sample_colors <- sample(names(proportions), size = sample_size, replace = TRUE, prob = proportions)
  "Blue" %in% sample_colors
})

p_contains_blue <- mean(contains_blue)
p_contains_blue

# d. 6 M&M's contain at least 6 colors
sample_size <- 6  # Number of M&Ms drawn

# Simulations
contains_all_colors <- replicate(n_sim, {
  sample_colors <- sample(names(proportions), size = sample_size, replace = TRUE, prob = proportions)
  length(unique(sample_colors)) == length(proportions) # Check if 6 colors (length(proportions) = 6) are present
})

p_contains_all_colors <- mean(contains_all_colors)
p_contains_all_colors
