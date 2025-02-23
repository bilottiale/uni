library(ggplot2)
library(fosdata)

# 2.5
probabilities <- c(0.14, 0.13, 0.20, 0.12, 0.20, 0.21)
colors <- c("Yellow", "Red", "Orange", "Brown", "Green", "Blue")

num_simulations <- 100000
success_counter <- 0

set.seed(123)
for(i in 1:num_simulations) {
  draw <- sample(colors, size = 6, replace = TRUE, prob = probabilities)
  if(length(unique(draw)) == 6) {
    success_counter <- success_counter + 1
  }
}

prob_all_colors <- success_counter / num_simulations
prob_all_colors

# 2.8
rolls1 <- sample(1:6, num_simulations, replace = TRUE)
rolls2 <- sample(1:6, num_simulations, replace = TRUE)

sum_rolls <- sum(rolls1 + rolls2 == 10)

prob <- sum_rolls / num_simulations
prob

# 2.9
results <- replicate(num_simulations, sum(sample(c(0, 1), 7 , replace = TRUE)))

res_3_heads <- sum(results == 3)

prob <- res_3_heads / num_simulations
prob

# 2.10
results <- replicate(num_simulations, sum(sample(1:6, 7 , replace = TRUE)))

res_15_20 <- sum(results >= 15 & results <= 20)

prob <- res_15_20 / num_simulations
prob

# 2.11
success_counter <- 0

for (i in 1:num_simulations) {
  cumulative_sum <- 0
  
  while (cumulative_sum < 20) {
    cumulative_sum <- cumulative_sum + sample(1:6, 1)
  }
  
  if (cumulative_sum == 20) {
    success_counter <- success_counter + 1
  }
}

prob <- success_counter / num_simulations

cat("Estimated probability that the cumulative sum equals 20:", prob, "\n")

# 2.12: Rolling 2 dice
num_simulations <- 10000

rolls <- replicate(num_simulations, sum(sample(1:6, 2, replace = TRUE)))

outcomes <- table(rolls)

barplot(outcomes, main = "Sum of two dice rolls", xlab = "Sum", ylab = "Frequency", col = "lightblue")

die1 <- c(5, 5, 5, 5, 5, 5)
die2 <- c(2, 2, 2, 6, 6, 6)

rolls <- replicate(num_simulations, sum(sample(die1, 1) + sample(die2, 1)))

outcomes <- table(rolls)

barplot(outcomes, main = "sum of two dice rolls", xlab = "sum", ylab = "frequency", col = "lightblue")

die1 <- c(1, 2, 2, 3, 3, 4)
die2 <- c(1, 3, 4, 5, 6, 8)

rolls <- replicate(num_simulations, sum(sample(die1, 1) + sample(die2, 1)))

outcomes <- table(rolls)

barplot(outcomes, main = "sum of two dice rolls", xlab = "sum", ylab = "frequency", col = "lightblue")

# 2.13
n_people <- 200

prob_no_shared_birthday <- (364 / 365) ^ (n_people - 1)

prob_shared_birthday <- 1 - prob_no_shared_birthday

prob_shared_birthday

# 2.14
n_people <- 100

n_combinations <- 365 * 24

prob_no_shared_birthday_hour <- 1
for(i in 0:(n_people - 1)) {
  prob_no_shared_birthday_hour <- prob_no_shared_birthday_hour * (n_combinations - i) / n_combinations
}

prob_at_least_one_shared_birthday_hour <- 1 - prob_no_shared_birthday_hour

prob_at_least_one_shared_birthday_hour

# 2.15
n_people <- 50

n_days <- 365

success_counter <- 0

for(i in 1:num_simulations) {
  birthdays <- sample(1:n_days, n_people, replace = TRUE)
  
  bday_counter <- table(birthdays)
  
  if(any(bday_counter > 3)) {
    success_counter <- success_counter + 1
  }
}

prob <- success_counter / num_simulations
prob

# 2.16
n_balls <- 100
n_urns <- 20

success_counter <- 0

for (i in 1:num_simulations) {
  urns <- sample(1:n_urns, n_balls, replace = TRUE)
  
  urn_counts <- table(urns)
  
  if (any(urn_counts == 0)) {
    success_counter <- success_counter + 1
  }
}

probability <- success_counter / num_simulations

cat("Estimated probability that at least one urn is empty:", probability, "\n")

# 2.17
deck <- c(rep(2:10, each=4), rep(10, 12), 11)

blackjack_counter <- 0
counter_19 <- 0

for(i in 1:num_simulations) {
  hand <- sample(deck, 2, replace = TRUE)
  
  if(sum(hand) == 21) {
    blackjack_counter <- blackjack_counter + 1
  }
  
  if(sum(hand) == 19) {
    counter_19 <- counter_19 + 1
  }
}

prob <- blackjack_counter / num_simulations
cat("Estimated probability of getting a blackjack:", prob, "\n")

prob <- counter_19 / num_simulations
cat("Estimated probability of getting a 19:", prob, "\n")

# 2.18
fourth_round_count <- 0

for (i in 1:num_simulations) {
  rounds <- 0
  
  x1 <- sample(1:1000, 1)
  
  while (TRUE) {
    rounds <- rounds + 1
    
    x2 <- sample(1:x1, 1)
    
    x3 <- sample(1:x2, 1)
    
    if (x2 == 1 || x3 == 1) {
      break
    }
    
    x1 <- x2
  }
  
  if (rounds == 4) {
    fourth_round_count <- fourth_round_count + 1
  }
}

prob_fourth_round <- fourth_round_count / num_simulations

cat("Estimated probability that the game ends on the 4th round:", prob_fourth_round, "\n")

ggplot(data = data.frame(x = 1:1000), aes(x = x)) +
  stat_function(fun = function(x) 1 / x, color = "red") +
  labs(title = "Probability of ending the game in round x", x = "Round", y = "Probability")

# 2.19
scrabble_tiles <- scrabble
scrabble_tiles

vowels <- c("A", "E", "I", "O", "U")

tiles <- rep(scrabble_tiles$piece, scrabble_tiles$points)
tiles

no_vowels_counter <- 0

for(i in 1:num_simulations) {
  draw <- sample(tiles, 7, replace = FALSE)
  
  if(all(!(draw %in% vowels))) {
    no_vowels_counter <- no_vowels_counter + 1
  }
}

prob <- no_vowels_counter / num_simulations
prob



















